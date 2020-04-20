// mask.c

inherit ITEM;

void create()
{
	set_name("面具", ({ "mian ju", "mask" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set_weight(3000);
		set("unit", "个");
		set("long", "这似乎是一个由人皮制成的面具。\n");
	}
	setup();
}
void init()
{
	if(environment()==this_player())
	add_action("do_pretend", "pretend");
	add_action("do_pretend", "ban");
}
int do_pretend(string arg)
{
	object who;
	object me = this_player();

	if(!arg)
		return notify_fail("你想假装谁？\n");

	if (arg == "none" || arg == "cancel") {
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
		message_vision("$N从脸上取下了一个人皮面具。\n", me);
		return 1;
	}
	if(!objectp(who = present(arg, environment(me))) 
	|| !living(who)	|| who->query("race") != "人类"
	|| wizardp(who))
		return notify_fail("你想假装谁？\n");

	write("你开使假装" + who->name() + "。\n");
	message_vision("$N戴上了一个精功制成的人皮面具。\n", me);

	me->set_temp("apply/name", ({who->name()}));
	me->set_temp("apply/short", ({who->short()}));
	me->set_temp("apply/long", ({who->long()}));
	set_temp("owner",me);
	return 1;
}
int move(mixed dest)
{
	object me;

	if (me = query_temp("owner"))
	{
		me->delete_temp("apply/name");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
		delete_temp("owner");
	}

	return ::move(dest);
}
