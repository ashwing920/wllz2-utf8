// fingerd.c

//pragma optimize
//#pragma save_binary

#include <ansi.h>;
#include <mudlib.h>

private void create() { seteuid( getuid() ); }
int sort_user(object,object);

string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + "m":"") + (day?day + "d":"") +
	(hour?hour + "h":"") + min + "m";
}

int online_time(object body)
{
	return time() - (int)body->query_temp("temp_time");
}
string finger_all()
{
	object *user,*ob;
	string msg,str;
	int i;

	user = filter_array(children(USER_OB),(: userp :));
	ob = sort_array(user,"sort_user");
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i])
			|| !interactive(ob[i])) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				query_idle(ob[i]) + "秒");
		}

	str =  HIY"「"+ code_name() +"」当前使用者列表：\n"+NOR;
	str += "──────────────────\n";
	str += BBLU +HIW "姓名          帐号          发呆    \n"NOR;
	str += "──────────────────\n";
	str += msg;
	str += "──────────────────\n";
	this_player()->start_more(str);
		return "共有"+ chinese_number(sizeof(ob))+"位使用者正在游戏中和等待连线中。\n";
	} else    // wizard finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i])
			|| !interactive(ob[i])) continue;
			msg = sprintf("%s%-14s%-14s%-32s%-8s%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				CHINESE_D->chinese_time( (int)ob[i]->query("mud_age")),
				query_idle(ob[i]) + "秒", query_ip_number(ob[i]));
		}
		str =  HIY"「"+ code_name() +"」当前使用者列表：\n"+NOR;
		str += "──────────────────────────────────────────\n";
		str += BBLU+HIW"姓名          帐号          上线总计时                      发呆    网络地址        \n"NOR;
		str += "──────────────────────────────────────────\n";
		str += msg;
		str += "──────────────────────────────────────────\n";
		this_player()->start_more(str);
			return "共有"+ chinese_number(sizeof(ob))+"位使用者正在游戏中和等待连线中。\n";


	}
}
string finger_user(string name)
{
	object ob, body;
	string msg;
	int public_flag;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore()) {
		write("没有这个玩家。");
		destruct(ob);
		return "\n";
	}
	if( !wizardp(this_player())){
		if( objectp(body = find_player(name)) && geteuid(body)==name ){
			public_flag = body->query("env/public")?1:0;
		} else
			{
			body = LOGIN_D->make_body(ob);
			if( !body->restore() ) return "没有这个玩家。\n";
			public_flag = body->query("env/public")?1:0;
			destruct(body);
		}

		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件：\t%s\nOicq号码：\t%s\n最近连线：\t%s\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			public_flag?ob->query("email"):"不告诉你",
			public_flag?ob->query("oicq"):"不告诉你",
			ctime(ob->query("last_on"))
		);
		if( objectp(body = find_player(name)) && geteuid(body)==name ) {
			if (this_player()->visible(body))
			msg += sprintf("\n%s目前正在连线中。\n", body->name(1));
		}
	} else    // wizard finger

	{
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件：\t%s\nOicq号码：\t%s\n最近连线：\t%s( %s )\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("oicq"),
			ob->query("last_from"),
			ctime(ob->query("last_on"))
		);
		if( objectp(body = find_player(name)) && geteuid(body)==name ) {
			msg += sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),
				query_ip_number(body));
			msg += sprintf("连线总计为：%s。\n\n",CHINESE_D->chinese_time( (int)body->query("mud_age")));
		}
	}

	destruct(ob);
	return msg;
}
object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");

	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

string get_killer()
{
	int i;

	object *ob = users();

	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query("kill_flag"))
			return "\n现在本城正在缉拿以下人犯：\n\n"RED + ob[i]->name() + "("+ob[i]->query("id")+")"+ NOR +"\n\n捉获以上逃犯送官者，重赏！\n";
	else
		return "本城治安良好。\n";
}
int sort_user(object ob1, object ob2)
{
	int time1,time2;
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);
	time1 = ob1->query("mud_age");
	time2 = ob2->query("mud_age");
	if (time1 > time2) return -1;
	if (time1 < time2) return 1;
		return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");

}
