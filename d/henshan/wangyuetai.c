// Room: /d/henshan/wangyuetai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "望月台");
	set("long", @LONG
望月台是祝融殿后一高耸巨石。每当夜籁，皓月当空，犹如玉盘冰轮
，漫洒万里清辉，清冷月色，辉映低昂的群峰。此时浩然万里，举七十二
峰，峰峰贮冰壶中，始信下方无此月也。前人因此有诗: 人间朗魄已皆尽
，此地清光犹未低。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southup"	: __DIR__"zhurongdian",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

