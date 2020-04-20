
inherit ROOM;

void create()
{
	set("short","后院");
	set("long",@LONG
穿过一个半月形的拱门, 你来到一座小楼之前。小楼檐下一块匾额,
写着：“$HIG$云锦楼$NOR$”三个墨绿毫字, 楼下前后左右种的都是茶花。但这些茶
花都不过是三四流货色, 和这精致的楼阁亭榭相比, 未免不衬。左右面是
一条长廊，南面是云锦楼。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"south" : __DIR__"yunjinlou",
		"west" : __DIR__"c13",
		"east" : __DIR__"c14-2",
		"north" : __DIR__"xiaojing8",
	]));
	setup();
	replace_program(ROOM);
}
