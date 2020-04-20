// damage.c

#include <dbase.h>
#include <login.h>
#include <move.h>
#include <ansi.h>
#include <action.h>

int ghost = 0;
int is_ghost() { return ghost;}
void set_ghost(int i){ ghost = i;}

static object defeated_by = 0;
static string defeated_by_who = 0;

object query_defeated_by() { return defeated_by; }
string query_defeated_who() { return defeated_by_who;}

void die();

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

	if( objectp(who) ) set_temp("last_damage_from", who);

	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}
varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

	if( objectp(who) ) set_temp("last_damage_from", who);

	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);

	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}
int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}
int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}
void unconcious()
{
	object defeater,me;
	object env;
	me = this_object();
	env = environment(me);
	if( !living(me) ) return;
	if( wizardp(me) && query("env/immortal") ) return;
	if( is_ghost() ) { die(); return; }
	if( run_override("die") ) return;
    if( playerp(me) && env && function_exists("user_cant_die", env) ) {
            if( environment()->user_cant_die(me) )
                     return;
    }
	if( objectp(defeater = me->query_temp("last_damage_from")))
		COMBAT_D->winner_reward(defeater, me);
	
	if(objectp(defeater) && userp(me) && userp(defeater)){
		defeated_by = defeater;
		defeated_by_who = defeater->query("id");
	}

	if (me->is_busy()) me->interrupt_me();

	me->remove_all_enemy(0);
	me->clear_written();
	
	message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,me);
	
	me->disable_player(" <昏迷不醒>");
	set_temp("unconcious",1);
	set("no_get",1);
	set("jingli", 0);
	set("neili", 0);
	set("jing", 0);
	set("qi", 0);
	set_temp("block_msg/all",1);
	call_out("revive", random(100 - me->query_con()) + 20);
	COMBAT_D->announce(me, "unconcious");
}
varargs void revive(int quiet)
{
	object me;
	me = this_object();
	
	remove_call_out("revive");

	me->enable_player();
	me->write_prompt();

	delete("disable_type");
	delete("no_get");
	
	set_temp("block_msg/all", 1);

	while( environment()->is_character() || environment()->is_container())
		me->move(environment(environment()));

	if( !quiet ) {
		defeated_by = 0;
		defeated_by_who = 0;
		COMBAT_D->announce(me, "revive");
		set_temp("unconcious",0);
		delete_temp("block_msg");
		message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,me);
	}
	delete_temp("block_msg");
}
void die()
{
	object corpse, killer,me,tmp_load,env;
	int exp,pot,shen,count_point,load;
	mapping ks;
	
	me = this_object();
	env = environment(me);
	if( !living(me) ) revive(1);
	if( wizardp(me) && query("env/immortal") ) return;
	if( (int)environment(me)->query("fight_room")
	|| (int)environment(me)->query("watch_fight_room")) return;


	// 如果没有经过授权，无法使用指令让这个生物死亡
	if (objectp(previous_object()))
		if( !SECURITY_D->valid_set( me, previous_object()) ) return ;

	// 自由式PK的场所保护
	if(run_override("die")) return;
    if( playerp(me) && env && function_exists("user_cant_die", env) ) {
            if( environment()->user_cant_die(me) )
                     return;
    }
	// Clear all the conditions by death.
	COMBAT_D->announce(me, "dead");

	if(objectp(me->query_temp("last_damage_from")))
		killer = me->query_temp("last_damage_from");
	if(stringp(defeated_by_who) && killer->query("id") != defeated_by_who){
		if(objectp(defeated_by))
			killer = defeated_by;
		else {
			tmp_load = UPDATE_D->load_player(defeated_by_who);
			load = 1;
			killer = tmp_load;
		}
	}
	
	defeated_by = 0;
	defeated_by_who = 0;

	if(killer) {
		ks = killer->query_entire_dbase();
		me->set("my_pker", clean_color(ks["name"]));
		me->set("last_pker",clean_color(ks["name"]));
// 任务奖励开始
		if(!userp(me) && ks["quest"] && ks["quest"]["quest_type"] == "杀" 
		&& ks["quest"]["quest"]==me->name(1)){
			if( ks["quest"]["task_time"] >  time()){
				exp = ks["quest"]["exp_bonus"] + (random(ks["quest"]["exp_bonus"]) /2);
				pot = ks["quest"]["pot_bonus"] + (random(ks["quest"]["pot_bonus"]) /2);
				shen =ks["quest"]["exp_bonus"] + (random(ks["quest"]["pot_bonus"]) /2);
				ks["combat_exp"] += exp;
				ks["potential"] += pot;
				ks["score"] += 1;

				if(ks["shen"] >= 0) 
					ks["shen"] += shen;
				else 
					ks["shen"] -= shen;

				tell_object(killer, sprintf("恭喜你！你又完成了一项任务！\n你的经验增加了%s点！\n"
				"你的潜能增加了%s点！\n你的江湖阅历提高了一点！\n你的神也提高了%s点！\n", 
				chinese_number(exp),chinese_number(pot),chinese_number(shen)));
				SCORE_D->set_score(killer);
				killer->add_temp("count",1);
				if((int)killer->query_temp("count") > 15) {
					count_point = ks["quest"]["diff"] * 15 * 100;
					if(count_point > 6000) count_point = 6000;
					tell_object(killer,sprintf(HIY"\n恭喜！由于你连续的完成十五个任务。"
					"\n你获得了%s点实战经验和一百点江湖威望的额外奖励。\n\n"NOR,chinese_number(count_point)));
					ks["combat_exp"] += count_point;
					ks["weiwang"] += 100;
					killer->delete_temp("count");
				}
			}else{
				tell_object(killer,YEL"你没有在规定时间完成你的任务，你的任务失败了！\n"NOR);
				killer->delete_temp("count");
		}
//删除任务
		ks["MKS"]+=1;
		map_delete(ks,"quest");

	} else COMBAT_D->killer_reward(killer, me);
		} else COMBAT_D->die_for(me);
	if(me->query("eatable"))
		( new((string)me->query("afterdie")) )->move(environment() );
	else if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
		corpse->move(environment());
	
	me->remove_all_killer();
	all_inventory(environment())->remove_killer(me);
	me->dismiss_team();

	// 如果有临时呼叫玩家，清除玩家并存档，临时呼叫标志消失

	if(load) 
		UPDATE_D->global_destruct_player(tmp_load, 1);
		load = 0;
	
	if( userp(me) ) {
		if (me->is_busy()) me->interrupt_me();
		set("eff_jing",1);
		set("jing",1);
		set("eff_qi", 1);
		set("qi",1);
		set("neili",0);
		set("jingli",0);
		ghost = 1;
		me->move(DEATH_ROOM);
		//DEATH_ROOM->start_death(me); 这个现在已经没用了。
	} else
		destruct(me);
}
void reincarnate()
{
	if (!ghost) return;
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
	delete_temp("last_damage_from");
	delete_temp("last_opponent");
	delete("last_pker");
}
int max_food_capacity() { return query_weight() / 200;}

