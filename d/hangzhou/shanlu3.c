// shanlu3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
小溪横过山路，跨溪有一座小石桥。溪边农家小孩在嬉戏玩乐。南上
便到了上天竺。北下就是中天竺。
LONG
);
	set("exits", ([
		"southup"   : __DIR__"faxisi",
		"northdown" : __DIR__"fajinsi",
	]));
	set("objects", ([
		"/d/center/npc/boy" : 3,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
