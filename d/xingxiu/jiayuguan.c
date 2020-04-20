// Room: /d/xingxiu/jiayuguan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "嘉峪关");
	set("long", @LONG
这是长城最西的关隘。岁月沧桑，仍掩不住它的风采。群山环抱之下
，更显它的雄浑。由于西域安定，久无战事，边关守军已大为减少。一条
大道向东延伸通向中原。出关向西，便是著名的“丝绸之路”。
LONG
);
	set("outdoors", "xingxiuhai");
	set("exits", ([
		"eastup" : __DIR__"xxroad3.c",
		"west" : __DIR__"silk1.c",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

