// Room: /city/kedian.c

inherit ROOM;

void create()
{
	set("short", "客栈");
	set("long", @LONG
这是一家价简陋客栈，店铺虽然不大，生意却不错，许多过往的人都
喜欢选择这里落脚，因为这里的店主识得一些江湖中人，所以很少有人会
来此闹事，小二忙前忙后的招呼客人，店主也满脸笑容的陪着说好话。让
人觉的有归家的感觉一般。
LONG
);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/laoban" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandajie2",
		"westup" : __DIR__"kedian1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店主笑着对你说道：客官请先这里付了钱再上楼住店。\n");

	return ::valid_leave(me, dir);
}
