// pubu.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short", "瀑布");
	set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见
一条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾
弥漫，望不到尽头……
LONG
);
	set("exits", ([
		"east" : "/d/huashan/sheshen",
	]));
	set("outdoors", "xiaoyao" );

	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{

	object me;
	mapping fam;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg == "down" ){
		tell_object(me, HIR"你不加思索，纵身一跃，跳下了悬崖……\n"NOR);
		message("vision","只见" + me->query("name") + "万念俱灰，纵身跳入了悬崖之中……\n",environment(me),me);
		if(!mapp(fam = me->query("family")) || fam["family_name"] != "逍遥派"){
			if(random((int)me->query("kar")) < 15 && (int)me->query_skill("dodge",1) < random(50) + 30){
				me->die();
				return 1;
			}
			else{
				me->add("qi",-(int)me->query("qi") / 3 );
			}
		}
		me->move(__DIR__"yanfeng");
		return 1;
	}

}
