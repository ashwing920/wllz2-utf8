// Room: /d/huashan/jzroad5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "密林深处的空地");
	set("long", @LONG
不知不觉，你来到密林深处的空地当中，只见空地上放着一张长石桌
，石桌后有一张石椅。这里虽然是郊外，却是收拾的整齐妥当，显然平时
经常有人到这里打扫，收拾。
LONG
);
	set("exits", ([
		"west":	__DIR__"jzroad5",
	]));
	set("objects",([
		__DIR__"npc/shanzei": 25,
		__DIR__"npc/shanzeitouzi":1,
	]));
	setup();
}
