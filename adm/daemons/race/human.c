// human.c

#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([      "action":       "$N挥拳攻击$n的$l",
		"damage_type":  "瘀伤",
	]),
	([      "action":       "$N往$n的$l一抓",
		"damage_type":  "抓伤",
	]),
	([      "action":       "$N往$n的$l狠狠地踢了一脚",
		"damage_type":  "瘀伤",
	]),
	([      "action":       "$N提起拳头往$n的$l捶去",
		"damage_type":  "瘀伤",
	]),
	([      "action":       "$N对准$n的$l用力挥出一拳",
		"damage_type":  "瘀伤",
	]),
});
void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"左肩", "右肩", "左臂", "左脚", "右脚", "右臂",
		"左手", "右手", "腰间", "小腹", "左腿", "右腿",
		"后心", "头部", "颈部", "胸口",
	}) );
	set("dead_message",             "\n$N倒在地上，挣扎了几下就死了。\n\n");
	set("unconcious_message",       "\n$N脚下一个不稳，跌在地上昏了过去。\n\n");
	set("revive_message",           "\n$N慢慢睁开眼睛，清醒了过来。\n\n");
}
void setup_human(object ob)
{
	mapping my;
	int qi_age;
	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	if(undefinedp(my["age"]) ) my["age"] = 14;
	if(undefinedp(my["str"])) my["str"] = 10 + random(21);
	if(undefinedp(my["con"])) my["con"] = 10 + random(21);
	if(undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if(undefinedp(my["int"])) my["int"] = 10 + random(21);
	if(undefinedp(my["per"])) my["per"] = 10 + random(21);
	if(undefinedp(my["kar"])) my["kar"] = 10 + random(21);
	if(undefinedp(my["spi"])) my["spi"] = 10 + random(21);
	if(undefinedp(my["cor"])) my["cor"] = 10 + random(21);

	if(my["age"] >= 50 && my["age"] - my["last_age"] > 4){
		my["per"] -= 1; 
		my["last_age"] = my["age"];
	}
/* 精力设置 */

	if(userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)){
		if( my["max_neili"] > ob->max_neili()) my["max_neili"] = ob->max_neili();
		if( my["neili"] > my["max_neili"]) my["neili"] = my["max_neili"];
	}
	if( my["max_jingli"] > ob->max_jingli()) my["max_jingli"] = ob->max_jingli();
	if( my["jingli"] > my["max_jigli"]) my["jingli"] = my["max_jingli"];

/* 精神设置 */

	if( userp(ob) || undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 20 ) my["max_jing"] = 100 + (my["age"] - 14) * 20;
		else if( my["age"] <= 30||(int)ob->query_skill("taoism", 1)> 59) my["max_jing"] = 220;
		else if( my["age"] <= 60 ) my["max_jing"] = 220 - (my["age"] - 30) * 5;
		else my["max_jing"] = 70;
		if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"] / 2;
		if( my["breakup"] ) my["max_jing"] *= 2;
	}
/* 气血设置 */
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 20 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else my["max_qi"] = my["con"] * 6 + 100;

		// 道家练气：３０岁前补气，３０岁后长气
		if((qi_age=(int)ob->query_skill("taoism", 1)) > 39){
			qi_age = qi_age/2;
			if (my["age"] <= 30) qi_age -= my["age"];
			else qi_age -= 30;
			// Added by Hop
			qi_age += my["max_jingli"] / 50;
			// End of appendence
			if (qi_age > 0) my["max_qi"] += qi_age *((int)ob->query_skill("taiji-shengong", 1)/10) ;
		}

		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"];
	}
	ob->set_default_object(__FILE__);

	if( !ob->query_weight() )
		ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);

	if (!userp(ob)){
		if (undefinedp(my["neili"]))
		my["max_neili"] = (int)ob->query_skill("force") * 15;
		my["neili"]=my["max_neili"];
		if (undefinedp(my["jiali"]))
		my["jiali"] = (int)ob->query_skill("force") /2;
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"];
		if (undefinedp(my["jingli"]) && my["family"])
		my["max_jingli"] = ((int)ob->query_spi()+(int)ob->query_cor()) * 100;
		my["jingli"] = my["max_jingli"];
		if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"];
		my["eff_qi"]=my["max_qi"];
		my["qi"]=my["max_qi"];
		my["eff_jing"]=my["max_jing"];
		my["jing"]=my["max_jing"];
	}
	if ((int)ob->query("mud_age")<100){
		if(!(int)ob->query("water")) ob->set("water",ob->max_water_capacity());
		if(!(int)ob->query("food"))  ob->set("food",ob->max_food_capacity());
	}
}
mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
