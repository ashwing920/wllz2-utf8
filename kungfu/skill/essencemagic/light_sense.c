// light_sense.c - 光识神通

#include <ansi.h>

inherit F_SSERVER;

int bbqthem(object me, object obj,int lvl);

string *light_msg = ({"电！","闪！","雷！","鸣！","击！","火！","杀！",});

int conjure(object me, object target)
{
	object env, *inv;
	int lvl,i;
	string msg;

	lvl = (int)me->query_skill("essencemagic",1) + (int)me->query_skill("magic",1);

	if( me->query("jingli") < 200 )
		return notify_fail("你的灵力不够！\n");

	if( me->query("jing") <= 200 )
		return notify_fail("你的精不够！\n");

	if((int)me->query_skill("essencemagic",1) < 150)
		return notify_fail("你的八识神通火候不足，无法使用光识神通。\n");

	me->add("jingli",- 200);
	me->receive_damage("jing",200);

	if ( lvl <= random(300) )
		return notify_fail("你因法术不够高而失败了！\n");

	msg = light_msg[random(sizeof(light_msg))];
	message_vision(HIW"$N腾空飞起，暴喝一声："HIR + msg + HIW +"只见$N全身发出一道炽热的红光，象利刃般四散飞去。\n" NOR, me);

	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( inv[i]->is_corpse() || !inv[i]->is_character()) continue;
		if( userp(inv[i]) && inv[i]->query("age") < 18 ) continue;
		if( wizardp(inv[i])) continue;
		if( inv[i]->query("one_enemy") &&( inv[i]->is_fighting()&&!( inv[i]->is_fighting(me))))  continue;
		bbqthem(me, inv[i],lvl);
	}
	me->start_busy(random(5)+1);
	return 1;

}

int bbqthem(object me, object obj,int lvl)
{

	message_vision(HIR"\n一道炽热的红光象利剑般射向$N！！\n\n", obj);

	obj->receive_damage("jing", 0, me);

	if(obj->is_ghost()==1) {
		message_vision(YEL"$N惨叫了一声，化为了灰烬！" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(YEL"$N惨叫了一声，化为了一滩血水！" NOR, obj);
		obj->die();
		return 1;
	}
	if( obj->query_temp("apply/shade_vision")){
		obj->delete_temp("apply/shade_vision");
		message_vision(HIW"$N惨号了一声，终于现出了一个人形。\n"NOR,obj);
		obj->start_busy(5);
		return 1;
	}

	obj->receive_damage("jing",lvl,me);
	obj->receive_damage("qi",lvl * 2,me);
	me->set_temp("first_kill/"+ obj->query("id"),1);
	if( !obj->is_fighting(me) && !me->is_fighting(obj)){
		me->kill_ob(obj);
		obj->fight_ob(me);
	}
	return 1;
}
