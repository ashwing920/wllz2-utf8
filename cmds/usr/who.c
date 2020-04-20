// who.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int sort_user(object,object);
int sort_clan(object ob1, object ob2);
int sort_userid(object ob1, object ob2);
int help();

private void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string name, str, *option,qname,*frd_list,coin;
	object *list, *ob, ob1;
	int i, ppl_cnt,player_cnt;
	int opt_long, opt_wiz, opt_party,opt_male,opt_female,opt_normal;
	int opt_dead,opt_banghui,opt_id,opt_ids,opt_frd,opt_master,opt_close,opt_clan;

	if(!remote) frd_list = me->query("my_friends");
	if(remote && sizeof(arg)<2) arg="";
	if(arg && qname != "" && sscanf(arg,"is %s",qname) == 1) opt_id = 1;
	else if( arg )
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
				case "-h": return help();
				case "-l": opt_long = 1;break;
				case "-w": opt_wiz = 1;break;
				case "-b": opt_banghui = 1;break;
				case "-p": opt_party = 1;break;
				case "-f": opt_female = 1;break;
				case "-m": opt_male = 1;break;
				case "-n": opt_normal = 1;break;
				case "-d": opt_dead = 1;break;
				case "-s": opt_ids = 1;break;
				case "-z": opt_master = 1;break;
				case "-frd": opt_frd = 1;break;
				case "-c": opt_close =1;break;
				case "-clan": opt_clan =1;break;
				default:
					if(option[i][0]=='@' )
					{
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
						write("网路讯息已送出，请稍候。\n");
						return 1;
					}
					ob1 = present(option[i], environment(me));
					if (!ob1) ob1 = find_player(option[i]);
					if (!ob1) ob1 = find_living(option[i]);
					if ((!ob1) && (option[i] =="me")) ob1=me;
					if (!ob1 || !me->visible(ob1)) {
						write("没有这个玩家或参数错误。\n");
						return help();
					}
					me = ob1; opt_party = 1;
			}
	}

	str = HIY"「" + code_name() +"」"HIW"目前";
	if(opt_banghui)
		if((string)me->query("clan/name"))
			str += (string)me->query("clan/name")+ HIW"的玩家有：";
		else
			return notify_fail("你目前还没有加入任何帮会。\n");
	else if(opt_party)
		if((string)me->query("family/family_name"))
			str += (string)me->query("family/family_name")+"的玩家有：";
		else str += "普通百姓有：";

	else if(opt_frd)
		if(!frd_list)
			return notify_fail("你目前并没有设置任何好朋友。\n");
		else str += "在线的好朋友有：";

	else if(opt_id)
		str += "叫"+ qname +"的玩家有：";
	else if(opt_male)
		str += "男性玩家有：";
	else if(opt_female)
		str += "女性玩家有：";
	else if(opt_normal)
		str += "太监有：";
	else if(opt_wiz)
		str += "巫师有：";
	else if(opt_long)
		str += "玩家有：";
	else if(opt_master)
		str += "武林宗师有：";
	else str += "总人物有：";

	if(!wizardp(me)){
		if((int)me->query("jing") < (int)me->query("eff_jing")  / 20 )
			return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
		me->receive_damage("jing",(int)me->query("eff_jing")/ 10);
	}

	str += HIY"\n─────────────────────────────────────\n"NOR;
	ob = filter_array(children(USER_OB),(: userp :));
	if(opt_banghui)
		ob = filter_array(ob, (: (string)$1->query("clan/name") == (string)$2->query("clan/name") :), me);
	else if (opt_party)
		ob = filter_array(ob, (: (string)$1->query("family/family_name") == (string)$2->query("family/family_name") :), me);
	if( opt_ids )
		list = sort_array(ob,"sort_userid");
	else if( opt_clan)
		list = sort_array(ob,"sort_clan");
	else
		list = sort_array(ob,"sort_user");
	ppl_cnt = 0;
	if(opt_long || opt_wiz)
	{
		i = sizeof(list);
		while ( i-- )
		{
			// Skip those users in login limbo.
			if( !environment(list[i])) continue;
			if( !wizardp(me) && !me->visible(list[i]) ) continue;
			if( opt_wiz && !wizardp(list[i]) && wizhood(list[i]) != "(immortal)" ) continue;
			if( opt_clan && !list[i]->query("clan")) continue;
			if( interactive(list[i]) ) ppl_cnt++; player_cnt++;
			if(!interactive(list[i]) && !list[i]->query_temp("biguan")) coin = HIR"#"NOR;
			else if(interactive(list[i]) && query_idle(list[i]) > 120) coin = HIG"*"NOR;
			else if(list[i]->query_temp("biguan")) coin = HIY"~"NOR;
			else coin = " ";
			if(opt_clan)
				str = sprintf("%s%12s%s%s%s%s\n",
					str,RANK_D->query_rank(list[i]),coin,
					(string)list[i]->query("clan/name")+ NOR,
					(string)list[i]->query("nickname")?"「"+ (string)list[i]->query("nickname")+"」":" ",
					list[i]->name(2));
			else
				str = sprintf("%s%12s%s%s\n",str,RANK_D->query_rank(list[i]),coin,list[i]->short(1));
			
		}
	}
	else {
		ppl_cnt = 0;
		i = sizeof(list);
		while( i-- ){
			if(!environment(list[i])) continue;
			if(!me && wizardp(list[i]) && (int)list[i]->query("env/invisibility")) continue;
			if(!remote && !wizardp(me) && !me->visible(list[i])) continue;
			if(opt_wiz && !wizardp(list[i]) ) continue;
			if(opt_male && (string)list[i]->query("gender")!="男性") continue;
			if(opt_female && (string)list[i]->query("gender")!="女性") continue;
			if(opt_normal && (string)list[i]->query("gender")!="无性") continue;
			if(opt_dead && !(int)list[i]->query_temp("netdead")) continue;
			if(opt_master && !(int)list[i]->query("is_zongshi")) continue;
			if( opt_clan && !list[i]->query("clan")) continue;
			if(opt_id && qname && (string)list[i]->query("name") != qname ) continue;
			if(opt_frd && pointerp(frd_list) && member_array(list[i]->query("id"),frd_list) == -1) continue;
			if(opt_close && !list[i]->query_temp("biguan")) continue;
			if( wizardp(list[i])){
				name = sprintf( HIG"%-10s(%-11s"HIY"│"NOR + HIG,list[i]->name(1),
				capitalize(list[i]->query("id"))+")");
			}
			else if((string)list[i]->query("gender") == "女性"){
				name = sprintf( HIC"%-10s(%-11s"HIY"│"NOR + HIC,list[i]->name(1),
				capitalize(list[i]->query("id"))+")");
			}
			else {
				name = sprintf(NOR + WHT"%-10s(%-11s"HIY"│"NOR + WHT,list[i]->name(1),
				capitalize(list[i]->query("id"))+")");
			}
			if(!interactive(list[i]) && !list[i]->query_temp("biguan")) coin = HIR"#";
			else if(interactive(list[i]) && query_idle(list[i]) > 120) coin = HIG"*";
			else if(list[i]->query_temp("biguan")) coin = HIY"~";
			else coin = " ";
			str = sprintf("%s%s%25s%s", str,coin,name,ppl_cnt%3==2?"\n":"");
			ppl_cnt++;
			player_cnt++;
		}
		if ( ppl_cnt%3 ) str += "\n";
	}
	str += HIY"─────────────────────────────────────\n"NOR;

	if(player_cnt)
		str = sprintf("%s共有 %s 位使用者连线中，系统负担：%s\n "HIG"*"NOR" 表示发呆中，"HIR"#"NOR" 表示断线中，"HIY" ~"NOR" 表示离线闭关中。\n\n", str, CHINESE_D->chinese_number(player_cnt),
		query_load_average());
	else
		str = sprintf("目前游戏中并没有符合该条件的玩家。\n");

	if( remote )
		return str;
	else
		me->start_more(str);

	return 1;
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);
	name1 = (string)ob1->query("family/family_name");
	name2 = (string)ob2->query("family/family_name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
		return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");

}
int sort_clan(object ob1, object ob2)
{
	string name1, name2;
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);
	name1 = (string)ob1->query("clan/name");
	name2 = (string)ob2->query("clan/name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
		return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int sort_userid(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2)
			- (int)SECURITY_D->get_wiz_level(ob1);
	if( ob1->query("id") && !ob2->query("id") )
		return -1;
	if( ob2->query("id") && !ob1->query("id") )
		return 1;
	if( !ob1->query("id") && !ob2->query("id") )
		return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
	return strcmp(ob2->query("id"), ob1->query("id"));
}
int help()
{
	write("
指令格式 : who [-h] [-l] [-w] [-p] [-f] [-m] [-d] [-s] [is] [-frd] [<ID>]

这个指令可以列出所有在游戏中的玩家及其等级。

-h　　列出帮助屏幕。
-l　　选项列出较长的讯息。
-b　　只列出同帮会的玩家。
-p　　只列出同门派的玩家。
-w　　只列出游戏中的巫师。
-f　　只列出游戏中的女玩家。
-m　　只列出游戏中的男玩家。
-n　　只列出游戏中的无性玩家。
-c    只列出目前处于闭关中的玩家。
-d　　只列出当前游戏中处于断线状态中的玩家。
-s　　按照 id 字母升序排列玩家。
-z    只列出当前游戏中的武林宗师。
is　　如果使用了这个选项，后面要跟随玩家的中文名字。
-frd　列出当前在线的好朋友，必须使用 frd 指令先行设置好朋友名单。
-clan 列出已经加入帮会的所有玩家。
<ID>　列出<ID>代表玩家所属门派的玩家。

"HIG"*"NOR" 表示"HIG"发呆"NOR"中，"HIR"#"NOR" 表示"HIR"断线"NOR"中。

相关指令： finger \n\n");
	return 1;
}
