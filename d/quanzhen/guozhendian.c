// guozhendian.c 过真殿
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "过真殿");
	set("long", @LONG
这里是大堂旁边的一个侧殿，也是接待重要客人的地方。殿不大，只
摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆景，墙壁上挂
着一些字画。从这里往北，好象有一座四层的小塔。
LONG
);
	set("exits", ([
		"south" : __DIR__"datang3",
		"west" : __DIR__"cetang",
		"north" : __DIR__"cundaota1",
	]));
	setup();
	replace_program(ROOM);
}
