inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道一路向下，两旁点着几盏油灯，昏灯如豆，一片阴沉沉地，而且
地道又弯弯曲曲，转得人头昏眼花。
LONG
);
	set("exits",([
		"down" : __DIR__"xiaohuayuan",
		"up" : __DIR__"dadian",
	]));
	setup();
	replace_program(ROOM);
}
