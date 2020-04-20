// gushan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "孤山");
	set("long", @LONG
通过林荫道向前，迎面石壁上刻有“孤山”两个丹红大字。朝南拾级
登山便是平台。东北边便是发鹤亭。东南边则是平湖秋月。西北边通往西
泠桥。
LONG
);
	set("exits", ([
		"westup"	: "/d/meizhuang/shijie",
		"east"	  : __DIR__"pinghuqiuyue",
		"southup"   : __DIR__"gushanpingtai",
		"northwest" : __DIR__"xilingqiao",
		"northeast" : __DIR__"fangheting",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
