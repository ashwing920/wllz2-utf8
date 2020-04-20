// shijie9.c 石阶
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条整齐的石板路，依山而建，随着山势的曲折蜿蜒曲折。由于
山势陡了，当初修建这条石阶时肯定费了不小的功夫。走到这里，已经可
以看见全真教重阳观的檐角了。西面好象有一条小路。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northdown" : __DIR__"shijie8",
		"south" : __DIR__"guanritai",
	]));
	set("objects",([
		__DIR__"npc/daotong" : 2,
	]));

	setup();
	replace_program(ROOM);
}
