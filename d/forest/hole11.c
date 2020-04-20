// /d/kunming/pubu

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","别有洞天");
	set("long", @LONG
这是一个十分宽敞的洞庭，抬头向上望去，四五个人高的洞顶上，依
稀的滴下几滴水珠，洞庭的地面三五步就有一摊水渍，想必就是洞顶上的
水珠滴下堆积而成。洞庭之中，有一张石床，依稀的铺着一些干枯的野草
。洞中的环境，想必在此居住肯定是室外高人。
LONG
);
	set("exits",([
		"east": __DIR__"hole_ne/exit",
	]));
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_bo","bo");
}
int do_jump(string arg)
{
	object me = this_player();

	if(!arg || arg == "") return 0;

	if(arg == "床" || arg == "石床" || arg == "bed"){
		if(me->query_temp("jump_bed")){
			message_vision("$N站在石床上跳来跳去，十分滑稽。\n",me);
			return 1;
		}
		message_vision("$N跳到石床上。\n",me);
		me->set_temp("jump_bed",1);
		return 1;
	}
	else if( arg == "down"){
		if(!me->query_temp("jump_bed")){
			message_vision("$N站在山洞里跳来跳去，十分滑稽。\n",me);
			return 1;
		}
		message_vision("$N从床上跳了下来。\n",me);
		me->delete_temp("jump_bed");
		return 1;
	}
}
int do_bo(string arg)
{
	object me,obj;
	me = this_player();
	
	if(!arg || arg == "" || !me->query_temp("jump_bed")) return 0;
	if( arg == "草" || arg == "野草" || arg =="cao"){
		if(objectp(obj = find_object("/d/forest/obj/stone_white"))
		|| query("boed"))
			return notify_fail("野草已经被拨开了。\n");
		message_vision("$N拨开石床上的野草，发现了一块晶莹剔透的白色玉片。\n",me);
		obj = new(__DIR__"obj/stone_white");
		obj->move(me);
		set("boed",1);
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s拿到了传说中的%s了！",me->name(),obj->name()+HIM));
		return 1;
	}	
}
		
int valid_leave(object me,string dir)
{
        if((int)me->query_temp("jump_bed"))
        	return notify_fail("你不从床上下来想走哪去？\n");
        return ::valid_leave(me, dir);
}
void reset()
{
	object inv;
	foreach (inv in all_inventory()){
		if(userp(inv)) return;
	}
	delete("boed");
}
