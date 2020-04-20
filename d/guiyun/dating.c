// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /guiyun/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是归云庄的正厅，由于修建年代久远，看起来已颇为陈旧，但打扫
得十分干净，光线也较为充足，完全没有陈年旧宅的阴晦之气。四壁挂着
一些古人书画精品，皆为上乘之作，显得主人眼光不凡，胸中大有丘壑。
LONG 
);
	set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east"  : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoyin" : 1,
	]));
	setup();
	replace_program(ROOM);
}
