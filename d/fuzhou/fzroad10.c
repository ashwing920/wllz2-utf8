// Room: /d/fuzhou/fzroad10.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "酒肆");
	set("long", @LONG
酒店门口一个酒招子半拉子挂着，店主人老蔡却不见了。两间茅屋的
小店显得十分空落，只有一个青袍年轻憨子靠在酒炉上冷冷地瞧着你。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"fzroad9",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/yuyan" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

