// daodejing-i.c

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_discuss","discuss");
}
void create()
{
	set_name( "道德经「上卷」", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册道德经「上卷」，由体道第一始至去用第四十止。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "taoism",	   // name of the skill
			"exp_required": 0,	  // minimum combat experience required
			"jing_cost":	20,	 // jing cost every time study this
			"difficulty":   20,	 // the base int to learn this skill
			"max_skill":	50,	 // the maximum level you can learn
		]) );
	}
}

int do_discuss(string arg)
{
	object me, obj,ob;
	int mylev , objlev ,myexp,objexp;
	int myint , objint,count,times,score;

	string book_name = "jing";
	mapping skill = this_object()->query("skill");
	me = this_player();
	   
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");	 
	 
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不要讨论。\n");

	if( !arg )
		return notify_fail("你想和谁研讨道学心法？\n");

	if(!objectp(obj = present(arg, environment(me))))

		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj == me)
		return notify_fail("你不能自学的。\n");

	myexp =  me -> query ("combat_exp" ) ;
	objexp = obj -> query ("combat_exp" ) ;
	mylev =  (int)me -> query_skill("taoism",1) ;
	objlev = (int)obj -> query_skill("taoism",1) ;
	myint = (int) me -> query("int" ) ;
	objint = (int)obj -> query("int" ) ;
		  times = (int)me->query("MKS")/10+(int)me->query("PKS")/5+random(5)+5;

		  if ((int)me->query("shen") < 0  || (int)obj->query("shen") < 0)
				return notify_fail("道德经是正派人士研讨之用的\n");

	if(!objectp(ob = present(book_name, obj)) )
		return notify_fail("对方没书怎么研讨啊!\n");

	if ( (mylev < 20) || (mylev > (skill["max_skill"]+1)*2) || mylev < skill["max_skill"])
		return notify_fail("你的道学心法不够条件！\n");

	if ( (objlev < 20) || (objlev > (skill["max_skill"]+1)*2) || objlev < skill["max_skill"])
				return notify_fail("对方的道学心法不够条件!\n");
			 if ( (mylev - objlev)*100/objlev > 20 || (objlev - mylev)*100/mylev > 20) 
			 return notify_fail("你们的道学心法差距太大了,不能共同研讨!\n");

		 if ( (me->query("int") - obj->query("int")) > 10 || (obj->query("int") - me->query("int")) > 10)
				 return notify_fail("你们的天资差距太大了,不能共同研讨!\n");
		  if ( me->query("jing") < 20 || me->query("qi") < 20 || obj->query("qi") < 20 || obj->query("jing") <20)
				 return notify_fail("你们的气血已经不能再研讨了!\n");



			 if (me->query_temp("qinjiao") > 0)
				 return notify_fail("你对道学心法的理解已经不能进步了\n");

		  if (me->query_temp("mcount") > times )  {
				me->set_temp("qinjiao",1);
				return notify_fail("你又领会了道德心法新的要领了\n");}

		  message_vision(HIY "\n$N翻开道德经和$n一起领悟其中的奥秘.\n"NOR, me, obj);
		  count = me->query_temp("mcount");
			 score = me->query("score");
		  me->set_temp("mcount",count+1);
		   if (times < 20)  me->set("score",score+100-times*5);
			else me->set("score",score+100-times*3);

	  me->improve_skill("taoism", (int)me->query_skill("literate", 1)/5+5);
	  obj->improve_skill("taoism", (int)obj->query_skill("literate", 1)/5+5);
	 me -> receive_damage ("jing", 30 - random(5));
	 me -> receive_damage ("qi", 30 -  random(5));
	 obj -> receive_damage ("jing", 30 - random(5));
	 obj -> receive_damage ("qi",30 - random(5));
	   obj -> start_busy (3) ;
	 me -> start_busy (2) ;
	   return 1;
}
