// Room: /d/fuzhou/fzroad6.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。山中毒
虫猛兽出没无常，行路艰辛。一个粗豪汉子站在当道。
LONG
);
	set("exits", ([
		"westdown" : __DIR__"fzroad7",
		"eastdown" : __DIR__"fzroad5",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/yu" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

