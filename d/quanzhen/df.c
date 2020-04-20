//danfang.c 炼丹房
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create ()
{
	set ("short", "炼丹房");
	set ("long", @LONG
这里是全真教配药炼丹的地方，屋子正中放了一只炼药炉，一个小道
童正不停的加药、鼓火、添水，炉中不停的冒出腾腾水雾，并散发着浓浓
的药气，在丹房的另一头还有一个小门(door)。在小门的两边还挂着一幅
楹联(lian),这儿是全真教的重地，外人轻易是不能进来
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"yaojishi",
	]));
	set("item_desc", ([ /* sizeof() == 2 */
		"door" : "一忘扇紧闭的小门。 ",
		"lian" : @TEXT $MAG$
	斗                    龙
	室                    泉
	能                    飞
	观                    舞
	天                    振
	下                    八
	事                    荒
$NOR$
TEXT
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("quanzhen")+"/tianxu" : 1,
	]));

	setup();
  
}

