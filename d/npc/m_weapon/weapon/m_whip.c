// m_whip.c

#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;

int duanlian(string arg);
int do_hui(string arg);

void init()
{
	if(environment()==this_player()
	&& this_object()->query("weapon_master") == this_player()->query("id")
	&& this_player()->query("weapon/make")){
		add_action("do_duanlian","duanlian");
		add_action("do_hui","hui");
	}
}
void create()
{
	object me;
	mapping weapon;
	me = this_player();
	
	if(me && mapp(weapon= me->query("weapon"))){
		if(!weapon["id"]) weapon["id"] = "my whip";
		set_name(weapon["name"],({ weapon["id"],"whip"}));
		set("weapon_master",me->query("id"));
		set("rigidity",weapon["rigidity"]);
		set("unit","把");
		set_desc(weapon["lv"],weapon["or"],weapon["name"]);
		switch(weapon["or"]){
			case "千年神木" :
				set_weight(500);
				set("material", "iron");
				break;
			case "海底金母" :
				set_weight(1000);
				set("material", "steel");
				break;
			case "寒丝羽竹" :
				set_weight(30);
				set("material", "bamboo");
				break;
			default :
		}
		if(weapon["wield_msg"])
			set("wield_msg", weapon["wield_msg"]+"\n");
		else
			set("wield_msg", "$N往腰中一摸，刷的抖出了一把"+ weapon["name"]+"。\n");
		
		if(weapon["unwield_msg"])
			set("unwield_msg", weapon["unwield_msg"]+"\n");
		else
			set("unwield_msg", "$N手中"+weapon["name"]+"一抖，眨眼间卷回腰间不见了影踪。\n");
		
		set_weight(weight() + (weapon["lv"] * 150));
		set("weapon_prop",me->query("weapon/weapon_prop"));
		init_whip(weapon["lv"] * 10);
	}
	else {
		set_name("传家之鞭",({"my whip","whip"}));
		set_weight(500);
		set("unit","把");
		init_whip(1);
	}
	set("no_sell",1);
	set("ownermake",1);
	set("value",1);
	setup();
}
int do_duanlian(string arg)
{
	object me,bingqi,weapon;
	string w_name;
	int w_zhi, w_level;

	me = this_player();
	w_name= clean_color(me->query("weapon/name"));

	if( !id(arg))
		return notify_fail("你要锻炼什么？\n");

	if( environment(me)->query("chat_room")
	 || environment(me)->query("fight_room")
	 || environment(me)->query("no_fight")
	 || environment(me)->query("no_sleep_room")
	 || environment(me)->query("force_room"))
		return notify_fail("这个地方不能炼鞭！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，无法锻炼兵器！\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不够，无法锻炼兵器！\n");

	if( (int)me->query("qi") < 100 )
		return notify_fail("你的气不够，无法锻炼兵器！\n");

	if( (int)me->query("jing") < 100 )
		return notify_fail("你现在的精力无法集中，不能锻炼兵器！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法锻炼兵器！\n");

	tell_object(me,RED"你手捏鞭稍，一股内力丝丝的传了进去。\n" NOR);

	me->add("max_neili",-10);
	me->add("neili",-100);
	me->add("learned_points",2);
	me->receive_damage("qi",50);
	me->receive_damage("jing",30);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_level = (int)me->query("weapon/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1))){
		w_level++;
		me->set("weapon/lv", w_level);
		tell_object(me,HIY"\n鞭身忽的一亮，一道金光隐入你的" + w_name + HIY"，不见了！\n\n" NOR);
		tell_object(me,HIW"你的『" + w_name + HIW"』的等级已提高为："+ chinese_number(me->query("weapon/lv"))+"！破坏力为："+ me->query("weapon/lv") *10 +"\n\n");
		bingqi = new(base_name(this_object()));
		bingqi->move(me,1);
		me->set("weapon/value",0);
		me->save();
		weapon=this_object();
		if(weapon->query("equipped") )
		weapon->unequip();
		destruct(weapon);
		return 1;
	}
	return 1;
}

int do_hui(string arg)
{
	object me;
	me=this_player();
	if( !id(arg))
		return notify_fail("你要摧毁什么？\n");

	message_vision(HIR "$N大喝一声，一手擎鞭，一手猛的一扯。结果啪的一声爆响$n"HIR"断为两截！\n" NOR,me,this_object());
	me->delete("weapon");
	me->save();
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
	this_object()->unequip();
	destruct(this_object());
}
