// m_blade.c

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
	
	if(mapp(weapon = me->query("weapon"))){
		if(!weapon["id"]) weapon["id"] = "my blade";
		set_name(weapon["name"],({ weapon["id"],"blade"}));
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
			set("wield_msg",weapon["wield_msg"]+"\n");
		else
			set("wield_msg","$N往腰中一抽，拔出了一把"+ weapon["name"]+"在手中。\n");

		if(weapon["unwield_msg"])
			set("unwield_msg",weapon["unwield_msg"]+"\n");
		else
			set("unwield_msg", "$N手中"+ weapon["name"] +"迎风一抖，眨眼间已然不见影踪。\n");

		set_weight(weight() + (weapon["lv"] * 150));
		set("weapon_prop",me->query("weapon/weapon_prop"));
		init_blade(weapon["lv"] * 10);
	}
	else {
		set_name("传家宝刀",({"my blade","blade"}));
		set_weight(500);
		set("unit","把");
		init_blade(1);
	}
	set("no_sell",1);
	set("ownermake",1);
	set("value",1);
	setup();
}
int do_duanlian(string arg)
{
	object me,bingqi,weapon;
	int w_zhi, w_level;
	string w_name;

	me = this_player();
	w_name = clean_color(me->query("weapon/name"));

	if( !id(arg))
		return notify_fail("你要锻炼什么？\n");

	if( environment(me)->query("chat_room")
	 || environment(me)->query("fight_room")
	 || environment(me)->query("no_fight")
	 || environment(me)->query("no_sleep_room")
	 || environment(me)->query("force_room"))
		return notify_fail("这个地方不能炼刀！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，无法锻炼刀气！\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不够，无法锻炼刀气！\n");

	if( (int)me->query("qi") < 100 )
		return notify_fail("你的气不够，无法锻炼刀气！\n");

	if( (int)me->query("jing") < 100 )
		return notify_fail("你现在的精力无法集中，不能锻炼刀气！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法锻炼刀气！\n");

	tell_object(me,RED"你手指刀脊，一股绵绵内力丝丝的传了进去。\n" NOR);

	me->add("max_neili",-10);
	me->add("neili",-100);
	me->add("learned_points",2);
	me->receive_damage("qi",50);
	me->receive_damage("jing",30);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_level = (int)me->query("weapon/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		tell_object(me,HIC"\n刀身忽的一闪，一道银光隐入你的刀中，不见了！\n\n" NOR);
		tell_object(me,HIW"你的『" + w_name + HIW"』的等级已提高为："+ chinese_number(me->query("weapon/lv"))+"！破坏力为："+ me->query("weapon/lv") *10 +"\n\n");
		me->set("weapon/value",0);
		bingqi = new(base_name(this_object()));
		bingqi->move(me,1);
		weapon=this_object();
		if(weapon->query("equipped"))
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

	message_vision(HIR"$N大喝一声，一掌擎刀，一掌猛力击下。结果轰隆一声巨响$n"HIR"断为两截！\n"NOR,me,this_object());
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
