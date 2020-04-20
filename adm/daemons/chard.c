// chard.c

//#pragma optimize
//#pragma save_binary

#define HUMAN_RACE "/adm/daemons/race/human"
#define BEAST_RACE "/adm/daemons/race/beast"
#define MONSTER_RACE "/adm/daemons/race/monster"
#define STOCK_RACE "/adm/daemons/race/stock"
#define BIRD_RACE "/adm/daemons/race/bird"
#define FISH_RACE "/adm/daemons/race/fish"
#define SNAKE_RACE "/adm/daemons/race/snake"
#define INSECT_RACE "/adm/daemons/race/insect"

void create() { seteuid(getuid()); }

void setup_char(object ob)
{
	string race;
	mapping my;

	if( !stringp(race = ob->query("race")) ) {
		race = "人类";
		ob->set("race", "人类");
	}

	switch(race) {
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;
		case "野兽":
			BEAST_RACE->setup_beast(ob);
			break;
		case "家畜":
			STOCK_RACE->setup_stock(ob);
			break;
		case "飞禽":
			BIRD_RACE->setup_bird(ob);
			break;
		case "游鱼":
			FISH_RACE->setup_fish(ob);
			break;
		case "蛇类":
			SNAKE_RACE->setup_snake(ob);
			break;
		case "昆虫":
			INSECT_RACE->setup_insect(ob);
			break;
		default:
			error("Chard: undefined race " + race + ".\n");
	}


	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]))  my["pighead"] = 0;
	if( undefinedp(my["jing"]) || my["jing"] > my["max_jing"]) my["jing"] = my["max_jing"];
	if( undefinedp(my["qi"]) || my["qi"] > my["max_qi"]) my["qi"] = my["max_qi"];
	if( undefinedp(my["eff_jing"]) || my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"])  || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
	if( undefinedp(my["jingli"])) my["jingli"] = my["max_jingli"];

	if (userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)){
		if( my["max_neili"] > ob->max_neili()) my["max_neili"] = ob->max_neili();
		if( my["neili"] > my["max_neili"]) my["neili"] = my["max_neili"];
	}
	if(userp(ob) && (my["max_jingli"] || my["jingli"])){
		if( my["max_jingli"] > ob->max_jingli()) my["max_jingli"] = ob->max_jingli();
		if (my["jingli"] > my["max_jingli"]) my["jingli"] = my["max_jingli"];
	}

	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
	
	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 100;
	}

	if( !ob->query_max_encumbrance() )
		ob->set_max_encumbrance( my["str"] * 5000 + 
					(ob->query_str() - my["str"]) * 1000);

	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}
	if( victim->is_zombie() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while( i-- ) destruct(inv[i]);
		say( victim->name() + "缓缓地倒了下来，化为一滩血水。\n");
		return 0;
	}


	corpse = new(CORPSE_OB);
	victim->delete("disable_type");
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender"))
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("killer",victim->query("last_pker"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));

	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while( i-- ) {
			if(inv[i]->query("equipped") == "horse"){
				inv[i]->delete("equipped");
				inv[i]->move(environment(corpse));
				if(victim->query_temp("is_riding"))
				victim->delete_temp("is_riding");
			}
			else if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if(!inv[i]->wear()) inv[i]->move(environment(victim));
			}
			else {          // 清除no_drop的物品。
				if (!inv[i]->query("no_drop")) inv[i]->move(corpse);
			}
		}
	}

	return corpse;
}
