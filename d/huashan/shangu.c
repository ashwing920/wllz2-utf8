// Room: /d/huashan/shangu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
这里是中条山的一个隐秘山谷。四周是高可及天的山峰，云深林密，
一径小溪潺潺流过，溅入坡下塘中。溪畔有一汉子舞剑正酣。不打扰的为
妙。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"jzroad7",
		"south"	 : __DIR__"pingdi",
	]));
	set("objects", ([
		CLASS_D("huashan")+"/cong-buqi": 1,
	]));
	set("outdoors", "xx");
	setup();
	replace_program(ROOM);
}

