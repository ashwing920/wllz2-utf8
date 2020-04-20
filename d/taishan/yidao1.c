// Room: /d/shaolin/yidao1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶
着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑
快马从身边飞驰而过，扬起一路尘埃。马上的人个个身着劲装，衣甲鲜明
，有的还随身佩带着刀剑。看来都是些些习武的江湖人。道路两旁是整整
齐齐的杨树林。
LONG
);
	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
		"southeast" : "/d/quanzhou/qzroad1",
	]));
	set("objects",([
		__DIR__"npc/tangzi" : 2,
		"/d/quanzhou/npc/hai" : 1,
		"/d/city/npc/xiaoguiz" : 1,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

