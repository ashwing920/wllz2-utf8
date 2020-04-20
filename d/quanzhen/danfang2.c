// Room: /d/quanzhen/danfang2
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create ()
{
	set ("short", "炼丹房");
	set ("long", @LONG
这里是全真教配药炼丹的地方，屋子正中放了一只炼药炉，一个小道
童正不停的加药、鼓火、添水，炉中不停的冒出腾腾水雾，并散发着浓浓
的药气，在丹房的另一头还有一个小门(men)。       
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"danfang1",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"men" : "一扇紧着的竹门。",
	]));
	setup();
	replace_program(ROOM);
}