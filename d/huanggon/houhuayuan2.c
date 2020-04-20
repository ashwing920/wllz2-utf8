// houhuayuan2.c 后花苑
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "后花苑");
	set("long", @LONG
这里是皇上赏花的后花苑。平日里皇上时常会来这儿，和贵妃娘娘一
起赏花品茗。所以，这儿是平常太监，侍卫不能来的。这里的宫女多是心
灵手巧，精通花道的。放眼四顾，满目皆是似锦繁花，你仔细分辨，竟然
品目齐全，大凡你想得的，甚至你想都不敢想的，这里都有了。你不经有
些妒疾起皇帝老儿来。
LONG
);
	set("outdoors", "huanggon");
	set("exits", ([
		"east" : __DIR__"houhuayuan",
		"west" : __DIR__"majuan.c",
	]) );
	set("objects", ([
		__DIR__"npc/gonnv" : 2,
	]) );
	setup();
	replace_program(ROOM);
}
