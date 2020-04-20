//main1.c
// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","高昌迷宫");
	set("long",@LONG
你来到一个洞窟之前，只见洞窟门口堆满黄土，洞口有一个石碑，已
经被长年的黄土所覆盖，依稀的留下一些字迹(zi)。洞内一片漆黑，站在
这里根本无法看清楚洞里究竟有什么东西。
LONG);

	set("exits",([
		"north": __DIR__"level/entry",
		"out": "/d/lingjiu/shanjiao",
	]));
	set("item_desc",([
		"zi": "擅入高昌迷宫者－－必死！！\n",
	]));
}
