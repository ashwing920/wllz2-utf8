//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: chunyangdian.c 纯阳殿

inherit ROOM;

void create()
{
	set("short","纯阳殿");
	set("long",@LONG
纯阳殿海拔一千余米，四面古木苍翠，幽静宜人。殿前有一石，叫普
贤石，据说普贤菩萨登山时曾坐在这里休息过。在此可纵观峨嵋诸峰，仰
望金顶，悬崖峭壁，离天咫尺。这里西上至神水庵，东下是归云阁。
LONG
);
	set("exits",([
		"eastdown"  : __DIR__"guiyunge",
		"westup"	: __DIR__"shenshuian",
	]));
	set("outdoors", "emei");

	setup();
	replace_program(ROOM);
}
