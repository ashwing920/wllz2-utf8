// Room: /d/shaolin/duchuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长
竹篙，正在船尾吃力地撑着船。
LONG
);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

