
inherit ROOM;

void create()
{
	set("short", "魁星楼三楼");
	set("long", @LONG
这是魁星楼的最高处，虽然只有三楼，极目望去，十里平湖，点点翠
绿，尽收眼底。清风徐拂，头上是郎郎晴空。站在这儿，深吸一口气，不
禁就要溶入这悠悠美景中。
LONG
);
	set("exits", ([
		"down" : __DIR__"kuixinlou2"
	]));
	setup();
	replace_program(ROOM);
}
