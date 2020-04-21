// Room: /d/shaolin/wuqiku.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
少林寺的武器库可称天下第一，十八般兵器，这里可谓应有尽有。四
面一望，令你顿感眼花缭乱。墙上砌了一个个小格子，每个都插满了各种
各样的兵器。墙角一个健壮的僧人正乒乒乓乓地在打造一根禅杖。另一位
灰衣僧人正在墙角拂拭一把戒刀。看到你进来，他缓缓起身，向你迎了过
来。
LONG
);
	set("exits", ([
		"west" : __DIR__"zhulin2",
		"north" : __DIR__"fangjuku",
	]));

	create_door("west","木门","east",DOOR_CLOSED);
	set("objects",([
		CLASS_D("shaolin") + "/dao-chen" : 1,
		__DIR__"npc/datie-seng" : 1,
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
