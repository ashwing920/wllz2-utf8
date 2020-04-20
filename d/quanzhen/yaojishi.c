// yaojishi.c 药剂室
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "药剂室");
	set("long", @LONG
这里是全真教制药、配药的地方。这间房间本来很大，只是被前后左
右堆放的药柜药箱挤的显得小多了。药柜已经很陈旧了，不过是用上好的
南海沉香木做成的，据说用这种木材做成的柜子用来储藏东西不会遭虫蛀
。药柜上面有个抽屉(drawer)。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
		"east" : __DIR__"xianzhentang",
		"west" : __DIR__"danfang1",
		"south" : __DIR__"df",
	]));
	set("count", 1);
	set("item_desc", ([ /* sizeof() == 1 */
		"drawer" : "一个抽屉，不知道是因为粗心还是什么原因，没有上锁。",
	]));
	set("sleep_room", 1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhangyao" : 1,
	]));

	setup();
	replace_program(ROOM);
}
