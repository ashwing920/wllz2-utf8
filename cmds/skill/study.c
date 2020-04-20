// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object env = environment(me);
	object ob;
	string zhao_name;
	mapping skill;
	int my_skill,cost,time,lit,i;
	int t = time();

	if(!arg)
		return notify_fail("你要读什么？\n");

	if(env->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");

	if(env->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(me->is_fighting())
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if(sscanf(arg,"%s with %d",arg,time) != 2)
		return notify_fail("指令格式：study|du <书籍> with <次数> \n");

	if (t == me->query_temp("time/study"))
		return notify_fail("你刚刚才读过书，无法再继续研究新知。\n");
	
	if(!objectp(ob = present(arg, me)))
		return notify_fail("你身上根本没有这本书可以读。\n");

	if(time < 0 || time > 100)
		return notify_fail("读书的次数不可小于 0 次，也不可以大于 100 次。\n");

	if(!mapp(skill = ob->query("skill")))
		return notify_fail("你无法从这样东西学到任何东西。\n");

	lit = (int)me->query_skill("literate",1);
	
	if(!lit || lit < 0)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if((int)me->query("combat_exp") < skill["exp_required"])
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");

	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"]
		* (skill["difficulty"] - (int)me->query_int())/12;

	if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
		return notify_fail("以你目前的能力，还没有办法学这个技能。\n");

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

	if( !me->query_skill(skill["name"], 1) ) 
		me->set_skill(skill["name"], 0);
	
	my_skill = (int)me->query_skill(skill["name"], 1);

	if((string)SKILL_D(skill["name"])->type()=="martial"
	&& (my_skill * my_skill * my_skill) / 10 > (int)me->query("combat_exp"))
		return notify_fail(sprintf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name()));

	me->set_temp("time/study", t);
	
	if (cost < 10 ) cost = 10;
	
	for( i=0;i< time;i++){
		if((int)me->query("jing") > cost)
			me->receive_damage("jing", cost);
		else{
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			me->set("jing",0);
			break;
		}
		if(me->query_skill(skill["name"], 1) > skill["max_skill"]){
			write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
			break;
		}
		if((string)SKILL_D(skill["name"])->type()=="martial"
			&& (my_skill * my_skill * my_skill) / 10 > (int)me->query("combat_exp")){
			write(sprintf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name()));
			break;
		}
		me->improve_skill(skill["name"], random(lit)+1);
	}
	if (! i)
	{
		write("你现在太累了，结果一行也没有看下去。\n");
		return 1;
	}

	if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
		write(sprintf("你研读有关%s的技巧，对「%s」这一招似乎有些心得。\n",
			to_chinese(skill["name"]), zhao_name));
	else
		write(sprintf("你研读有关%s的技巧，似乎有点心得。\n",
			to_chinese(skill["name"])));

	if (i < time)
		write("你现在已经过于疲倦，无法继续研读新知。\n");

	if(me->query("env/auto_regenerate"))
		SKILL_D("force/regenerate")->exert(me, me);
	return 1;
}
int help(object me)
{
   write( @HELP
指令格式: study <书籍> with <次数>

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧，但前提是：你
不能是个『文盲』。

HELP
   );
   return 1;
}
