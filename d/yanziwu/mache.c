// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "马车");
	set("long", "一辆干净宽敞的马车,车夫坐在前面驾车。\n");
	setup();
	replace_program(ROOM);
}
