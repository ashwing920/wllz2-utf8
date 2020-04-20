// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);
void give_title(object me);
void set_faction_title(object me);
int main(object me, string arg)
{
	object ob, old_rec;
	string item;

	if( me->query_temp("sleeping") ) return notify_fail("你现在正躺着呢。\n");
/*
	if( environment(me)->query("restrict_action") ) 
		return notify_fail("这里不能做这件事情。\n");
*/
	if( !arg ) return help(me);

	if( arg == "cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你现在并没有收录任何人为弟子的意思。\n");
		write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
		tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}
	notify_fail("你想收谁作弟子？\n");
	sscanf(arg, "%s %s", arg, item);
	if( !(ob = present(arg, environment(me))) ) return 0;
	if( !userp(ob)) return 0;
	if( !me->query("faction") )
		return notify_fail("你并不属於任何门派，你必须先加入一个门派，或自己创一个才能收徒。\n");
	if( !me->query("faction/head") && !me->query("faction/second") )
		return notify_fail("你不是门派的负责人。\n");
	if( ob == me ) {
		give_title(me);
		tell_object(me,"你恢复了自己的头衔。\n");
		return 1;
		}
	if( !me->query("faction/head") 
		&& (me->query("faction/name") == ob->query("faction/name"))
		&& (ob->query("faction/head")||ob->query("faction/second")) )
		return notify_fail("你不是门派的负责人。\n");
	if( ob->is_player_apprentice_of(me) ) {
		if( item){
			if( item == "dizi"){
				ob->set("faction/second",1);
				printf("你授权%s代收弟子。\n", ob->name());
				tell_object( ob, sprintf("%s授权由你代收弟子。\n", me->name()));
				return 1;
			} else if( item == "no_dizi"){
				ob->delete("faction/second");
				printf("你取消%s代收弟子的权力。\n", ob->name());
				tell_object( ob, sprintf("%s取消你代收弟子的权力。\n", me->name()));
				return 1;
			} else if( item == "弟子"){
				ob->set("faction/generation",1);
				set_faction_title(ob);
				give_title(ob);// 重新设定玩家的RANK
				item = ob->query("faction/faction_title");
				printf("你授予%s%s的称号。\n", ob->name(), item);
				tell_object( ob, sprintf("%s授予你%s的称号。\n", me->name(),item));
				return 1;
			} else {
				item = convert_color(item);
				ob->set("faction/faction_title", item);
				ob->delete("faction/generation");
				give_title(ob);// 重新设定玩家的RANK
				printf("你授予%s%s的称号。\n", ob->name(),item);
				tell_object( ob, sprintf("%s授予你%s的称号。\n", me->name(),item));
				return 1;
			}
		}
		message_vision("$N拍拍$n的头，说道：「好好努力！」\n", me, ob);
		set_faction_title(ob);
		give_title(ob);// 重新设定玩家的RANK
			item = ob->query("faction/faction_titile");
		printf("你授予%s%s的称号。\n", ob->name(), item);
		tell_object( ob, sprintf("%s授予你%s的称号。\n", me->name(),item));
		return 1;
	}
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {
		if( !living(ob) ) {
			message_vision( "$N决定收$n为弟子。\n\n"
				"不过看样子$n显然没有办法行拜师之礼。\n\n", me, ob);
			return 1;
		}
		if( ob->query("faction")) {
			ob->delete("faction");
			message_vision( "$N决定背叛师门，改投入$n门下！！！\n\n", ob, me);
		} else message_vision( "$N决定拜$n为师。\n\n", ob, me);
		// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		
		message_vision( "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n", ob, me);

		ob->set("faction/name",me->query("faction/name"));
		me->add("faction/times",1);   
		ob->set("faction/generation",me->query("faction/times"));
		me->delete_temp("pending/recruit");
		ob->delete_temp("pending/apprentice");
		set_faction_title(ob);
		give_title(ob);// 重新设定玩家的RANK

		printf("恭喜您新收了一名%s。\n", ob->query("faction/faction_title"));
		tell_object( ob, sprintf("恭喜您成为%s。\n", ob->query("title")));

		return 1;

	} else {
		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("你想收" + ob->name() + "为弟子，但是对方还没有答应。\n");
		else if( objectp(old_rec) ) {
			write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
			tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n为弟子。\n", me, ob);
		tell_object(ob, YEL "如果你愿意拜" + me->name() + "为师父，用 bai_player 指令。\n" NOR);
		return 1;
	}
}
void set_faction_title(object me)
{
	string faction;
	int generation, exp;

	if( !(faction = me->query("faction/name"))) return;
	if( !(generation = me->query("faction/generation"))
		&& me->query("faction/faction_title")) return;
	exp = me->query("combat_exp");

	if( exp <= 100000 ) generation = 1;
	else if( exp <= 250000 ) generation = 2;
	else if( exp <= 500000 ) generation = 3;
	else if( exp <= 1000000 ) generation = 4;
	else if( exp <= 5000000 ) generation = 5;
	else if( exp <= 80000000 ) generation = 6;
	else if( exp <= 15000000 ) generation = 7;
	else generation = 8;
	me->set("faction/generation", generation) ;

	switch(generation){
		case 1: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "弟子"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "弟子"); return;
			case "飞氏集团":   me->set("faction/faction_title", "职员"); return;
			case "天空界":   me->set("faction/faction_title","豪兵"); return;
			default:
			}
		return;
		}
		case 2: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "坛主"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "坛主"); return;
			case "飞氏集团":   me->set("faction/faction_title", "秘书"); return;
			case "天空界":   me->set("faction/faction_title","勇者"); return;
			default:
			}
		return;
		}
		case 3: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "堂主"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "堂主"); return;
			case "飞氏集团":   me->set("faction/faction_title", "副主任"); return;
			case "天空界":   me->set("faction/faction_title","豪将"); return;
			default:
			}
		return;
		}
		case 4: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "护法"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "护法"); return;
			case "飞氏集团":   me->set("faction/faction_title", "主任"); return;
			case "天空界":   me->set("faction/faction_title","修罗"); return;
			default:
			}
		return;
		}
		case 5: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "法王"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "法王"); return;
			case "飞氏集团":   me->set("faction/faction_title", "副经理"); return;
			case "天空界":   me->set("faction/faction_title","战魂"); return;
			default:
			}
		return;
		}
		case 6: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "长老"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "长老"); return;
			case "飞氏集团":   me->set("faction/faction_title", "经理"); return;
			case "天空界":   me->set("faction/faction_title","战龙"); return;
			default:
			}
		return;
		}
		case 7: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "掌教长老"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "掌庄长老"); return;
			case "飞氏集团":   me->set("faction/faction_title", "副主席"); return;
			case "天空界":   me->set("faction/faction_title","狂龙"); return;
			default:
			}
		return;
		}
		case 8: {
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "副教主"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "副庄主"); return;
			case "飞氏集团":   me->set("faction/faction_title", "副总裁"); return;
			case "天空界":   me->set("faction/faction_title","武神"); return;                        default:
			}
		return;
		}
		default :{
		switch(faction) {
			case "孤星楼":   me->set("faction/faction_title", "弟子"); return;
			case "《江湖人》杂志社":   me->set("faction/faction_title", "弟子"); return;
			case "飞氏集团":   me->set("faction/faction_title", "职员"); return;
			case "天空界":   me->set("faction/faction_title","豪兵"); return;
			default:
			}
		return;
		} 
	}
}
void give_title(object me)
{
	string faction,faction_title;
	faction = me->query("faction/name");
	faction_title = me->query("faction/faction_title");
	switch(faction) {
		case "孤星楼":   me->set("title",HIC""+faction+faction_title + ""NOR); return;
		case "《江湖人》杂志社":   me->set("title",HIY""+faction+faction_title + ""NOR); return;
		case "飞氏集团":   me->set("title",HIW""+faction+faction_title + ""NOR); return;
		case "天空界":   me->set("title",MAG""+faction+""WHT+faction_title + ""NOR); return;
		default:
	}
	return;
}

int help(object me)
{
	write(@HELP
这个指令能让你收某人为弟子，如果对方也答应要拜你为师的话。
指令格式：recruit_player <对象>
	  recruit_player cancel
如果对方已经是自己弟子，还有其他几种用途：
	recruit_player <某人> <称号>   (给予某人特殊称号)
	recruit_player <某人> 弟子      (取消某人的特殊称号)
	recruit_player <某人> dizi      (授权某人收徒)
	recruit_player <某人> no_dizi  (取消某人收徒)
HELP
	);

	return 1;
}

