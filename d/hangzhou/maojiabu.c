// maojiabu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "茅家埠");
	set("long", @LONG
路两旁盖着几座小土房。房门口一位老大娘正在喂鸡，几个小孩正在
追逐嬉戏。北边是上黄泥岭。南面是丁疽山。
LONG
);
	set("exits", ([
		"southwest"   : __DIR__"tulu1",
		"northup"	 : __DIR__"huangniling",
	]));
	set("objects", ([
		"/d/center/npc/boy" : 2,
		__DIR__"npc/oldwoman" : 1,
		__DIR__"npc/camel" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
