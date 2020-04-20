// beidajie1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "玄冰石室");
	set("long", @LONG
这里是据称千年寒石的发源地－玄冰石室，站在石室中间，顿觉阵阵
阴寒之气袭上心头。只见石室内十分宽敞，石室顶端，挂着一道道冰柱，
隐隐的水珠不断地往下滴淌，地面上三两步就可见到一滩水迹，把原本干
燥的地面弄得滑溜溜的。
LONG
	);
	set("exits", ([
		"west": __DIR__"stone1",
		"east": __DIR__"stone3",
		"southwest": __DIR__"stone5",
		"southeast": __DIR__"stone6",
	]));
	set("no_sleep_room",1);
	set("pk_room",1);
	setup();
}
void init()
{
	object ob;

	if( interactive(ob = this_player()) && !query("checking")) {
		remove_call_out("check_status");
		call_out("check_status",10);
		set("checking",1);
	}
}
void check_status(object ob)
{
	object inv;

	foreach (inv in all_inventory()){
		if(!userp(inv) || !inv->is_character() || inv->is_corpse()) continue;
		if(environment(inv) != environment()) continue;
	}
	if(!inv) {
		delete("checking");
		return;
	}
	tell_object(inv,HIC"一阵阴寒之气自地面幽幽袭来，偶尔吹来一阵微风，你不禁涩涩发抖。\n"NOR);
	inv->receive_damage("jing",50);
	inv->receive_damage("qi",100);
	inv->delete_temp("last_damage_from");
	inv->set_temp("die_for","寒气袭骨，活活冻死在玄冰石室里！");
	remove_call_out("check_status");
	call_out("check_status",10);
}
