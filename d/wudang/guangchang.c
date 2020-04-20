//Room: guangchang.c 武当广场
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","武当广场");
	set("long",@LONG
这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地
点。周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童
正在打扫。南边是灵霄宫三清殿。
LONG
);
	set("objects", ([
		CLASS_D("wudang") +"/daotong": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
		"northdown"  : __DIR__"zixiaogate",
		"south"         : __DIR__"sanqingdian",
		"eastdown"   : __DIR__"tyroad1",
		"east"           : __DIR__"shanlu2",
	]));
	set("outdoors", "wudang");
	setup();
}
