//Room: /d/dali/yanchi2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","沿池堤岸");
	set("long",@LONG
滇池风景怡人，沿堤岸漫步，遵堤行湖中，堤南北皆碧水。盖其碧波
即草海之余，南连于滇池，北抵黄土坡，西濒与赤鼻山之簏。东行湖中，
遥顾四周山色，掩映重波间，青蒲偃水，高柳潆堤，天然绝胜。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"westdown" : __DIR__"yanchi1",
		"east"	 : __DIR__"yanchi3",
	]));
	setup();
	replace_program(ROOM);
}

