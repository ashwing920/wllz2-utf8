// 盗贼山洞
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit ROOM;

static int cutting = 50000;

void create()
{
	set("short","牢笼");
	set("long",@LONG
这里是盗贼山洞关押人的地方。牢笼里阴暗潮湿，发出一股令人作呕
的恶臭。牢笼里关押着几个妇人和小孩，她们缩成一团，正用一种祈求而
由恐惧的眼光看着你，哆哆嗦嗦，想必已经被吓坏了。牢笼的大门被一条
麻绳粗的铁链(tielian)紧紧锁住了。
LONG);

	set("exits",([
		"south": __DIR__"level2/exit",
	]));
	set("item_desc",([
		"tielian":"一条麻绳粗的铁链，如果没有钥匙的话，恐怕要用利器才能砍断了。\n",
	]));
	setup();
}
void init()
{
	add_action("do_kan","kan");
}
int do_kan(string arg)
{
	object me,weapon,room,npc;
	int jiali,damage,total,i;
	me = this_player();

	if(!arg || arg =="")
		return notify_fail("你想要砍什么？\n");;

	if(arg == "铁链" || arg == "tielian"){
		if(!objectp(weapon = me->query_temp("weapon"))
		|| (weapon->query("skill_type") != "sword"
		&& weapon->query("skill_type") != "blade"))
			return notify_fail("不用刀剑怎么砍？\n");

		if((int)me->query("jiali") < 1)
			return notify_fail("铁链这么粗，不加内力砍的话恐怕不行。\n");

		if((int)me->query("neili") < 100)
			return notify_fail("你的内力不够了。\n");

		if( query("cuted"))
			return notify_fail("铁链已经被砍断了。\n");

		if( cutting <= 0){
			message_vision(HIY"只听见“锵”的一声巨响，铁链应声而断，掉落在地上，牢门被$N打开了。\n"NOR,me);
			set("cuted",1);
			set("exits/north",__DIR__"jiali");
			room = find_object(__DIR__"jiali");
			if(!room) room = load_object(__DIR__"jiali");
			room->set("exits/south",__DIR__"laolong");
			for(i=0;i<random(8)+3;i++){
				npc = new(__DIR__"npc/furen");
				npc->move(room);
				npc = new(__DIR__"npc/kid");
				npc->move(room);
			}
			return 1;
		}

		message_vision("$N运足内力，挥起手中的$n，狠狠的朝铁链上砍去，铁链与$n碰在一起，立刻擦出星点火花。\n",me,weapon);
		damage = (int)me->query_temp("apply/damage");
		jiali = (int)me->query("jiali");
		total = damage + jiali;
		cutting -= total;
		me->add("neili",-100);
		return 1;
	}
}
void reset()
{
	cutting = 50000;
	delete("exits/north");
	delete("cuted");
}