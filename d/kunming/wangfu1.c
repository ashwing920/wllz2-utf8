// /d/kunming/wangfu1

inherit ROOM;

void create()
{
	set("short","王府大院");
	set("long", @LONG
这里便是平西王府的大院，院内钟满了各钟花草，最显眼的却是中间
的一株万年山茶，巨大的树干上开满了无数的山茶花，颜色深浅不一，姹
紫嫣红，十分好看。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south"    :__DIR__"wangfu",
		"north"   :__DIR__"wangfu2",
		"west"   :__DIR__"xizoulang",
		"east"   :__DIR__"dongzoulang"
	]));
	setup();
	replace_program(ROOM);	       
}
			