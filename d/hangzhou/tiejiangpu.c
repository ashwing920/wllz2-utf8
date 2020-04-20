// tiejiangpu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这是一家不小的打铁铺，店里摆了几座火炉，一位铁匠正在火炉旁满
头大汗地打造东西。一位老者坐在边上。火炉边放着不少打好了的铁器。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"road11",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/smith" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	me=this_player();
	if (dir == "west")
	if((int)me->query_temp("marks/ouyezi"))
	{
	   return notify_fail("铁匠对你道：哎，这位客官，拿了兵器再走！\n");
	}
	return 1;
}
