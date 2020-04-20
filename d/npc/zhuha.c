// zhuha.c
// cgm 4/12/1999

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIR"莽牯朱蛤"NOR, ({ "zhu ha", "ha" }) );
	set("long", HIR"一只全身火红，只有拳头大小，叫声象牛的蛤蟆。\n"NOR);
	set("race", "野兽");
	set("age", 100);
	set("attitude", "aggressive");
	set("max_jing", 1500);
	set("max_qi", 8000);
	set("str", 100);
	set("cor", 50);
	set("combat_exp", 500000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence", 50);
	setup();
}
int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 1000000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("zhuha_poison") < 50 ) {
		ob->apply_condition("zhuha_poison", 60);
	tell_object(ob, HIR "一股焦热传来，你好象掉进了火炉之中！\n" NOR );
	}
}
