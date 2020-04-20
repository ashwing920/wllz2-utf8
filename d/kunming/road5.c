// /d/kunming/road5

inherit ROOM;

void create()
{
	set("short","长江北岸");
	set("long", @LONG
你来到了长江北岸，只见波涛滚滚，滔滔江水向东流去。岸边立有一
块碑(bei),前面不远处有座独木桥。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south" : __DIR__"qiao", 
		"northup"  :__DIR__"road4",
	]));

	set("item_desc", ([
		"bei" :@TEXT

一块石碑，上面写着：

**************** 
* 河   天   通 *
****************
	
TEXT
	]));
	setup();

}
int valid_leave(object me, string dir)
{
	if ( dir == "south" || dir == "northup" ) {
		me->delete_temp("dirs"); me->delete_temp("dirs1");
	}
	if (dir == "south") me->set_temp("dirs2",1);
	return ::valid_leave(me, dir);
}