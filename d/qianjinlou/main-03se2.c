// main-03se2.c - 千金楼（湖边）

inherit ROOM;

void create()
{
	set("short", "湖边");
	set("long", @LONG
这里是藕香榭旁的湖边，站在这里，望着清澈见底的湖水，让人倍感
舒爽。湖边有几块形状怪异的大石，有的象飞鸟，有的象野兽，有的更象
人形，十分好看。几个女子正在湖边上徘徊，把这里衬托得更加美丽。
LONG
);
	set("outdoors", "qianjinlou");
	set("exits", ([
		"west"   : __DIR__"main-03se1",
		"east"   : __DIR__"main-03se3",
		"north"  : __DIR__"main-04",
	]));
	set("objects",([
		__DIR__"npc/mingji-d":1,
		__DIR__"npc/yahuan":2,
	]));
	setup();
	replace_program(ROOM);
}