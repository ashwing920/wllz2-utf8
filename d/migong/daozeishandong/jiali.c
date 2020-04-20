// 盗贼山洞
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit ROOM;

static int cutting = 50000;

void create()
{
	set("short","牢笼里");
	set("long",@LONG
这里是山贼和人贩子们关押妇人和小孩的牢笼。牢笼里铺着一层厚厚
的稻草，稻草上还残留着一些血渍，不时引来一些苍蝇贪婪的吮吸着，乌
烟瘴气，让人只想作呕。
LONG);
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
	object me,weapon;
	int jiali,damage,total;
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
			set("exits/south",__DIR__"laolong");
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
	if(query("exits")){
		write("山贼喽罗走了过来，一看到你，不禁笑道：哈哈！！竟然有人自己送上门来了，快把牢门关上。\n");
		write("只听“乓”的一声，牢门被紧紧的关上，还锁上了一条麻绳粗的铁链。\n");
		cutting = 50000;
		delete("exits/south");
		delete("cuted");
	}
}
