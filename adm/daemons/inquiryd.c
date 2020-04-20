// inquiryd.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

int reply_ask(object me,object ob);

int parse_inquiry(object me, object ob, string topic)
{

	switch( topic )
	{
		case "name":
			message_vision( CYN "$N向$n问道：敢问" + RANK_D->query_respect(ob)
				+ "尊姓大名？\n" NOR, me, ob);
			return 1;

		case "here":
			message_vision(CYN "$N向$n问道：这位" + RANK_D->query_respect(ob)
				+ "，" + RANK_D->query_self(me) + "初来乍到，不知这里有些什麽风土人情？\n" NOR,
				me, ob);
			return 1;

		case "rumors":
			message_vision(CYN "$N向$n问道：这位" + RANK_D->query_respect(ob)
				+ "，不知最近有没有听说什么消息？\n" NOR, me, ob);
			return 1;

		case "marry":
			message_vision(CYN "$N笑呵呵的向$n问道：敢问这位"+RANK_D->query_respect(ob)
				+"是否婚配？\n" NOR,me,ob);
			return 1;

		default:
			return 0;
	}
}
int reply_ask(object me,object ob)
{
	mapping quest;
	object obj;
	string where;

	quest = me->query("quest");
		if( !me->query_temp("ask_quest_money")){
			tell_object(me,ob->name()+"对你嘿嘿一笑道：客官，来我这里买消息？可是要收钱的呀！！\n");
			me->set_temp("ask_quest",1);
			me->receive_damage("jing",10);
			return 1;
		}
		if(objectp(obj = quest["obj"]) && environment(obj)){
			where = environment(obj)->query("short");
			switch(random(5)){
				case 1:
					message_vision("$N凑到$n耳边悄悄的说了一些话。\n");
					tell_object(me,ob->name()+"在你耳边悄声说道：我听说在"+ quest["where"] + where +"有个叫"
						+ obj->name(1) +"的，不知从哪来了一本"+ quest["quest"]+"。\n"
						"听说可以习得盖世武功，客官有兴趣的话可以去他那里看看。\n");
					break;
				case 2:
					message_vision("$N凑到$n耳边悄悄的说了一些话。\n");
					tell_object(me,ob->name()+"附在你耳边说道：我听几个剑客说，有个叫"+ obj->name(1)+"的高手，偷到了一本"+ quest["quest"]+"。\n"
					"能够从"+ me->query("family/family_name")+"偷到秘籍，想必身手一定非常了得。\n");
					break;
				case 3:
					tell_object(me,ob->name()+"想了想说道：好象最近"+ quest["where"] +"来了一个叫"+ obj->name(1)+"的"+ obj->query("title")+"，样子看起来怪怪的。\n");
					break;
				default:
					tell_object(me,ob->name()+"摇了摇头道：最近没听说有什么消息，客官您可有新鲜事可告诉我呢？\n");
					break;
				}
		}
		else {
			tell_object(me,ob->name()+"摇了摇头道：最近没听说有什么消息，客官您可有新鲜事可告诉我呢？\n");
		}

	me->delete_temp("ask_quest_money");
	me->receive_damage("jing",10);
	return 1;
}
