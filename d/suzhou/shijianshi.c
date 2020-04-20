// Room: /d/suzhou/shijianshi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "试剑石");
	set("long", @LONG
在山道东侧是试剑石，呈椭圆形，正中有条深而齐裂的裂缝，相传吴
王得“干将”，“莫邪”剑后，为试其锋利，将石劈开。石旁刻着元代顾
瑛的诗句“剑试一痕秋，崖倾水断流，如何百年后，不斩赵高头？”的诗
句。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"northeast" : __DIR__"zhenniang",
		"south"	 : __DIR__"qianrenshi",
		"north"	 : __DIR__"zhenshi",
		"westdown"  : __DIR__"wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	setup();
	replace_program(ROOM);
}

