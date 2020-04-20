// m_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

int lianzao(string arg);
int do_hui(string arg);

void init()
{
	if(environment()==this_player()
	&& this_object()->query("armor_master") == this_player()->query("id")
	&& this_player()->query("armor/make")){
		add_action("do_lianzao","lianzao");
		add_action("do_hui","hui");
	}
}
void create()
{
	object me;
	mapping armor;
	me = this_player();

	if(mapp(armor = me->query("armor"))){
		set_name(armor["name"], ({"my armor","armor"}));
		set("long","这是"+ me->name() +"的"+ armor["name"] +"，看起来相当坚韧。\n");

		if((string)me->query("armor/wear_msg"))
			set("wear_msg",armor["wear_msg"]+"\n");
		else
			set("wear_msg", "$N轻轻的披上"+ armor["name"]+"，显得格外威风。\n");
		
		if((string)me->query("armor/remove_msg"))
			set("remove_msg",armor["remove_msg"]+"\n");
		else
			set("remove_msg", "$N轻轻一抖，"+ armor["name"] +"迎风飘扬，眨眼间已然不见影踪。\n");

		set("armor_prop/armor",armor["lv"] * 10);
		set("armor_prop/bad",armor["bad"]);
		set("armor_prop/armor_cool",armor["cool"]);
		set("armor_prop/armor_poison",armor["armor_poison"]);
		set("armor_master",me->query("id"));
	}
	else {
		set_name("我的衣服",({ "my armor","armor","cloth" }));
		set("long","一件玩家自造的衣服。\n");
		set("armor_prop/armor",1);
	}
	set_weight(3000);
	set("material","cloth");
	set("armor_type","cloth");
	set("unit","件");
	set("no_sell",1);
	set("value",2);
	set("ownermake",1);
	setup();
}
int do_lianzao(string arg)
{
	object me,cloth,armor;
	int a_zhi, a_level;
	string aname;

	me=this_player();
	aname = clean_color(me->query("armor/name"));

	if(!id(arg))
		return notify_fail("你要炼造什么？\n");

	if( environment(me)->query("chat_room")
	 || environment(me)->query("fight_room")
	 || environment(me)->query("no_fight")
	 || environment(me)->query("no_sleep_room")
	 || environment(me)->query("force_room"))
		return notify_fail("这个地方不能炼造防具！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，无法炼造"+ aname +"！\n");

	if((int)me->query("max_neili") < 100)
		return notify_fail("你的内力修为不够，无法炼造"+ aname +"！\n");

	if( (int)me->query("qi") <= 50 )
		return notify_fail("你的气不够，无法炼造"+ aname +"！\n");

	if( (int)me->query("jing") <= 30)
		return notify_fail("你的精气不足，无法炼造"+ aname +"！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法炼造"+ aname +"！\n");

	tell_object(me,CYN"你手指轻巧，眼明手快，开始炼造"+ aname +"。\n"NOR);

	me->add("max_neili",-10);
	me->add("neili",-100);
	me->add("learned_points",2);
	me->receive_damage("qi",50);
	me->receive_damage("jing",30);

	a_zhi = (int)me->query("armor/value");
	a_zhi++;
	me->set("armor/value", a_zhi);
	a_level = (int)me->query("armor/lv");
	if( a_zhi >= ((a_level + 1) * (a_level + 1))){
		a_level++;
		me->set("armor/lv", a_level);
		message_vision(HIY"\n$N用力一扯，发现"+ aname +"坚韧程度再度提高了！\n\n"NOR,me);
		tell_object(me,HIW"你的『" + aname + "』的等级已提高为："+ chinese_number(me->query("armor/lv"))+"！防御力为："+ me->query("armor/lv") *10 +"\n\n");
		cloth = new("/clone/misc/m_cloth");
		cloth->move(me,1);
		me->set("armor/value",0);
		me->save();
		armor=this_object();
		if(armor->query("equipped") )
			armor->unequip();
		destruct(armor);
		return 1;
	}
	return 1;
}
int do_hui(string arg)
{
	object me;
	me=this_player();

	if(!id(arg))
		return notify_fail("你要撕毁什么？\n");

	message_vision(HIR"$N用力一扯，只听见“哗啦”一声，$n"HIR"裂开两半！\n" NOR,me,this_object());
	me->delete("armor");
	destruct(this_object());
	me->save();
	return 1;
}
void owner_is_killed()
{
	write(HIY"只见一声猛烈的响声，碎做了数块，"+query("name")+HIY"飘落在地上。\n"NOR);
	this_object()->unequip();
	destruct(this_object());
}
