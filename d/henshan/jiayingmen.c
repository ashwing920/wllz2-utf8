// Room: /d/henshan/jiayingmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "嘉应门");
	set("long", @LONG
这里是地方官迎接京师御史官来祭南岳的地方，是南岳大庙第五进门
了。门上雕塑也较精细些，悬彩灯笼时时换新。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"yubeiting",
		"north"  : __DIR__"yushulou",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

