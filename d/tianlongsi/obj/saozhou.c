// saozhou.c 扫帚
// xueer

#include <weapon.h>
inherit HAMMER;

int do_sao(string arg);

void create()
{
	set_name("扫帚", ({ "sao zhou","saozhou" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把普通的扫帚,你可以扫它(sao)。\n");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
		set("material", "wood");
	}
	init_hammer(5);
	setup();
}

void init()
{
	add_action("do_sao", "sao");
}

int do_sao(string arg)
{
	object me,ob;
	me = this_player();

	if (ob = present("duan jian",environment(me)))
	if(!arg||arg!="duan jian")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_duanjian",environment(me)))
			  {
			destruct(present("duan jian",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
 			return notify_fail("你拿出一把扫帚握在手中,把地上的断剑扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("duan jian",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的断剑扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	

	
	if (ob = present("shu ye",environment(me)))
	if(!arg||arg!="shu ye")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_shuye",environment(me)))
			  {
			destruct(present("shu ye",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
			return notify_fail("你拿出一把扫帚握在手中,把地上的树叶扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("shu ye",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的树叶扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	


	if (ob = present("fei zhi",environment(me)))
	if(!arg||arg!="fei zhi")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_feizhi",environment(me)))
			  {
			destruct(present("fei zhi",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
			return notify_fail("你拿出一把扫帚握在手中,把地上的废纸扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("fei zhi",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的废纸扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	


	if (ob = present("xiao shizi",environment(me)))
	if(!arg||arg!="xiao shizi")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_shizi",environment(me)))
			  {
			destruct(present("xiao shizi",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
			return notify_fail("你拿出一把扫帚握在手中,把地上的小石子扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("xiao shizi",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的小石子扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	


	if (ob = present("xiao muban",environment(me)))
	if(!arg||arg!="xiao muban")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_muban",environment(me)))
			  {
			destruct(present("xiao muban",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
			return notify_fail("你拿出一把扫帚握在手中,把地上的小木板扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("xiao muban",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的小木板扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	


	if (ob = present("po sengyi",environment(me)))
	if(!arg||arg!="po sengyi")
		return notify_fail("你要扫什么东西？\n");
	else
		{
		if(me->query_temp("marks/sao"))
		   if (ob = present(me->query("id")+"_sengyi",environment(me)))
			  {
			destruct(present("po sengyi",environment(me)));
			me->add_temp("marks/sao",-1);
			me->start_busy(2+random(3));
			me->receive_damage("jing",10+random(30));
			me->receive_damage("qi",10+random(30));
			return notify_fail("你拿出一把扫帚握在手中,把地上的破僧衣扫在一边。\n
你清扫完一样杂物。\n");
			   }
			   else
			   {   destruct(present("po sengyi",environment(me)));
			   me->start_busy(2+random(3));
			   me->receive_damage("jing",10+random(20));
			   me->receive_damage("qi",10+random(20));
			   return notify_fail("你拿出一把扫帚握在手中,把地上的破僧衣扫在一边。\n
你把别人要清扫的杂物扫了。\n");
			}
		 else return notify_fail("你不去复命在这里干什么?");				 
		}	

	return 0;
}