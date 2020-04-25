// m_cloth.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;


int lianzao(string arg);
int hui(string arg);

void init()
{
	if(environment()==this_player()
	&& this_object()->query("glove_master") == this_player()->query("id")
	&& this_player()->query("glove/make")){
		add_action("do_lianzao","lianzao");
		add_action("do_hui","hui");
	}
}
void create()
{
	object me;
	mapping glove;
	me = this_player();

	if(mapp(glove = me->query("glove"))){
		if(!glove["id"]) glove["id"] = "my glove";
		set_name(glove["name"],({ glove["id"],"手套"}));
		set("long","这是"+ me->name() +"的"+ glove["name"] +"，做工精美，看起来相当精致。\n");

		if((string)me->query("glove/wear_msg"))
			set("wear_msg",glove["wear_msg"]+"\n");
		else
			set("wear_msg", "$N套上一双"+ glove["name"]+"。\n");
		
		if((string)me->query("glove/remove_msg"))
			set("remove_msg",glove["remove_msg"]+"\n");
		else
			set("remove_msg", "$N从手上取下"+ glove["name"] +"，揣在兜里放好。\n");

		set("glove_master",me->query("id"));
		
		set("armor_prop/unarmed_damage",glove["lv"] * 10);
		init_glove(glove["lv"] * 10);

	}
	else {
		set_name("传家护手",({ "my glove","glove","hu shou" }));
		set("long","这是一双玩家自造的护手。\n");
		set("hand_prop/armor",1);
	}
	set_weight(3000);
	set("material","cloth");
	set("unit","双");
	set("no_sell",1);
	set("value",1);
	set("ownermake",1);
	setup();
}
int do_lianzao(string arg)
{
	object me,cloth,glove;
	int a_zhi, a_level;
	string aname;

	me=this_player();
	aname = clean_color(me->query("glove/name"));

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

	tell_object(me,CYN"你运气丹田，将丝丝内力传于"+ aname +"之中，试图增强它的灵性。\n"NOR);

	me->add("max_neili",-10);
	me->add("neili",-100);
	me->add("learned_points",2);
	me->receive_damage("qi",50);
	me->receive_damage("jing",30);

	a_zhi = (int)me->query("glove/value");
	a_zhi++;
	me->set("glove/value", a_zhi);
	a_level = (int)me->query("glove/lv");
	if( a_zhi >= ((a_level + 1) * (a_level + 1))){
		a_level++;
		me->set("glove/lv", a_level);
		tell_object(me,HIW"你的『" + aname + "』的等级已提高为："+ chinese_number(me->query("glove/lv"))+"！防御力为："+ me->query("glove/lv") *10 +"\n\n");
		cloth=new("/d/npc/m_weapon/weapon/m_glove",1);
		cloth->move(me,1);
		me->set("glove/value",0);
		me->save();
		glove=this_object();
		if(glove->query("equipped") )
			glove->unequip();
		destruct(glove);
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
	me->delete("glove");
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