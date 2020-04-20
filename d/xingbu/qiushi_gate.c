// /d/beijing2/xingbu/hall.c

inherit ROOM;

void create()
{
	set("short", "囚室入口");
	set("long", @LONG
这是刑部囚禁犯人的地方。但是守卫不见得特别森严。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"down" :  __DIR__"qiushi1",
		"north":  __DIR__"hall",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qiushi_shouwei" : 5,
	]));
	setup();

}

int valid_leave(object me, string dir)
{
	if( dir == "down" && !me->query_temp("give_parsion_money"))
		return notify_fail("守卫双手一拦：大人有令，谁也不能进去。\n");
	if(dir != "down" && me->query_temp("give_parsion_money"))
		me->delete_temp("give_parsion_money");
	me->apply_condition("into_parsion",50);
	return ::valid_leave(me, dir);
     
}
