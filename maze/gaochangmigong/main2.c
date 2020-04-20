//main1.c
// Design By Robert 蝴蝶君 Email:robert_st@sina.com

#include <ansi.h>

inherit ROOM;

static int total = 1000;

void create()
{
	set("short","高昌石壁");
	set("long",@LONG
一堵足有五个人高的石壁堵在你的面前，石壁上刻满了一些密密麻麻
的文字。看似梵文，却又不是。石壁的那头，不时传来一阵阵咔哒咔哒的
声响，好像石壁那端又是另外的一番天地。
LONG);

	set("exits",([
		"southeast": __DIR__"level/exit",
	]));
}
void init()
{
	add_action("do_break","pi");
}

int do_break(string arg)
{
	object me,weapon;
	string file;
	me = this_player();
	
	if(!arg || arg == "")
		return notify_fail("你要劈什么？\n");
	
	if(arg == "石壁" || arg == "shibi"){
		if(query("breaked")) return 0;
		if( me->query("neili") < 200)
			return notify_fail("你的内力不足，无法劈开石壁。\n");
		if(!objectp(weapon = me->query_temp("weapon"))){
			message_vision("$N挥掌就往石壁上劈去，“乓”的一声过后，石壁依然纹丝不动。\n",me);
			me->add("neili",-200);
			return 1;
		}
		if((int)weapon->query("weapon_prop/damage") < 100){
			message_vision(HIY"$N挥起"+ weapon->name()+ HIY"往石壁上劈去，只听见“啪”的一声，"+ weapon->name() +HIY"应声断开两截。\n"NOR,me);
			weapon->unequip();
			weapon->set("name",HIY"断掉的"+ weapon->name()+ NOR);
			weapon->set("value",0);
			weapon->set("weapon_prop",0);
			weapon->move(environment(me));
			me->add("neili",-200);
			return 1;
		}
		if(total > 0){
			message_vision(HIY"$N默运内力，挥起"+ weapon->name() + HIY"就往石壁上砍去，"+weapon->name()+ HIY"砍在石壁上，擦出星点火花。\n"NOR,me);
			total -= weapon->query("weapon_prop/damage");
			me->add("neili",-200);
			return 1;
		}
		else {
			message_vision("石壁轰隆隆的发出一阵巨响，应声崩塌，尘土飞扬，$N拨开尘土，发现了另外的一条出路。\n",me);
			file = FUBEN_D->query_maze_dir(me);
			set("exits/north",file+"level1/entry");
			set("breaked",1);
			me->add("neili",-200);
			return 1;
		}
	}
	return 0;
}
int query_total()
{
	return total;
}
void reset()
{
	set("breaked",0);
	delete("exits/north");
	total = 1000;
}
