// houtang.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","后堂");
	set("long",@LONG
这里是布庄的后堂，后堂靠边的墙上，堆满了存货的一些布匹。由于
后堂比较潮湿，布匹摸上去上去有些湿漉漉的感觉。几个伙计正在旁用熨
斗，将布匹铺平熨(tang)干。
LONG);

        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"buzhuang",
	]));
	setup();
}
void init()
{
	add_action("do_tang","tang");
}
int do_tang(string arg)
{
	object me=this_player();

	if(!me->query_temp("gongzuo/yunbu"))
		return notify_fail("你现在没有熨布的工作。\n");

	if(!arg || arg != "布匹")
		return notify_fail("你要熨烫什么？\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->query_temp("working"))
		return notify_fail("你正在工作中呢。\n");

	if((int)me->query("jing") < 30)
		return notify_fail("你太累了，休息一下再做吧。\n");

	if(me->query_temp("gongzuo/finish"))
		return notify_fail("布匹已经熨好了，快把熨好的布交回去吧！\n");

	message_vision("$N拿起熨斗，慢慢地在布匹上来回移动 . . . \n",me);
	me->add("jing",-10);
	me->add_temp("gongzuo/times",1);
	me->set_temp("working",1);
	call_out("finish_tang",1,me);
	return 1;
}
private void finish_tang(object me)
{
	object ob;

	if(!me || environment(me) != this_object()) return;

	me->delete_temp("working");

	if(me->query_temp("gongzuo/times") > 15 + random(10)){
		message_vision("布匹在熨烫下逐渐平整，$N将布匹叠好后放在一边。\n",me);
		ob=new("/d/center/obj/bu");
		ob->set_temp("work_by",me);
		ob->move(me);
		me->set_temp("gongzuo/finish",1);
		return;
	}
	if(random(10)>7){
		message_vision(RED"$N在蒸气缭绕之中逐渐开始漫不经心，只听得“哧”的一声$N的手被熨斗碰了一下。\n"NOR,me);
		me->receive_damage("qi",10);
		me->delete_temp("last_damage_from");
	}
	else {
		message_vision("只见布匹上冒了出一道白色的蒸气，显得平整了许多。\n",me);
	}
	return;
}
int valid_leave(object me,string dir)
{
	if ( me->query_temp("working") )
		return notify_fail("你的工作还没做完呢！\n" );
	return ::valid_leave(me, dir);
}
