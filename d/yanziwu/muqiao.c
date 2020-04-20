
inherit ROOM;

void create()
{
	set("short","木桥");
	set("long",@LONG
这是通往湖中小亭的木桥，从这望去湖面碧波荡漾，景色宜人。木桥
的扶手上雕刻着一尊尊小木头狮子，让人爱不释手。木桥往西面走能够看
到一座湖中小亭。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"east" : __DIR__"houyuan1",
		"west" : __DIR__"bishuiting",
	]));
	setup();
	replace_program(ROOM);
}
