//guanwai/ningyuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "宁远");
	set("long", @LONG
这里是关外驻防的军事重镇。城高河宽，守备森严，城楼上不但有大
量的官兵驻防，甚至还有几门红衣火炮，架设其上。城门旁几名官兵正在
检察来往行人的物品，不时传来几声叱骂之声。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"road4",
		"south"	 : __DIR__"road3",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

