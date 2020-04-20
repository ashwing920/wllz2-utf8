
inherit ROOM;

void create()
{
	set("short", "画舫");
	set("long", @LONG
一座画舫，是唐门平时接送弟子出入的工具，有时也用来游湖。舫上
的雕花护栏、蜀绣窗帘皆是精美之物。撑船的是个二十几岁的姑娘--唐门
弟子唐菱，看起来很柔弱，臂力却是惊人。在她的掌握下，画舫飞快得向
湖心驶去。
LONG
);
	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}



