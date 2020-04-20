// Room: /d/gaibang/underbj.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "街边狗洞");
	set("long", @LONG
这是北京城一条偏僻街边的狗洞里。四周丢满了各种杂物，还有丐帮
弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
);
	set("exits", ([
		"out"   : "/d/city2/aobai1",
		"south" : __DIR__"bjandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/quan-gq" : 1,
	]));
	setup();
	replace_program(ROOM);
}

