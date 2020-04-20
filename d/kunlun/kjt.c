//d/kunlun/kjt.c

inherit ROOM;

void create()
{
	set("short","观景台");
	set("long", @LONG
这里是昆仑绝顶，俯视四周，只见众山峰被雪覆盖着，白云围涌，十
分壮观，令人心旷神怡。
LONG
);
	set("objects", ([
		CLASS_D("kunlun")+"/banshuxian"  : 1,
	]));
	set("outdoors","kunlun");
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"dt",
	]));
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	
	if(!arg || arg == "" || arg != "down") return 0;
	if((int)me->query_skill("dodge",1) < 100)
		return notify_fail("你的轻功不足，跳下去恐怕只有死路一条。\n");
	message_vision("$N纵身跃起，“嗖”的一声往观景台跳了下去。\n",me);
	me->move(__DIR__"mw");
	return 1;
}
