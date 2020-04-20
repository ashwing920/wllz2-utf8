// alabo.c 阿拉伯宅区
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "阿拉伯宅区");
	set("long", @LONG
由于泉州与世界的商贸往来，许多阿拉伯人来到此地居住和劳作，久
而久之形成了这聚居地。远远望去白色的圆形尖顶突兀而起，显得格外抢
眼。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"citong_s2",
		"south" : __DIR__"qingjing",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
