// bank.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "聚宝钱庄");
	set("long", @LONG
这里是桃源城的聚宝钱庄。这是一间素来以公平信用著称的钱庄。它
是一家老字号的钱庄，已有很多年的历史，在全国各地都有分店。据说，
钱庄的老板还是个曾经做过大官的人。你可以看到钱庄里里外外都打扫得
乾乾净净，一个胖胖的年轻人坐在柜台後面，柜台上放著一块牌子(sign)。
LONG
);

	set("exits", ([ 
		"east"  : __DIR__"roads1",
		"north" : __DIR__"roadw1",
		"up": __DIR__"bank_lv2",
	]));

	set("item_desc", ([
		"sign": @TEXT
$CYN$这里是钱庄，目前我们提供的服务有：
$MAG$
convert         兑换钱币
withdraw        提取存款
deposit         存入钱币
check           察寻存款
$NOR$
TEXT
	]) );
	set("objects", ([
		__DIR__"npc/banker": 1,
	]) );
	set("no_fight",1);
	set("no_beg",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
