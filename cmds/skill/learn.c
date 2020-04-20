// learn.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
	"说道：你我素不相识，这个......\n",
});
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	string skill, teacher, skill_name;
	object ob;
	object where = environment(me);
	int master_skill, my_skill, jing_cost, times, pertimes;
	int t = time();

	if( where->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3))
		return notify_fail("指令格式：learn|xue <某人> <技能> <次数>\n");

	if (times < 1 || times > 100)
		return notify_fail("学习次数最少一次，最多也不能超过一百次。\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if (t == me->query_temp("time/learn"))
		return notify_fail("你刚刚才学习过，还是休息一下再说吧。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if( ob == me ) return notify_fail("你想向自己请教？\n");
	
	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) )
		return  notify_fail(ob ->name()+ reject_msg[random(sizeof(reject_msg))] );

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	notify_fail(ob->name() + "不愿意教你这项技能。\n");


	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	if( my_skill >= (int)(master_skill - me->query("betrayer")*2))
		return notify_fail(ob->name() + "皱了皱眉头，不禁想起你过去的叛师经历。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	jing_cost = 150 / (int)me->query("int");
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够学习这么多次了。\n");

	me->set_temp("time/learn",t);
	write(sprintf(CYN"你向%s请教了"+chinese_number(times)+"句关于「%s」的疑问。\n"NOR,
		ob->name(), to_chinese(skill)));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("jing") > jing_cost*times/5 + 1 )
	{
		if( userp(ob) ) ob->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
		write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}

	if( (int)me->query("jing") > jing_cost * times )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&&( my_skill * my_skill * my_skill) / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write(sprintf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(),
					skill_name));
			else
				write(sprintf("你听了%s的指导，似乎有些心得。\n", ob->name()));
			for (pertimes = 1; pertimes <= times ; pertimes ++)
			{
				me->add("learned_points", 1 + (int)SKILL_D(skill)->learn_hard());
				if( my_skill < 400)
					me->improve_skill(skill, random(me->query_int()) + (my_skill / 3));
				else
					me->improve_skill(skill, random(me->query_int()) + (my_skill / 6));
			}
		}
	} else
	{

		jing_cost * times = me->query("jing");
		return notify_fail("你今天太累了，结果什么也没有学到。\n");

	}
	me->receive_damage("jing", jing_cost * times);
	if(me->query("env/auto_regenerate"))
		SKILL_D("force/regenerate")->exert(me, me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : learn|xue <某人> <技能> <次数>

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教
的对象在这项技能上的造诣必须比你高，而你经由这种方式学习得来的技
能也不可能高於你所请教的人，然而因为这种学习方式相当於一种「经验
的传承」，因此学习可以说是熟悉一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的
悟性有关。

其他相关指令 : apprentice, practice, skills, study
HELP
	);
	return 1;
}
