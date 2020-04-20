// cunzhangjia.c 村长家
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "村长家");
	set("long", @LONG
这里是村长的家，堂屋里堆放着一些锄头、镰刀之类的农耕用具，有
一些是村中村民家里坏了，来央求村长给修的。屋檐前吊着数十串鲜红的
辣椒，还有一些风干的野味。
LONG
);
	set("exits", ([
		"south" : __DIR__"guchang",
	]));
	set("objects", ([
		__DIR__"npc/dibao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
