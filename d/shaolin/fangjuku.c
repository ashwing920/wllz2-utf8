// Room: /d/shaolin/fangjuku.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "防具库");
	set("long", @LONG
这是一间很大的房间，靠墙整齐地放着一个个大柜子，不少柜子门敞
开着，露出里面的各种防具，品种之多，是你生平仅见。一位灰衣僧人正
埋头整理一堆破损的护具。连你进来也没有注意。
LONG
);
	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

