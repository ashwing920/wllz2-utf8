// chufang.c 铸造室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "铸造室");
	set("long", @LONG
这里是血刀门的血刀铸造室，红红的炉火在怒吼着，到处一片片打铁
的声音，墙上挂着一块牌子(paizi)，墙边扔着一把铁锤。
LONG
);
	set("exits",([
		"west" : __DIR__"lwchang1",
	]));
	set("objects" , ([
		__DIR__"npc/daoshi" : 1,
	]));

	setup();
}
