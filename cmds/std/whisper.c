// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;

	if(me->ban_say()) return 0;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什么？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character()
	|| (wizardp(ob) && ob->query("env/invisibility")))
		return notify_fail("你要对谁耳语？\n");

	if( me == ob)
		return notify_fail("你的嘴巴和耳朵长在一起的吗？\n");

	if(!wizardp(me) && me->query_condition("no_speak"))
		return notify_fail("你支支吾吾的，半天也说不出句话来。\n");

	if(!wizardp(me) && ob->query("env/no_whisper"))
		return notify_fail("对方不接受耳语，有事请用其他方法联系。\n");

	write( HIG "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob)) ob->relay_whisper(me, msg);
	else
		tell_object( ob, HIG + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}
