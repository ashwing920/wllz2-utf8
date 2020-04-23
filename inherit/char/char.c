// char.c

//#pragma optimize
//#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

static int tick;
static string short_desc = 0;

void create()
{
	seteuid(0);
}

int is_character() { return 1; }

void setup()
{
	seteuid(getuid(this_object()));
	set_heart_beat(1);
	tick = time() + 5 + random(10);
	enable_player();
	CHAR_D->setup_char( this_object() );
}
void heart_beat()
{
	int t;
	int wimpy_ratio, cnd_flag;
	mapping my;
	string prompt;
	object ob,me;
	me = this_object();

	if(!me || !environment(me)) return;

	my = query_entire_dbase();
	if (userp(me) && living(me) && mapp(my["env"]))
	{
		// update prompt
		prompt = my["env"]["prompt"];
		if ((prompt == "time" || prompt == "mud" || prompt == "hp") &&
		    is_waiting_command() && ! me->is_attach_system())
		    
		{
			write_prompt();
		}
		
	}
	if(userp(me) && !interactive(me) && me->query("biguan")){
		if(me->query_temp("breakup"))
			me->breakup();
		else if(me->query_temp("closed"))
			me->closed();
	}
	if(userp(me) && me->is_ghost() && !environment()->query("death")){
		tell_object(me,HIB"黑暗中一个声音怒喝道：你一个孤魂野鬼，跑上来阳间做什么？\n"NOR);
		tell_room(environment(),HIB"\n天空中突然出现一个黑洞，一股阴冷刺骨地寒风将"+ me->name(1)+"卷了进去。\n\n"NOR);
		me->move("/d/death/gate");
	}
	if( my["eff_qi"] < 0 || my["eff_jing"] < 0) {
		die();
		return;
	}
	if (my["qi"] < 0 || my["jing"] < 0)
	{
		if (!living(me)) die();
			else unconcious();
		if (! me || ! living(me))
			return;
	}
	if( is_busy() ) {
		continue_action();
		return;
	} else {
		if(is_fighting()
		&& intp(wimpy_ratio = (int)query("env/wimpy"))
		&& wimpy_ratio > 0
		&& !environment(me)->query("fight_room")
		&& !environment(me)->query("watch_fight_room")
		&& ( my["qi"] * 100 / my["max_qi"] <= wimpy_ratio
		||   my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
			GO_CMD->do_flee(me);
		attack();
	}

	if( !userp(me) && living(me) ) {
		me->scan();
		if( !me ) return;
	}

	if ((t = time()) < tick) return;
	else tick = t + 5 + random(10);

	cnd_flag = update_condition();
	if (! me) return;

	if(((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
	&& !is_fighting() && !interactive(me)){
		if(environment()) {
			ob = first_inventory(environment());
			while(ob && !interactive(ob))
				ob = next_inventory(ob);
		}
		if( !ob ) set_heart_beat(0);
	}

	me->update_age();

	if( !interactive(me)) return;

	if(query_idle(me) > IDLE_TIMEOUT)
		me->user_dump(DUMP_IDLE);
}
int visible(object ob)
{
	int invis,perception;

	if(wizardp(this_object())) return 1;
	invis = (int)ob->query("env/invisibility");
	if( !invis ) invis = (int)ob->query_temp("apply/shade_vision");
	
	perception = (int)query_temp("apply/astral_vision");
	if(!perception) perception = (int)query_skill("perception",1);

	if( invis ){
		if(wizardp(ob)) return 0; // 如果是巫师设置隐身，this_object()无法看到。
		if(!userp(ob)) return 0; // 如果是npc隐身，对方this_object()看不到。
		if(!userp(this_object()) && is_fighting()) return 1; // 如果战斗的对方是npc，对方可看到隐身的ob。
		if(perception > invis || this_object() == ob) return 1; // 如果对手this_object()拥有可识破隐身人物或拥有听风辨器的技术，而且等级低于对手的隐身级别，对手可看到隐身的ob。
		if((int)query("env/invisibility")) return 1; // 如果对方巫师等级大于隐身中的巫师，可看到。
		return 0;
		// 否则返回 0，看不到。
	}
	if(ob->is_ghost()) {
		if(is_ghost()) return 1;
		if((int)query_temp("apply/astral_vision")) return 1;
		return 0;
	}
	return 1;
}
string set_short_desc(string desc)
{
	short_desc = desc;
}

varargs string short(int raw)
{
	string title, nick, str,  *mask;
	object me;

	me = this_object();

	if (! raw && sizeof(mask = query_temp("apply/short")))
		str = (string)mask[sizeof(mask) - 1];
	else
	{
		str = query("name") + "(" + query("id") + ")";
		if (! stringp(title = query_temp("title")))
			title = query("title");
		if (nick = query("nickname"))
		{
			str = "「" + nick + "」" + str;
			if (title) str = title + str;
		} else
		if (title) str = title + " " + str;
	}

	if (! raw)
	{
		if (short_desc)
			str = name() + short_desc;
	} else
		return str;

	if (me->is_ghost())
		str = HIB "(鬼气) " NOR + str;

	if(!interactive(me) && userp(me))
	{
		if(query("biguan"))
			return str += HIR " <闭关中>" NOR;
		
		else return str += HIG " <断线中>" NOR;
	}

	if( query_condition("killer"))
		str += HIR" <逃亡中>"NOR;

	if( query_condition("parsion"))
		str += HIR" <服刑中>"NOR;

	if( query_condition("drunk"))
		str += HIC" <醉酒中>"NOR;

	if( is_fighting())
		str += HIR" <战斗中>"NOR;

	if (in_input())
		str += HIC " <输入文字中>" NOR;

	if (! living(me) && query("disable_type"))
		str += HIR + query("disable_type") + NOR;

	if (in_edit())
		str += HIY " <编辑档案中>" NOR;

	if (interactive(this_object()) && query_idle(this_object()) > 120 )
		str += HIM " <发呆中>" NOR;

	return str;
}
