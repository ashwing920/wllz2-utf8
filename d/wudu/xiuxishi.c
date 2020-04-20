// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","休息室");
	set("long", @LONG
这里是五毒弟子们休息的地方，空空的房间摆了一张通铺，看样子可
以睡几十人，几个弟子正在床上熟睡，你不由也有了阵阵的困意。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"zoulang",
	]));
	setup();
	replace_program(ROOM);
}
