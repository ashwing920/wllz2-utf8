// xiqiao.c 西门吊桥

inherit ROOM;

void create()
{
	set("short", "西门吊桥");
	set("long", @LONG
这是泉州西面的一座吊桥，从傍着晋河而建的城楼大门上以两个滑轮
维系。日出放下吊，日落绞起。过了桥向西南走可达岭南广东。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"citong_w2",
                "west" : "/d/foshan/road14",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
