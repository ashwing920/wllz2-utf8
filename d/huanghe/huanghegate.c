// Room: /huanghe/huanghegate.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河帮寨门");
	set("long", @LONG
这是一所气势壮观的寨门，正中高挂着一面扁额—写着「黄河帮」三
个大字。寨里旗帜高挂，规模不小。黄河帮是黄河沿岸的一个大帮会，平
日飞扬跋扈，欺压百姓，做恶多端。帮主沙通天武功深湛，并与彭连虎、
梁子翁和灵智上人等高手结交，因此声势浩大。据闻其与金人勾结，欲侵
略中土。
LONG
);
	set("exits", ([
		"east"  : __DIR__"huanghe1",
		"west"  : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/ma" : 1,
		__DIR__"npc/shen" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

