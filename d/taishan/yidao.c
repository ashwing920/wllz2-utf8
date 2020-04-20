// Room: /d/shaolin/yidao.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶
着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑
快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。
LONG
);
	set("exits", ([
		"west" : "/d/city/dongmen",
		"east" : __DIR__"yidao1",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 3,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

