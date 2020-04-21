//clan.c
// 建立帮会

#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me,string arg)
{
	string cname,ctitle,tmp;
	object ob;
	mapping clan = ([ ]);
	int num;

	if(!arg) return help(me);

	if(sscanf(arg,"create %s",arg) == 1){
		if(!arg) return notify_fail("你要建立什么帮会？\n");

		if((int)me->query("combat_exp") < 10000000)
			return notify_fail("你的经验不足以创立帮会。\n");
				
		if((int)me->query("weiwang") < 30000)
			return notify_fail("你的威望不足以创立帮会。\n");
			
		if( !(num = REC_D->query_vote(me->query("id"),"clan")) || num < 30)
			return notify_fail("你的推荐票数不足以成立帮会。\n");

		if((mapping)me->query("clan"))
			return notify_fail("你已经成立帮会了。\n");
			
		tmp = clean_color(arg);

		if(strlen(tmp) > 5)
			return notify_fail("帮会名称最多只能五个字，请重新设定。\n");
	
		if(!is_chinese(tmp))
			return notify_fail("对不起，帮会名字只能使用中文。\n");

		clan["name"] = convert_color(arg);
		clan["master"] = 1;
		clan["title"] = "教主";
		clan["time"] = NATURE_D->game_time();
		clan["member"] = 1;
		me->set("clan",clan);
		message("channel:chat",sprintf(HIC"【江湖消息】"HIG"%s，%s(%s)成立了%s。\n"NOR,NATURE_D->game_time(),me->query("name"),me->query("id"),convert_color(arg)),users());
		log_file("clan",sprintf("%s，%s(%s)成立了%s。\n",ctime(time()),me->query("name"),me->query("id"),convert_color(arg)));
		return 1;
	}
	if(sscanf(arg,"title %s %s",arg,ctitle) == 2){
		if(!objectp(ob = present(arg, environment(me))))
			return notify_fail("你要帮谁设置帮会位阶？\n");
		if((string)ob->query("clan/name") != (string)me->query("clan/name"))
			return notify_fail(ob->name()+"不是你的帮众。\n");
		if(!me->query("clan/master"))
			return notify_fail("你不是帮会第一阶层，无权对帮众位阶进行修改。\n");
		
		tmp = COLOR_D->clean_color(ctitle);

		if(strlen(tmp) > 12)
			return notify_fail("帮会位阶头衔过长，请重新设定。\n");

		ob->set("clan/title",convert_color(ctitle));
		message_vision("$N将$n的帮会位阶进行修改。\n",me,ob);
		return 1;
	}
	if(sscanf(arg,"join %s",arg) == 1){
		if(!objectp(ob = present(arg, environment(me))))
			return notify_fail("你要加入谁的帮会？\n");
		if(me->query("clan"))
			return notify_fail("你已经加入帮会了。\n");
		if(!ob->query("clan/master"))
			return notify_fail(ob->query("name")+"并不是帮会第一阶层，无法受理你加入帮会。\n");
		if(me->query_temp("wait_join_clan") == ob){
			message_vision("$N打算加入$n的帮会，可$n迟迟没有答复。\n",me,ob);
			return 1;
		}
		if(ob->query_temp("wait_recruit_clan") == me){
			message_vision("$N决定加入$n的帮会组织。\n",me,ob);
			me->set("clan/name",ob->query("clan/name"));
			me->set("clan/title","帮众");
			me->set("clan/time",NATURE_D->game_time());
			ob->add("clan/member",1);
			ob->delete_temp("wait_recruit_clan");
			return 1;
		}
		me->set_temp("wait_join_clan",ob);
		message_vision("$N打算加入$n的帮会，正等待$n的许可。\n",me,ob);
		tell_object(ob,me->name(1)+"打算加入你的帮会，如果你愿意，请输入：("WHT"clan recruit "+ me->query("id")+NOR")。\n");
		return 1;
	}
	if(sscanf(arg,"recruit %s",arg) == 1){
		if(!objectp(ob = present(arg, environment(me))))
			return notify_fail("你打算吸收谁加入你的帮会？\n");
		if(!me->query("clan/master"))
			return notify_fail("你不是帮会第一阶层，无法吸收弟子。\n");
		if(ob->query("clan"))
			return notify_fail(ob->name(1)+"已经加入过帮会了。\n");
		if(ob->query_temp("wait_join_clan") == me){
			message_vision("$N决定让$n加入自己的帮会组织。\n",me,ob);
			ob->set("clan/name",me->query("clan/name"));
			ob->set("clan/title","帮众");
			ob->set("clan/time",NATURE_D->game_time());
			me->add("clan/member",1);
			ob->delete_temp("wait_join_clan");
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
				sprintf("%s，%s加入了%s！",NATURE_D->game_time(),ob->name(2),
					clean_color(me->query("clan/name"))));
			return 1;
		}
		if(me->query_temp("wait_recruit_clan") == ob){
			message_vision("$N打算吸纳$n加入自己的帮会，可是$n却迟迟没有答复。\n",me,ob);
			return 1;
		}
		me->set_temp("wait_recruit_clan",ob);
		message_vision("$N打算接收$n到自己的帮会，正等待$n的答复。\n",me,ob);
		tell_object(ob,me->name(1)+"打算接收你加入帮会，如果你愿意，请输入：("WHT"clan join "+ me->query("id")+NOR")。\n");
		return 1;
	}
	if(sscanf(arg,"expell %s",arg) == 1){
		if(!objectp(ob = present(arg, environment(me))))
			return notify_fail("你打算将谁开除出你的帮会？\n");
		if(!me->query("clan/master"))
			return notify_fail("你不是帮会第一阶层，无权开除帮众。\n");
		if((string)ob->query("clan/name") != (string)me->query("clan/name"))
			return notify_fail(ob->name()+"不是你的帮众。\n");
		if(ob == me)
			return notify_fail("你无法开除自己。\n");
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("听说%s离开了%s，成为无组织的江湖侠客。",ob->name(2),
			clean_color(ob->query("clan/name"))));
		ob->delete("clan");
		me->add("clan/mamber",-1);
		message_vision("$N将$n踢出帮会，$n成为无组织的江湖侠客。\n",me,ob);
		return 1;
	}
}
int help(object me)
{
	write(@TEXT

这个指令是让你对创建帮会，吸纳帮众和开除帮众所用，在没有加入帮会
之前，你也可以使用这个指令加入玩家创造的帮会。指令使用格式如下：

clan join	<加入帮会>	使用该指令可加入已创建的帮会。
clan create	<帮会名称>	凡是满足条件者，便可创建帮会。
clan title	<帮众头衔>	帮主给予帮会成员设置的帮会头衔。
clan expell	<开除帮众>	帮主可使用该指令开除帮会成员。
clan recruit	<玩家id>	吸纳玩家成为你帮会的一员。

TEXT);
	return 1;
}