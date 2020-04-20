// Room: /d/suzhou/sunwuting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "孙武亭");
	set("long", @LONG
在真娘幕后的土丘上，有一座小亭子，名为孙武亭。相传春秋时，兵
家孙武曾在此训练两队宫女，由吴王的两个宠姬分别担任队长，由于宠姬
与宫女们不听军令，虽三令五申，仍置若罔闻，孙武遂下令，先斩两姬于
军前以整军纪。后人遂筑此亭。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"south"  : __DIR__"zhenniang",
	]));
	setup();
	replace_program(ROOM);
}

