// Room: /d/henshan/mojingtai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "磨镜台");
	set("long", @LONG
磨镜台位于燕子岩下，与半山亭一沟相邻。台前峰回路转，台旁古松
苍翠，环境清幽。相传南宗禅宗怀让在此宣扬顿悟法门，坐台高僧斗法，
怀让磨镜，智服北宗道一，此台因而传名。磨镜台之幽是衡山大四绝之一。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown"  : __DIR__"shanlu8",
		"westup"	 : __DIR__"shanlu7",
		"northup"	: __DIR__"shanlu6",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

