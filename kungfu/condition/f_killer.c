// f_killer.c
// 帮会追杀状态

#include <ansi.h>

int update_condition(object me, int duration)
{
	object ob;
	mapping kill_family;
	kill_family = me->query("kill_family");

	if (duration < 1) {
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("据悉%s已经放弃追杀%s了。",kill_family["family_name"],me->name()));
		me->delete("kill_family");
		return 0;
	}
	me->apply_condition("f_killer", duration - 1);
	if(random(10) == 2
	|| random(10) == 5 ){
		ob=new("/clone/npc/f_killer");
		ob->set("family",kill_family);
		ob->set("title",kill_family["family_name"] +"罚恶使者");
		ob->set("combat_exp",me->query("combat_exp") * 10);
		ob->add_temp("apply/damage",me->query("weapon/lv") * 10);
		ob->add_temp("apply/armor",me->query("armor/lv") * 10);
		NPC_D->full_init(ob);
		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
	}
	return 1;
}
