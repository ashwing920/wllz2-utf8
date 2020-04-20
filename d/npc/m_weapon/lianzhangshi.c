//ROOM lianzhangshi.c
inherit ROOM;

void create()
{
	set("short", "杖场");
	set("long",@LONG
这里是玄兵古洞的造杖的地方。四周道也不是十分荒凉，相反还可说
有几分景致。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，似乎什么都能
被它融化似的。
LONG
);
	set("exits", ([
		"eastup" : "/d/baituo/xiaolu4",
	]));

	set("objects",([
		__DIR__"npc/shizhang" :1,
	]));

	setup();
	replace_program(ROOM);
}
