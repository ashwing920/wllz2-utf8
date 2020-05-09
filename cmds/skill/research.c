// research.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, skill_name;
	object where = environment(me);
	int my_skill, jing_cost, times, pertimes,improve;
	int t = time();

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( where->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");

	if (!where->query("sleep_room"))
		return notify_fail("这里太纷杂，你没法做研究。\n");

	if(t == me->query_temp("time/research"))
		return notify_fail("你刚刚才研究过，休息一下再说吧。\n");

	if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 ))
		return notify_fail("指令格式：research|yanjiu <技能> <次数>\n");

	if (times < 1 || times > 100)
		return notify_fail("研究次数最少一次，最多也不能超过一百次。\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕没法研究了。\n");

	if( (string)SKILL_D(skill)->type()=="knowledge"
	&& skill != "taoism" && skill != "lamaism" && skill != "buddhism")
		return notify_fail(to_chinese(skill)+"只能靠你学习才能提高的。\n");

	notify_fail("依你目前的能力，没有办法研究这种技能。\n");

	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	if( SKILL_D(skill)->valid_research() && my_skill < SKILL_D(skill)->valid_research())
		return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法自行研究。\n");

	if( !SKILL_D(skill)->valid_research() && my_skill < 200 )
		return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法自行研究。\n");

	//if( my_skill >= 800)
	//	return notify_fail("你的"+ to_chinese(skill)+"已经进入高深莫测的境界，无法再进行研究了。\n");

	jing_cost = 300 / (int)me->query("int");

	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}
	improve=0;
	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够研究这么多次了。\n");
	me->set_temp("time/research",t);
	write(HIM"你开始研究「"+to_chinese(skill)+"」当中的精髓。\n"NOR,);

	my_skill = me->query_skill(skill, 1);
	if(my_skill < 400)
		improve=me->query_int() + me->query_spi();
	else
		improve=me->query_int() / 2;
	write(sprintf("原始improve:%d\n",improve));
	improve+=improve * where->query("research_improve") / 100;
	write(sprintf("房屋加成后improve:%d\n",improve));
	if( (int)me->query("jing") > jing_cost * times )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也许是缺乏实战经验，你没法研究"+to_chinese(skill)+"的问题了。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("你研究了一会，慢慢的领会了「"+ skill_name +"」一式的奥妙。\n");
			else
				write("你研究了一会，似乎对「"+to_chinese(skill)+"」有些新的领悟。\n");
			for (pertimes = 1; pertimes <= times ; pertimes ++)
			{
				me->add("learned_points",1);
				me->improve_skill(skill, random(improve));
			}
		}
	} else
	{
		jing_cost = me->query("jing");
		return notify_fail("你今天太累了，结果什么也没有研究成。\n");
	}
	me->receive_damage("jing", times * jing_cost );
	if(me->query("env/auto_regenerate"))
		SKILL_D("force/regenerate")->exert(me, me);
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
