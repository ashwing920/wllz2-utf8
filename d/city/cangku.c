// cangku.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void init();
void create()
{
	set("short", "仓库");
	set("long", @LONG
这里是一间黑黝黝的仓库，堆满了唐家的各种杂物，塞了满满一仓库
。看来你是被人拐卖到这里来的。
LONG );
	set("valid_startroom",1);
	set("no_fight", 1);

	set("objects", ([
		"/clone/food/jitui" : 3,
		"/clone/food/jiudai" : 1,
	]));
	setup();
}

void init()
{
	object ob;

	ob = this_player();
	ob->set("startroom","/d/city/cangku");
	ob->set_temp("selled", 1);
	add_action("do_punish","suicide");

}
int do_punish()
{
	object me;
	me = this_player();
	if( wizardp(me)) return 0;
	tell_object(me,"你现在不能自杀,还是老老实实呆这儿吧!\n");
	return 1;
}
