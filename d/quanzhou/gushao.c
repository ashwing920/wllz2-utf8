// gushao.c 姑嫂塔
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "姑嫂塔");
	set("long", @LONG
姑嫂塔又名「关锁塔」，巍峨挺拔。登塔远望，则「手摩霄汉千山尽
，眼入沧溟百岛通」。相传古时有一张姓男子，抛妻别妹，远涉重洋，不
料海涂遇风，人舟尽沉。姑嫂俩登台远眺，日复一日，积思成疾，双双而
亡。后人建造此塔纪念二人。同时此塔也是泉州港重要的导航塔。西边是
安海港，北边则是永宁港。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"anhai",
		"north" : __DIR__"yongning",
	]));
	set("objects", ([
		__DIR__"npc/langren" : 1,
	]));
	set("outdoors", "quanzou");
	setup();
	replace_program(ROOM);
}
