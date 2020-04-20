// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
		return 1;
	} else if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");

	if( ob->query("no_snoop") && me->query("id") == "robert")
		return notify_fail("你不能监听这个人所收到的信息。\n");

	if( !userp(ob) && !wizardp(ob))
		return notify_fail("你只能收听玩家的信息。\n");

	if( ob->query_temp("netdead"))
		return notify_fail("这个人当前正属于断线状态，你无法收听信息。\n");

	if( wizhood(me) != "(admin)"
	&&      wiz_level(me) <= wiz_level(ob) )
		return notify_fail("你没有监听" + ob->name() + "所收听讯息的权利。\n");

	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");

	snoop(me, ob);
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	return 1;
}

int help()
{
	write(@TEXT
指令格式：snoop <某人>|none

监听其他使用者所收听的讯息，snoop none 则取消监听。
TEXT
	);
	return 1;
}
