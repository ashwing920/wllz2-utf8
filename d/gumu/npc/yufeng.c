// yufeng.c //玉蜂

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW "玉蜂" NOR, ({"yufeng","feng","bee"}) );
	set("race","昆虫");
	set("subrace","飞虫");
	set("age", 8);
	set("long",@LONG
这是一只玉色的蜜蜂，个头比普通蜜蜂大得多，翅膀上被人用尖针刺有字
。古墓派的弟子一旦在古墓里迷路，就得靠它来带路(lead)了。遇到如此
稀奇的宝贝，你真想抓(arrest)一只过来好好珍藏。
LONG);
	set("str", 40);
	set("dex", 50);
	set("can_get",1);
	set_temp("apply/attack", 35);
	set_temp("apply/armor", 25);
	set("chat_chance", 2);
	set("chat_msg", ({
		(: random_move :),
		"玉蜂在你头顶转了一圈，似乎发现这不是可采蜜的地方，就嗡嗡嗡地飞走了。\n",
		"玉蜂围绕着鲜花飞飞停停，似乎也不着重在采蜜上。\n",
	}) );
	setup();
}
void init()
{
	add_action("do_arrest","arrest");

	if(environment() == this_player())
		add_action("do_lead","lead");
}
int do_arrest(string arg)
{
	object me;
	mapping fam;

	me = this_player();
	
	if(!id(arg))
		return notify_fail("你要抓什么？\n");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if(environment() == me)
		return notify_fail("小家伙不正在你身上嘛？小心别把它捏死了。\n");

	if(!mapp(fam = me->query("family"))
		|| fam["family_name"] != "古墓新派")
		return notify_fail("你伸手就想抓住玉蜂，可是这小家伙却十分伶俐，嗖的一声躲开了。\n");
		
	if((int)me->query_skill("qufeng",1) < 120)
		return notify_fail("你伸手就想抓住玉蜂，可是这小家伙却十分伶俐，嗖的一声躲开了。\n");
	
	message_vision(HIW"$N眼明手快，右手“嗖”的一声飞快的朝玉蜂抓去，一下子就把它抓了下来。\n"NOR,me);
	move(me,1);
	return 1;
}
int do_lead(string arg)
{
	object me;
	mapping fam;
	string path,mypath;
	int i;
	
	me = this_player();
	
	if(!mapp(fam = me->query("family"))
		|| fam["family_name"] != "古墓新派")
		return notify_fail(name() +"好像一点也不听你的使唤。\n");

	if((int)me->query_skill("qufeng",1) < 120)
		return notify_fail("你的驱蜂之术太差，玉蜂根本不听你的使唤。\n");

	path = base_name(environment(me));
	i = strlen(path);
	
	i--;
	while(path[i]!='/' && i>0) {
		i--;
	}
	
	mypath=path[0..(i-1)];
	
	message_vision(HIW"$N摊开手掌，手中的玉蜂顷刻“嗡嗡”飞起，在$N的身边来回旋绕。\n\n"NOR,me);

	if(mypath != "/d/gumu"){
		write(HIR"可是这里并不是古墓，玉蜂象无头苍蝇般四处乱串了一阵子，终于疲惫不堪，死掉了。\n"NOR);
		move(environment(me));
		die();
		return 1;
	}

	if((int)query("use_time") >= (int)query("con") / 3){
		write(HIW"玉蜂显然已经太劳累了，刚飞起几步，突然“啪嗒”一声掉在地上，死掉了。\n"NOR);
		move(environment(me));
		die();
		return 1;
	}

	if(me->is_busy() || me->is_fighting()){
		write(HIR"可是你忙着其他事情，转眼之间，玉蜂已经飞远了。\n"NOR);
		destruct(this_object());
		return 1;
	}
	
	write(HIC"你紧紧跟随着玉蜂飞去的路线，不一会儿，你已经来到了古墓墓门之外。\n\n"NOR);
	me->move("/d/gumu/mumen");
	write(HIW"玉蜂又轻轻飞落了你的手掌之中，你轻轻的将玉蜂揣在怀里放好。\n"NOR);
	add("use_time",1);
	return 1;
}
int move(mixed dest)
{
	if(environment() && environment(this_object())->is_character())
	{
		delete("chat_chance");
		delete("chat_msg");
	}
	return ::move(dest);
}
