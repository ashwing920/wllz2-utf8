
inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是一大片花园。唐门地处蜀南，占地广阔，气候适宜花草生长。加
上唐门弟练功之余，皆喜欢侍弄花草，所以整个花园品种繁多，终年花团
锦簇，非常漂亮。花从中很多罕见珍贵的花草，不单可以让人欣赏玩味，
还有不少妙用。
LONG
);
	set("outdoors", "tangmen");
	set("exits", ([
		"east" : __DIR__ "huayuan2",
		"west" : __DIR__ "huayuan4",
	]));
	setup();
	replace_program(ROOM);
}

