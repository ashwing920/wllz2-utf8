//xiaolu4
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",@LONG
这里是一条上山的小路向西分出一条岔道。北边是山贼的老窝。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
		"westdown" : "/d/npc/m_weapon/lianzhangshi",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));
	setup();
	replace_program(ROOM);
}
