// Room: /d/shaolin/fanting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

string* names = ({
	__DIR__"obj/mala-doufu",
	__DIR__"obj/bocai-fentiao",
	__DIR__"obj/shanhu-baicai",
	__DIR__"obj/liuli-qiezi",
});

void create()
{
	set("short", "斋厅");
	set("long", @LONG
这里便是少林全寺寺僧用斋的地方。斋厅极大，足可容纳上千人同时
进餐。从东到西一排排摆满了长长的餐桌和长凳，几位小和尚正来回忙碌
着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。
LONG
);
	set("exits", ([
		"east" : __DIR__"guangchang3",
		"north" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
	setup();
	replace_program(ROOM);
}