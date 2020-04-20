// Room: /d/henshan/sansheng.c
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "三生塔");
	set("long", @LONG
三生塔是福严寺开山禅师慧思埋骨处，据说慧思禅师的三生均埋骨这
里，故称三生塔。不远处有棵银杏，据说曾受戒于慧思禅师，树龄千年，
仍亭亭华盖，岁岁青苍。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"jigaoming",
		"eastdown"  : __DIR__"fuyansi",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

