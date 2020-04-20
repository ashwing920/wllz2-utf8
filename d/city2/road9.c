//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商的
、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两
三骑快马从身边飞驰而过，扬起一路尘埃。马上的人个个身着劲装，衣甲
鲜明，有的还随身佩带着刀剑。看来都是些些习武的江湖人。道路两旁是
整整齐齐的杨树林。
LONG
);
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : __DIR__"road10",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
	]));

	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



