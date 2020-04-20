// research.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int research(object me);
int halt_research(object me);
int main(object me, string arg)
{
        string skill, skill_name;
        object where = environment(me);
        int my_skill, jing_cost, times, pertimes;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( where->query("restrict_action"))
                return notify_fail("这里不能做这件事情。\n");

        if (!where->query("sleep_room"))
                 return notify_fail("这里太纷杂，你没法做研究。\n");

        if(!arg || (sscanf(arg, "%s %d",skill,times) != 2 ))
                return notify_fail("指令格式：research|yanjiu <技能> <次数>\n");

        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");

        if( !my_skill = me->query_skill(skill, 1) )
                return notify_fail("这项技能你恐怕没法研究了。\n");

        if( (string)SKILL_D(skill)->type()=="knowledge"
        && skill != "taoism" && skill != "lamaism" && skill != "buddhism" && skill != "poison")
                return notify_fail(to_chinese(skill)+"只能靠你学习才能提高的。\n");

        notify_fail("依你目前的能力，没有办法研究这种技能。\n");

        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        if( SKILL_D(skill)->valid_research() && my_skill < SKILL_D(skill)->valid_research())
                return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法自行研究。\n");

        if( !SKILL_D(skill)->valid_research() && my_skill < 200 )
                return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法自行研究。\n");

        if( my_skill >= 800)
                return notify_fail("你的"+ to_chinese(skill)+"已经进入高深莫测的境界，无法再进行研究了。\n");

	if(me->query("jing") < 100)
		return notify_fail("你的精神太差，无法静心研究武功。\n");

        if((me->query("potential") - me->query("learned_points")) < 1 * times)
                return notify_fail("你的潜能不足，无法研究武功。\n");

	me->set_temp("research/skill",skill);
	me->set_temp("research/time",times);
        write(HIM"你开始研究「"+to_chinese(skill)+"」当中的精髓。\n"NOR,);
	me->set_short_desc("正在研究「"+to_chinese(skill)+"」当中的精髓。");
	me->start_busy((: research :), (:halt_research:));
	return 1;
}
int research(object me)
{
	string skill,skill_name,msg;
	int my_skill,jing_cost,times;
	jing_cost = 300 / (int)me->query("int");


	skill = (string)me->query_temp("research/skill");
	times = (int)me->query_temp("research/time");

        my_skill = me->query_skill(skill, 1);
	
	if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
		msg = "你研究了一会，慢慢的领会了「"+ skill_name +"」一式的奥妙。\n";
	else
		msg = "你研究了一会，似乎对「"+to_chinese(skill)+"」有些新的领悟。\n";

	if((my_skill * my_skill * my_skill) / 10 > (int)me->query("combat_exp")){
		write(msg);
		me->delete_temp("research");
		write("也许是经验不足，你尝试研究"+ to_chinese(skill) +"却毫无进展。\n");
		me->set_short_desc(0);
		return 0;
	}
	if((int)me->query("jing") < 100 || (int)me->query("jing") < times * jing_cost){
		write(msg);
		me->delete_temp("research");
		write("你精神不好，无法再继续进行研究。\n");
		me->set_short_desc(0);
		return 0;
	}

	me->add("learned_points",1 * times);
	me->receive_damage("jing",jing_cost * times);
	if(my_skill < 400)
		me->improve_skill(skill,(random(me->query_int()) + random(me->query_spi())) * times);
	else
		me->improve_skill(skill,(random(me->query_int()) / 2) * times);

        return 1;
}
int halt_research(object me)
{
	me->delete_temp("research");
	me->set_short_desc(0);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : research | yanjiu <技能> <次数>

这个指令可以让你研究一种技能的疑难问题，当你师傅这项技能的级
别不如你的时候，可以通过研究自己来提高，当然进步的速度是不如
向师傅学的了。

此外研究也需要消耗一些精力，而消耗的精力跟你自己的悟性有关。

其他相关指令 : apprentice, practice, skills, study, learn
HELP
        );
        return 1;
}
