// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int slow_suicide(object me);
private int halt_suicide(object me);

int main(object me, string arg)
{
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你上一个动作还没完成。\n");

	if( !arg ) {
		write("重新投胎完毕。\n");
		return 1;
	}
	if( wizardp(me) || wizhood(me) == "(immortal)")
		return notify_fail("你有重任在身，不能自杀！\n");

	if( arg!="-f" )
		return notify_fail("自杀有两种，您是要永远死掉还是重新投胎？\n");

	write("如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
		"考虑清楚，确定的话请输入您的密码：");
	input_to("check_password", 1, me, 1);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}

	if (forever) {
		tell_object( me,HIR "\n\n你决定要自杀了，如果十五秒钟内不后悔，就真的永别了。\n\n\n" NOR);
		me->add_temp("to_suicide",1);
		me->set_temp("suicide_countdown", 15);
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("%s[%s]正寻找一种自杀的方式，离开这个世界！",
		me->name(1),geteuid(me)));
		me->start_busy( (: slow_suicide,me :),
				(: halt_suicide, me :));
	}
}

private int slow_suicide(object me)
{
	object link_ob,where,npc;
	int stage;
	mapping name;
	string myid,place,msg;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
		  tell_object(me,
			HIR "\n你还有 " + stage + " 秒的时间可以后悔。"+ HIW"[可用 halt 指令来终止自杀]\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s[%s]于[%s]自杀，连线来自[%s]。\n", me->name(1),geteuid(me),ctime(time()),(string)query_ip_number(me)));

	seteuid(getuid());
	myid=me->query("id");
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__);
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
	if( file_size(DATA_DIR + "mail/" + sprintf("%c", myid[0]) + "/" + myid + __SAVE_EXTENSION__) > 0 )
	rm(DATA_DIR + "mail/" + sprintf("%c", myid[0]) + "/" + myid + __SAVE_EXTENSION__);

	PNAME_D->del_name(myid,me->query("name"));

	npc = find_living("wulin mengzhu");
	if(!npc) npc = load_object("/clone/npc/meng-zhu");
	if((string)npc->query("winner") == (string)me->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}
	npc = find_living("shangshan shizhe");
	if(!npc) npc = load_object("/clone/npc/shang-shan");	
	if((string)npc->query("winner") == (string)me->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}
	npc = find_living("fae shizhe");
	if(!npc) npc = load_object("/clone/npc/fa-e");
	if((string)npc->query("winner") == (string)me->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}

	write("好吧，永别了:(\n");
	tell_room(environment(me), me->name() +"自杀了，以后你再也看不到这个人了。\n", ({me}));
	where = environment(me);
	place =  (where->short()?where->short():where->query("short"));
	switch( random(4) ) {
		case 0: msg = "服毒双料自杀了！！";
			break;
		case 1:
			msg = "在"+ place +"悬梁自尽了！！";
			break;
		case 2:
			msg = "在"+ place +"挥剑自刎而死！！";
			break;
		default:
			msg = "在"+ place +"自断经脉，吐血身亡！！";
			break;
	}
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("%s[%s]%s",me->name(1),geteuid(me),msg));
	reclaim_objects();
	destruct(me);
	return 0;
}
int help (object me)
{
	write(@HELP
指令格式: suicide [-f]

如果因为某种原因你不想活了, 你可以选择自杀，自杀分两种:

suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你输入密码以确认身份。

请慎重选择 :)

HELP
);
	return 1;
}
