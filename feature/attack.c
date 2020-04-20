// attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>
#include <weapon.h>

#define MAX_OPPONENT 4

static object *enemy = ({ });
static string *killer = ({ });

object *query_enemy() { return enemy;}
string *query_killer() { return killer; }

void apply_killer(string *ik)
{ 
	if (arrayp(ik)) 
		killer = filter_array(ik, (: stringp :)); 
}
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;
	return member_array(ob, enemy)!=-1;
}

varargs int is_killing(string id)
{
        if(!id) return sizeof(killer) > 0;
        return arrayp(killer) && member_array(id, killer) != -1;
}
void fight_ob(object ob)
{
	object env;
	
	if(!ob || ob==this_object()) return;

	if(member_array(ob, enemy) != -1) return;

	env = environment();

    	if(environment(ob) != env 
    	|| env->query("no_fight")) return;

        if(!living(this_object())) return;

	set_heart_beat(1);
	enemy += ({ ob });
        ob->fight_ob(this_object());

}
void kill_ob(object ob)
{
	object env,me;
	me=this_object();

	if(!ob || !living(me)) return;

	env = environment();

	if(environment(ob) != env || env->query("no_fight"))  return;

        if (! arrayp(killer)) killer = ({ });
	
	tell_object(ob, HIR "看起来" + me->name() + HIR + "想杀死你！\n" NOR);
	
	if(member_array(ob->query("id"),killer) == -1 )
		killer += ({ ob->query("id") });

	if(userp(me) && userp(ob)){
		if(!ob->query_temp("first_kill/"+me->query("id")) )
			me->set_temp("first_kill/"+ob->query("id"), 1);
		if(!ob->query_temp("be_kill/"+ me->query("id")))
			ob->set_temp("be_kill/"+ me->query("id"),1);
	}
	fight_ob(ob);
	
}
void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
	for(int i=0; i<sizeof(enemy); i++) {
		if( !objectp(enemy[i])
		||  environment(enemy[i])!=environment()
		||  (!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
		enemy[i] = 0;
	}
	enemy -= ({ 0 });
	}
}
object select_opponent()
{
	int which;
	if( !sizeof(enemy) ) return 0;
	which = random(MAX_OPPONENT);
	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}
int remove_enemy(object ob)
{
	enemy -= ({ ob });
	return 1;
}

int remove_killer(object ob)
{
	if( is_killing(ob->query("id"))) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}
	return remove_enemy(ob);
}
int check_killer(string id)
{
	if(member_array(id,killer) != -1)
		return 1;
}
	
void remove_all_enemy(int force)
{
        int i;

	if (! (i = sizeof(enemy)))
		return;

        while (i--)
	{
                // We ask our enemy to stop fight, but not nessessary to confirm
                // if the fight is succeffully stopped, bcz the fight will start
                // again if our enemy keeping call COMBAT_D->fight() on us.
                if (objectp(enemy[i]))
                {
                        if (force || ! enemy[i]->is_killing(query("id")))
                        {
                                enemy[i]->remove_enemy(this_object());
                                enemy[i] = 0;;
                        }
                }
        }

        enemy -= ({ 0 });
}
void remove_all_killer()
{
        int i;
        //object ob;

        enemy -= ({ 0 });

        for (i = 0; i < sizeof(enemy); i++)
                if (enemy[i]->remove_killer(this_object()))
                        enemy[i] = 0;

        killer = ({ });

        enemy -= ({ 0 });
}

void reset_action()
{
	object me,ob;
	string type, skill;
	mapping prepare;

	me = this_object();
	prepare = query_skill_prepare();

	if( ob = me->query_temp("weapon") ) type = ob->query("skill_type");
	else if ( sizeof(prepare) == 0) type = "unarmed";
	else if ( sizeof(prepare) == 1) type = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)
		type = (keys(prepare))[query_temp("action_flag")];

	if( stringp(skill = query_skill_mapped(type)) ) {
		if(ob && (ob->query("flag") & SELF_ACTION))
			set("actions", ob->query("actions",1) );
		else if ( ob )
			set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
		else
			set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}
int attack()
{
	object opponent;
	clean_up_enemy();
	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

void init()
{
	object ob;
	object me;
	mapping my,its;
	string vendetta_mark;

	me = this_object();

	if(!living(me)
	|| !(ob = this_player())
	|| !living(ob)
	|| environment(ob)!=environment()
	|| environment(ob)->query("no_fight")
	|| environment(ob)->query("fight_room"))
		return;

        my = query_entire_dbase();
        its = ob->query_entire_dbase();

	// 如果是伴侣
	if(my["marry"] == its["id"]) return;

	// 如果是设置了好朋友
	if((sizeof(my["my_friends"]) > 1 
		&& member_array(its["id"],my["my_friends"]) != -1)
	&& (sizeof(its["my_friends"]) > 1 
		&& member_array(my["id"],its["my_friends"]) != -1))
		return;

	if(interactive(ob) && is_killing(its["id"]) && ob->is_killing(my["id"])) {
		COMBAT_D->auto_fight(me, ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = my["vendetta_mark"])
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(me, ob, "vendetta");
		return;
	} else if(userp(ob) && my["attitude"]=="aggressive" ) {
		COMBAT_D->auto_fight(me, ob, "aggressive");
		return;
	} else if(ob->query_condition("oldfamily_killer") && its["old_family"] && my["family"]
	&& its["old_family"]["family_name"] == my["family"]["family_name"] && !userp(ob) && !userp(me)) {
		message_vision(HIR"\n$N喝道："+ ob->name() +"，你这个叛徒，纳命来！！！\n"NOR,me);
		COMBAT_D->auto_fight(me, ob, "aggressive");
		return;
	} else if( random(my["bellicosity"]) > (my["max_neili"] + random(my["neili"]))) {
		COMBAT_D->auto_fight(me, ob, "berserk");
		return;
	}
}
