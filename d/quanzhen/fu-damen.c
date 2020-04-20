// fu-damen 富家大门
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "富家大门");
	set("long", @LONG
这里是武功镇上首富--侯员外家的大门，门上挂着一块大横匾，上面
写着‘侯府’两个大字。门内立着一面朱红的影壁，模模糊糊好象题着一
些诗句之类的东西。几个横眉立眼的家丁正挺胸凸肚地站在门口耀武扬威
，看来这是一家为富不仁的乡绅列霸。
LONG
);
	set("exits", ([
		"north" : __DIR__"dongjie",
		"south" : __DIR__"fu-xiaoyuan",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 3,
	]));

	setup();
	replace_program(ROOM);
}
