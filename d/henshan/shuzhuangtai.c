// Room: /d/henshan/shuzhuangtai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "梳妆台");
	set("long", @LONG
藏经殿有一泓碧泉如镜，向称美容泉。相传为南陈后主妃在此避乱时
，对碧水照容颜梳妆打扮的地方。殿前胜迹有灵日，昔时夜间常见飞光，
或如繁星点点，或若万萤乱飞，煞是壮观。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north"   : __DIR__"cangjingdian",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

