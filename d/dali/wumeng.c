//Room: /d/dali/wumeng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","乌蒙村落");
	set("long",@LONG
这里是山的缓坡，乌夷人搬石去土，把这里修成一层层阶梯状的平台
，民居分别建在各处平台上，互不连接，各自有石砌围墙，村中道路也由
石头铺成。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"west"	: __DIR__"wunong",
		"east"	: __DIR__"caopo",
		"north"   : __DIR__"wuyiminju1",
		"south"   : __DIR__"wuyiminju2",
	]));
	setup();
	replace_program(ROOM);
}

