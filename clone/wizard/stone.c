// fengyun-stone.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"风云石"NOR, ({"fengyun stone","stone" }) );
	set_weight(100);
	set("long",@LONG
这就是传说中的风云石，据有超越凡间的一切力量。据说只要诚心祷告，
就会有奇迹出现。
LONG
);
	set_weight(100);
	set("no_give",1);
	set("no_put",1);
	set("no_get_from",1);
	set("no_pawn",1);
	set("no_drop",1);
	remove_call_out("deststone");
	call_out("deststone",180,this_object());
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value",0);
		set("material","diamond");
	};
	setup();
}

void init()
{
	if(environment()==this_player())
	add_action("do_daogao","daogao");
}
int do_daogao(string arg)
{
	object ob,me;
	int exp;
	ob = this_object();
	me = this_player();
	
	if(arg == "" || !arg )
		return notify_fail("你要祷告什么？\n");
	
	message_vision("$N拿起$n开始向天祷告："+ arg +"～～～\n",me,ob);
	exp = me->query("combat_exp") / 100;

	switch(random(40)){
		case 3:
			me->add("combat_exp",exp);
			tell_object(me,"恭喜，你的经验增长了“"+ chinese_number(exp) +"”点。\n");
			break;
		case 4:
			if(me->query("kar") < 50) {
			me->add("kar",1);
			tell_object(me,"恭喜，你的运气增加了一点。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 5:
			if(me->query("str") < 100) {
			me->add("str",1);
			tell_object(me,"恭喜，你的臂力增加了一点。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 6:
			if(me->query("per") < 50){
			me->add("per",1);
			tell_object(me,"恭喜，你的魅力增加了一点。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 7:
			if( me->query("con") < 50) {
			me->add("con",1);
			tell_object(me,"恭喜，你的根骨增加了一点。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 8: 
			if(me->query("int") < 100) {
			me->add("int",1);
			tell_object(me,"恭喜，你的悟性增加了一点。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 9:
			me->add("dex",1);
			tell_object(me,"恭喜，你的身法增加了一点。\n");
			break;
		case 10:
			if(me->query("weapon")) {
			me->add("weapon/lv",1);
			tell_object(me,"恭喜，你的"+ me->query("weapon/name") +"等级提高了一级。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 11:
			if(me->query("armor")){
			me->add("armor/lv",1);
			tell_object(me,"恭喜，你的"+ me->query("armor/name") +"等级提高了一级。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 12:                        
			if(me->query("age") > 18){
			me->add("mud_age",-86400);
			me->add("age",-1);
			tell_object(me,"突然间，你觉得自己显得年轻了许多。\n");
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 13:
			if(me->query("betrayer")){
			me->add("betrayer",-1);
			tell_object(me,HIR"由于你对门派忠心耿耿，人们忘记了你以前叛师的历史！\n"NOR);
			}
			else {
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			}
			break;
		case 14:
			me->add("weiwang",100);
			tell_object(me,"由于你一直表现良好，你的威望增加了一百点。\n");
			break;
		case 15:
			me->add("neili",me->query("max_neili"));
			tell_object(me,"恭喜，你的内力增加了。\n");
			break;
		case 16:
			me->add("food",me->max_food_capacity() * 3);
			me->add("water",me->max_water_capacity() * 3);
			me->set("eff_qi",me->query("max_qi"));
			me->set("eff_jing",me->query("max_jing"));
			me->set("qi",me->query("max_qi"));
			me->set("jing",me->query("max_jing"));
			me->set("neili",me->query("max_neili"));
			tell_object(me,"你突然觉得精神抖擞，气血旺盛。\n");
			break;
		case 17:
			me->set("bellicosity",0);
			tell_object(me,"你突然觉得心情平和，原来是你的杀气已经消失了。\n");
			break;
		case 18:
			me->set("PKS",0);
			tell_object(me,"恭喜，你的杀戮太多，上天将你的戾气化解了。\n");
			break;
		case 19:
			me->set("VKS",0);
			tell_object(me,"恭喜，上天给了你一次重生的机会，你的被杀次数消失了。\n");
			break;
		case 20:
			if(me->query("score") <= 4000)
			me->add("score",1000);
			tell_object(me,"恭喜，你的江湖阅历增加了一千点，好好努力吧！\n");
			break;
		case 21:
			me->apply_condition("corpse_poison",180);
			tell_object(me,"可能是你作恶多端的缘故，恭喜！你中了腐尸毒了。\n");
			break;
		case 22:
			me->add("mud_age",86400);
			me->add("age",1);
			tell_object(me,"也许是你日夜操劳，你显得苍老了许多。\n");
			break;
		case 23:
			me->add("combat_exp",-exp);
			tell_object(me,"恭喜！你的经验丢失了"+chinese_number(exp)+"点。\n");
			break;
		case 24:
			me->add("int",-1);
			tell_object(me,"恭喜！你的悟性降低了一点。\n");
			break;
		case 25:
			me->add("kar",-1);
			tell_object(me,"恭喜！你的运气降低了一点。\n");
			break;
		case 26:
			me->add("dex",-1);
			tell_object(me,"恭喜！你的身法降低了一点。\n");
			break;
		case 27:
			me->add("con",-1);
			tell_object(me,"恭喜！你的根骨降低了一点。\n");
			break;
		case 28:
			me->add("str",-1);
			tell_object(me,"恭喜！你的臂力降低了一点。\n");
			break;
		default:
			tell_object(me,"你祷告了半天，却什么事情也没有发生。\n");
			break;
		}
	destruct(this_object());
}
void deststone()
{
	destruct(this_object());
}
void owner_is_killed() { destruct(this_object()); }

