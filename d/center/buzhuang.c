// buzhuang.c - 布  庄
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;
void create()
{
	set("short", "桃源布庄");
	set("long", @LONG
这里是桃源城的布庄，到处放满了各式各样的布匹。一个肥头大耳的
老板笑嘻嘻地招呼着顾客，和气生财是他的口头禅。伙计殷勤地向你介绍
每钟布料的优点，让你不忍心拒绝。旁边挂着一块牌子(sign)，上面好象
写着什么。
LONG
);
	set("exits", ([
		"east"  : __DIR__"roads4",
		"south": __DIR__"houtang",
	]));
	set("item_desc",([
		"sign": @TEXT
$CYN$
　　本店招收临时工协助布庄进行（$HIG$tang 布匹$NOR$$CYN$）工作，有意者可与本庄老
板($HIG$ask yang about job$NOR$$CYN$)联系。

						桃源布庄
$NOR$
TEXT	]));
	set("objects", ([
		__DIR__"npc/seller-bz" : 1,
	]));
	setup();
	replace_program(ROOM);
}