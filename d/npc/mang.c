// mang.c
// cgm 4/12/1999

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("蟒蛇", ({ "mang she", "mang", "she" }) );
	set("race", "蛇类");
	set("age", 3);
	set("long", "一条五、六尺长的大蟒蛇，昂首吐信，好象想吃人。\n");
	set("attitude", "peaceful");
	set("str", 50);
	set("cor", 50);
	set("max_jing", 800);
	set("max_qi", 3000);
	set("combat_exp", 100000);
	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage", 20+random(10));
	set_temp("apply/armor", 20+random(10));
	set_temp("apply/defence",20+random(10));
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