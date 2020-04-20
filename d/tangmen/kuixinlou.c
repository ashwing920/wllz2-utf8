
inherit ROOM;

void create()
{
	set("short", "魁星楼");
	set("long", @LONG
这里是藕香湖的南端，矗立着高大的魁星楼。魁星乃是天上专门管理
文运的神。唐门文风历代很盛，所以楼中塑有魁星像。楼分三层，如果上
得第三层，便可总整个藕香湖的美景。进得魁星楼，迎面便是左手书，右
手笔，神情威猛的魁星。往上是红木扶梯，可以到第二层。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"qulang6",
		"south" : __DIR__"huayuan10",
		"up" : __DIR__"kuixinlou2",
	]));
	setup();
	replace_program(ROOM);
}

