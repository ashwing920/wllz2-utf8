// workroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "珊瑚楼阁");
	set("long", @LONG
这是神秘的海底世界，你的四周到处都是海底动物，围着你看热闹，
远处有一座金碧辉煌的宫殿，听说八爪鱼就住在宫殿里，宫殿守卫森严，
到处是虾兵蟹将，宫殿上面有一块金匾，上书：

		 　$HIR$〖珊瑚楼〗$NOR$

LONG
);
	set("exits",([
		"bmw":"/u/bmw/workroom",
		"robert":"/u/robert/workroom",
		"down":"/d/wizard/wizard_room",
	]));
	setup();
	replace_program(ROOM);
}
