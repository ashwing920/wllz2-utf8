// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "眉毛崖");
	set("long", @LONG
看这眉毛崖两侧弯弯，长满整齐的林木，就象两道浓眉，中间有一条
采药人踏出的几乎看不见的小道(xiaodao)。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"baichi",
		"southdown" : __DIR__"taohua",
	]));
	set("objects", ([
		__DIR__"npc/shashou2": 2,
	]));
	set("item_desc", ([
		"xiaodao" : "此乃本教风景区.\n",
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
 
