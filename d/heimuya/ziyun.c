// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "紫云崖");
	set("long", @LONG
此处奇景又是一绝，崖岭弯曲回转，东方红日露出云层半截一映，满
天云雾霎时紫色一片，外深内淡，仿佛这崖边的云彩原本就是紫色。
LONG
);
	set("exits",([
		"east" : __DIR__"taohua",
		"west" : __DIR__"wulao",
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
