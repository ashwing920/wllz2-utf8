//wuguan-3.c
//Design By 蝴蝶君 Email:Robert_st@263.net 

inherit ROOM;

void create()
{

	set("short","兵器库");
	set("long",@LONG
这里是枫林武馆的兵器库，兵器库东西两边各有一个兵器架，上面整
齐的放着一些兵器，竹棒，长剑，木刀等应有尽有，是枫林武馆提供
给弟子们练功用的一些基本兵器。
LONG
);

	set("outdoors","taoyuan");
	set("exits",([
		"north":__DIR__"wuguan-2",
	]));
	set("objects",([
		"/clone/weapon/sword": 2,
		"/clone/weapon/zhujian":2,
	]));
	setup();

}