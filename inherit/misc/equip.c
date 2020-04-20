// equip.c

#include <ansi.h>

inherit ITEM;
inherit F_EQUIP;

int set_weapon_desc();

void setup()
{
	if( !query("weapon_prop/dodge") && (weight() >= 3000) )
		set("weapon_prop/dodge", - weight() / 3000 );

//	if(!query("desc")) set_weapon_desc();
}
/*
int set_weapon_desc()
{
	string msg,report;
	int rigidity;
	mapping status;
	rigidity = query("rigidity");
	status = query("weapon_prop");
	msg = query("long");
	
	if(rigidity > 1) report = CYN"只见它软硬适中，轻手便利，十分顺手。";
	else if(rigidity > 20) report = HIC"只见它寒光瑟瑟，无坚不摧，简直无与伦比。";
	else if(rigidity > 30) report = HIW"只见它削铁如泥，显然是经过千锤百炼而成。";
	else if(rigidity > 40) report = HIW"只见它高傲而不可侵犯，可谓兵器中之神器。";

	if(rigidity)
		msg += report + "\n";
	else
		msg += CYN"可惜还没有经过炉火的锤炼，经受不起重创。\n"NOR;

	msg += sprintf(WHT"伤害度：%d　臂力：%d　魅力：%d　身法：%d　定力：%d。\n",
	status["damage"],status["strength"],status["personality"],status["personality"],status["composure"]);
	set("desc",msg);	
	set("long",msg);
}
*/