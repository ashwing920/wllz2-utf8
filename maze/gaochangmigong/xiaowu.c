//main1.c
// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","洞窟小屋");
	set("long",@LONG
你来到洞窟中的一间小屋，整间小屋都是黄土堆砌而成，屋子正中有
一张桌子，桌子两边各有两张石椅。
LONG);
	set("outdoors","gaochangmigong");
	set("exits",([
		"south": __DIR__"level2/exit",
	]));
	replace_program(ROOM);
}
