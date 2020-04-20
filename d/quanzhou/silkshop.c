// silkshop.c 鸿翔绸缎庄

inherit ROOM;

void create()
{
	set("short", "鸿翔绸缎庄");
	set("long", @LONG
这就是天下闻名的丝绸销售中心，古色古香的店面，门上挂干飘着一
面质地上好的绸面，绣着红色的「鸿翔绸缎」四个大字。中原来的上等丝
绸在此加工后源源不断的运往西洋各国。庄内各式花色和质地的绸缎应有
尽有，琳琅满目。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"jiedao1",
	]));
	set("objects", ([
		__DIR__"npc/xu" : 1,
		__DIR__"npc/ss_huoji" : 1,
	]));
	setup();
}
