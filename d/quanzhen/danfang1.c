// Room: /d/quanzhen/danfang1
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create ()
{
	set ("short", "木廊");
	set ("long", @LONG
这里是全真教道士通往炼丹房的走廊，全是用终南山上好的木材建造
起来的，没有什么特别的地方，只是从木廊的尽头时常会传来一阵阵的药
香味，木廊的两边点着几盏油灯。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"danfang3",
		"south" : __DIR__"danfang4",
		"east" : __DIR__"yaojishi",
		"west" : __DIR__"danfang2",
	]));

	setup();
	  replace_program(ROOM);
}
