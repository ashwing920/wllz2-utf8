// Room: /d/songshan/qimushi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "启母石");
	set("long", @LONG
这里有一壁三丈巨石当道。相传大禹治水时要打通辕擐山，大禹化熊
扒挖不止。禹妻涂山氏送饭时不慎撞破，失惊而逃，到此化石。其时涂山
已有身孕，大禹追及唤子，巨石北裂一口，夏启呱呱落地。巨石因此唤作
启母石。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"	  : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

