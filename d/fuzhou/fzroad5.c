// Room: /d/fuzhou/fzroad5.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。山中毒
虫猛兽出没无常，行路艰辛。路边有一年轻汉子倚在树上冷眼看着你。
LONG
);
	set("exits", ([
		"westup"	: __DIR__"fzroad6",
		"northeast" : __DIR__"fzroad4",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/fang" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

