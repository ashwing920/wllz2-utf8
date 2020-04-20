//ROOM liangunshi.c

inherit ROOM;

void create()
{
	set("short", "棍窠");
	set("long",@LONG
这里是玄兵古洞造棍的地方。周围整齐的堆放着造棍用的原料，一个
年轻小伙手里拿着一本玄天棍法，正在仔细的研读着。看到你走了过来，
连忙放下手中的书，带着一脸纯真冲你憨憨的一笑，脸不由又红了。
LONG
);
	set("exits", ([
		"east" : "/d/xueshan/shenghu",
	]));

	set("objects",([
		__DIR__"npc/shigun" : 1,
	]));

	setup();
	replace_program(ROOM);
}
