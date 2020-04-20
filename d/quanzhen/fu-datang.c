// fu-datang 富家大堂
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "富家大堂");
	set("long", @LONG
这里是侯员外家的大堂，堂梁上挂着一块匾(bian)。堂内摆放着一些
八仙桌和椅子，堂壁上梅兰竹菊的竹帘被挂成了兰竹菊梅，看来这家也不
过是附庸风雅的暴发户而已。
LONG
);
	set("exits", ([
		"east" : __DIR__"fu-ceting",
		"west" : __DIR__"fu-zhangfang",
		"north" : __DIR__"fu-xiaoyuan",
		"south" : __DIR__"fu-houyuan",
	]));
	set("item_desc", ([
	   "bian": @TEXT
＃＃＃＃＃＃＃＃＃＃＃＃＃
＃＃　　　　　　　　　＃＃
＃＃　忠　义　传　疽　＃＃
＃＃　　　　　　　　　＃＃
＃＃＃＃＃＃＃＃＃＃＃＃＃
TEXT
	]) );
	setup();
	replace_program(ROOM);
}
