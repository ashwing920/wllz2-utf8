//fanting1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "斋厅");
	set("long", @LONG
这里便是少林全寺寺僧用斋的地方。斋厅极大，足可容纳上千人同时
进膳。从东到西一排排摆满了长长的餐桌和长凳，几位小和尚正来回忙碌
着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。北面
是个厨房。
LONG
);
	set("exits", ([
		"south" : __DIR__"fanting",
		"north" : __DIR__"chufang",
	]));
	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		__DIR__"obj/mizhi-tianou": 1,
		__DIR__"obj/jiaxin-biji": 1,
		__DIR__"obj/basi-shanyao": 1,
		__DIR__"obj/furong-huagu": 1,		
	]));

	setup();

}