int max_water_capacity(){ return query_weight() / 200;}

int heal_up()
{
	int update_flag;
	mapping my;
	object me=this_object();

	if(ghost && userp(me))  { set("eff_qi",1); return -1; }
	if(environment())
	if(environment()->query("chat_room")
	|| environment()->query("force_room")
	|| me->query_temp("biguan")) return -1;

	update_flag = 0;

	my = query_entire_dbase();

	if(userp(me) && !wizardp(me)){
	if( my["water"] > 0 ){ my["water"] -= 1; update_flag++; }
	if( my["food"] > 0 ) {
		my["food"] -= 1;
		if(my["food"] == me->max_food_capacity()*0.3 )
			tell_object(me,HIY "\n你肚子咕咕直叫，看来得吃点东西了。\n"NOR);
		if(my["food"] == me->max_food_capacity()*0.1 ){
			tell_object(me,HIY "\n你饿得直发慌，赶快吃点东西吧。\n"NOR);
			me->delete_temp("foods");
		}
		update_flag++;
	}
	else{
		if (!me->query_temp("foods")){
			tell_object(me,HIR "\n你饿得直冒金星，实在是顶不住了。\n"NOR);
			me->set_temp("foods",10);
	}
	if ((int)me->query_temp("foods") > 1) me->add_temp("foods",-1);
		else{
			tell_object(me,HIR"\n你又饿又冷，浑身发抖，看样子快不行了......\n"NOR);
			if((int)me->query("age") < 15 ) {
				tell_object(me,HIY"还好路边有位好心的大婶，给了你一碗隔夜的面条，你狼吞虎咽的吞了下去。\n"NOR);
				me->set("food",me->max_food_capacity());
				me->set("water",me->max_water_capacity());
			}
			else{
				me->unconcious();
				me->set_temp("foods",10);
			}
		}
		update_flag++;
	}
}
	//如玩家战斗中，不会恢复其体力。
	if( userp(me)
	&& !wizardp(me)
	&& me->is_fighting() ) return update_flag;

	if( my["water"] < 1 && userp(me) ) return update_flag;
		my["jing"] += my["con"] / 3 + my["max_jingli"] / 10;
	if( my["jing"] >= my["eff_jing"] ) {
		my["jing"] = my["eff_jing"];
		if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"] ++; update_flag++; }
	} else update_flag++;

	my["qi"] += my["con"] / 3 + my["max_neili"] / 10;
	if( my["qi"] >= my["eff_qi"] ) {
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
	} else update_flag++;

	if( my["food"] < 1 && userp(me) ) return update_flag;

	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
		my["jingli"] += (int)me->query_skill("magic", 1) / 2;
		if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
		update_flag++;
	}

	if( my["neili"] < (my["max_neili"] / 5 )) {
		my["neili"] += (int)me->query("max_neili") / 5;
		if( my["neili"] <= 0 ) my["neili"] = 0;
		if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
		update_flag++;
	}

	return update_flag;
}
void sleep()
{
	object me, env, *inv;
	int i;

	me = this_object();

	if( !living(me) ) return;
	if(me->query_temp("sleeping") == 1) return;

	me->set_temp("sleeping", 1);
	me->remove_all_enemy(0);
	me->clear_written();
	me->disable_player(" <沉睡中.zzZZ>");
	me->set("jing",10);
	me->set("qi",10);

	if( environment(me)->query("sleep_room") ) {


	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if( inv[i]->query_temp("sleeping")
		&&      inv[i]->query("gender") != me->query("gender") )  {
			if ( stringp(me->query("marry")) ) {
				if( me->query("marry") == (string)inv[i]->query("id") )
					message_vision( HIM "$N用手轻轻地拥着$n睡着了。\n" NOR, me, inv[i] );
				else
					message_vision( HIR "突然有人大喝一声：$N！婚外偷情是犯法的！\n" NOR, me );
			}
			else message_vision( HIR "突然有人大喝一声：$N！未婚同居是犯法的！\n" NOR, me );

		}
	}
	}
	set_temp("block_msg/all",1);
	call_out("wakeup",10);
	return;
}
varargs void wakeup()
{
	object me,env, *inv;
	int i, flag;

	me = this_object();
	remove_call_out("wakeup");

	if(environment()->is_character()) me->move(environment(environment()));

	me->delete_temp("sleeping");
	me->enable_player();
	me->write_prompt();

	if( environment(me)->query("sleep_room")) {
		env = environment(me);
		inv = all_inventory(env);
		flag = 0;
		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]==me ) continue;
			if( inv[i]->is_corpse() ) continue;
			if( !inv[i]->is_character()) continue;
			if( inv[i]->query_temp("sleeping")) flag ++;
		}
	}
	else flag = 1;

	if( flag <= 1 ) {
		me->set("qi",(int)me->query("eff_qi") );
		me->set("jing",(int)me->query("eff_jing") );
		me->set("jingli",(int)me->query("max_jingli") );
		if((int)me->query("max_neili") > (int)me->query("neili") )
			me->add("neili",((int)me->query("max_neili") - (int)me->query("neili"))/2);
	}
	else
		write(HIC"对不起，一个房间最多只能睡两个人。\n"NOR);

	delete_temp("block_msg/all");
	message_vision("$N一觉醒来，活动了几下筋骨，整个人看起来精神了很多。\n" ,me);
	return;
}
