//jiudian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short", "酒店");
	set("long",@LONG
这里是一家独具特色的酒店，由于地处『白驼山』下，酒店可以供应
风味食品－－蛇肉。许多中原来客都爱来尝尝鲜，所以酒店生意兴隆。酒
店还经营打散装酒的业务。
LONG
);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}





