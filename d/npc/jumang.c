// jumang.c
// cgm 4/12/1999

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"巨蟒"NOR, ({ "ju mang", "mang" }) );
	set("race", "蛇类");
	set("age", 1000);
	set("long", HIY"一条千年巨蟒，力大无穷，皮粗肉厚，刀剑不入。\n"NOR);
	set("attitude", "peaceful");
	set("str", 120);
	set("cor", 100);
	set("dex", 200);
	set("max_jing", 1500);
	set("max_qi", 12000);
	set("combat_exp", 800000);
	set_temp("apply/attack", 50+random(50));
	set_temp("apply/damage", 50+random(50));
	set_temp("apply/armor", 100+random(100));
	set_temp("apply/defence",50+random(50));
	setup();
}
void init()
{
	object me,ob;

	if (interactive(me = this_player()))
	{
	if (!(ob = present("xionghuang", this_player())))
	       {
	       remove_call_out("kill_ob");
	       call_out("kill_ob", 1, me);
		}
	}
}