// ask.c

#include <ansi.h>
inherit F_CLEAN_UP;

private string *msg_dunno = ({
	CYN"$n摇摇头，说道：没听说过。\n"NOR,
	CYN"$n疑惑地看着$N，摇了摇头。\n"NOR,
	CYN"$n对$N大喊：我什么都不知道，什么都不会，千万不要问我！说完，往地上一躺假装昏倒了。\n"NOR,
	CYN"$n睁大眼睛望着$N，显然不知道$P在说什么。\n"NOR,
	CYN"$n疑惑道：你在说什么？我听不懂耶！\n"NOR,
	CYN"$n耸了耸肩，很抱歉地说：无可奉告。\n"NOR,
	CYN"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n"NOR,
	CYN"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"NOR,
	CYN"$n想了想，疑道：我为什么要告诉你呢？\n"NOR,
	CYN"$n义正严词的说：“DON'T ASK ME！”\n"NOR,
	CYN"$n漫不经心的说了一句：卡诺吉瓦雅马哈！\n"NOR,
});
int main(object me, string arg)
{
	string dest, topic,msg,callme;
	object ob;
	seteuid(getuid());
	callme = RANK_D->query_respect(me);

	if(me->ban_say()) return 0;

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if(!wizardp(me) && me->query("jing") < 20)
		return notify_fail("你太累了，根本没法向人套近乎。\n");

	if( !ob->is_character() )
		return notify_fail("看清楚点，那不是活的吧。\n");

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}
	if( ob->is_fighting())
		return notify_fail(ob->query("name")+"保命要紧，才懒得理你呢！\n");

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		if(userp(ob))
			message_vision(CYN"$N向$n问道：『"HIG + topic + NOR +CYN"』\n"NOR,me,ob);
		else
			message_vision(CYN"$N向$n打听有关『"HIG + topic + NOR +CYN"』的消息。\n"NOR, me, ob);

	me->receive_damage("jing",10);

	if( userp(ob) ){
		ob->set_temp("pending/ask",me);
		return 1;
	}
	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",me, ob);
		return 1;
	}
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		switch(topic){
			case "name":
				message_vision(CYN"$N说道："+ RANK_D->query_self(ob)+"名曰："+ ob->name()+"，这位"+ callme+"还请多多指教！\n"NOR,ob);
				break;
			case "here":
				message_vision(CYN"$N说道：这里就是"+ environment(me)->query("short")+CYN"，其他的我什么也不清楚。\n"NOR,ob);
				break;
			case "marry":
				message_vision(CYN"$N说道：这位"+ callme+"实在是见笑了。\n"NOR,ob);
				break;
			case "rumors":
				if(ob->is_vendor()){
					if(me->query("quest/must_ask")){
						INQUIRY_D->reply_ask(me,ob);
						break;
					}else {
						RQUEST_D->random_quest(me,ob);
						break;
					}
				}
				else
					EMOTE_D->do_emote(ob, "dunno");
				break;
			default:
				if (topic == ob->query("name") || ob->id(topic))
					message_vision(CYN "$n说道：那就是" + RANK_D->query_self_rude(ob) + "呀。\n" NOR, me, ob);
				else if (topic == me->query("name") || me->id(topic))
					message_vision(CYN "$n说道：那就是" + RANK_D->query_rude(me) + "你呀。\n" NOR, me, ob);
				else 
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
