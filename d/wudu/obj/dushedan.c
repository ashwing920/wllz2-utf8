// 五毒教蛇胆 shedang 

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("蛇胆", ({"she dan", "dan"}));
        set("unit", "只");
	set("long", "这是一只毒蛇胆。\n");
	set("value", 100);
        setup();
}

int do_use(string arg)
{	object me=this_player();
	int jing_cost,qi_cost;
	jing_cost= 200/(int)me->query_int();
	qi_cost= 500/(int)me->query_int();
	if (!id(arg))
                return notify_fail("你要吃什么？\n");
	if ((int)me->query_skill("wudu-xinfa",1) < 20)
	return notify_fail("你的五毒心法太低了！\n");
	message_vision("$N吃下一个毒蛇胆！\n",me);
	message("vision",me->name()+"盘腿坐下开始运功\n",environment(me), ({me}));
	tell_object(me,"只觉得毒气供心，赶快坐下运功驱毒！\n");
	 if ( me->query("jing") < jing_cost || me->query("qi") < qi_cost)
	  { destruct(me); return 1;}
	 me->receive_damage("jing", jing_cost );
         me->receive_damage("qi", qi_cost );
	 me->start_busy(2);
	 message("vision","过了一会"+me->name()+"若无其事的站了起来。\n",environment(me), ({me}));
	 tell_object(me,"你觉得毒气一点点散去，最后化为虚无，你若无其事的站了起来。\n"+
			"似乎对五毒心法又有了点心得！");
	 me->improve_skill("wudu-xinfa", 2*(int)me->query_skill("wudu-xinfa", 1));
	 destruct(this_object()); 
	 return 1;        
}

