// eat.c
// Design By robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit F_CLEAN_UP;

#define DROP_CMD 	"/cmds/std/drop"

int main(object me, string arg)
{
	object obj;
	int avai,remain;
	
	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");

	if(!arg) 
		return notify_fail("你要吃什么东西？\n");

	if(!objectp(obj = present(arg, me)) ){
		if(objectp(obj = present(arg, environment(me))) && !obj->is_character() )
		tell_room(environment(me), me->name() + "盯着地上的"+obj->name() + "，咽了一口唾沫。\n",({ me }));
		return notify_fail("你身上没有这样东西。\n");
	}
	if(!obj->query("food_supply") )
		return notify_fail("看清楚点，这东西能吃吗？\n");
	if(!obj->query("food_remaining") ){
		write(obj->name() + "已经没什么好吃的了。\n");
		if( me->query("env/drop_food")) DROP_CMD->do_main(me,obj->query("id"));
		return 1;
	}
	if((int)me->query("food") >= me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
		
	remain = (int)obj->query("food_remaining") * (int)obj->query("food_supply");
	avai = (int)me->max_food_capacity() - (int)me->query("food");

	if( remain > avai ){
		me->add("food", avai);
		obj->add("food_remaining", - ( avai / (int)obj->query("food_supply")));
		obj->set("value", 0);
	}
	
	else
	{
		me->add("food",remain);
		obj->set("food_remaining", 0);
		obj->set("value", 0);
	}

	if( obj->query("eat_func") ) return 1;
	if( !obj ) return 1;
    

	if((int)obj->query("food_busy"))
		me->start_busy(obj->query("food_busy"));
	    
	if( !obj->query("food_remaining") ) {
		obj->delete_temp("apply/long");

	if((string)obj->query("finish_msg"))
		message_vision(obj->query("finish_msg"), me, obj);
		else message_vision("$N将剩下的$n吃得干干净净。\n", me, obj);
		if( !obj->finish_eat() )
		destruct(obj);
	} 
	else{
	     if((string)obj->query("eat_msg"))
		   message_vision(obj->query("eat_msg"), me, obj);
		else message_vision("$N拿起$n咬了几口。\n", me, obj);
	}
	return 1;
}
int help(object me)
{
    write(@HELP
指令格式 : eat <物品名称>
 
这个指令可以让你吃食物。
 
HELP
    );
    return 1;
}

