// Room: /d/shaolin/bagua0.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

#include "/d/shaolin/bagua.h"

void create()
{
	set("short", "八卦阵");
	set("long", @LONG
这是便是八卦阵，四壁全由粗糙的片岩垒垛而成。巨石狰狞，缺口及
合缝处犬牙交错，如洪荒怪兽，其势似欲择人而噬。壁上刻着一行小篆：
“八卦通天地，金刚泣鬼神”。四周灰尘厚积，蛛网密布，看来已久无人
行。地上似乎躺着几具尸体，早已腐烂化灰，脚步经过，连尸首身上的衣
物也随风飘散。
LONG
);
	set("exits", ([
		"乾" : __DIR__"bagua7",
		"巽" : __DIR__"bagua6",
		"离" : __DIR__"bagua5",
		"艮" : __DIR__"bagua4",
		"兑" : __DIR__"bagua3",
		"坎" : __DIR__"bagua2",
		"震" : __DIR__"bagua1",
		"坤" : __DIR__"bagua0",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (check_dirs(me, dir))
		return notify_fail("你踩动了机关，掉进僧监。\n");
	return ::valid_leave(me, dir);
}

