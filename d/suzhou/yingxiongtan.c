// taolunshi.c - 武学讨论室

inherit ROOM;

string look_sign();

void create()
{
	set("short", "苏州英雄堂");
	set("long", @LONG
这里是苏州最具文明的英雄堂室。英雄堂是有苏州当地的衙门所创办
，表面上是弘扬中原武林，实际上是为募集江湖好汉加入朝廷所用。这里
常常挤满了形形色色的武林人士，是广交天下武林同道的好地方。英雄堂
中央的墙上挂着一幅龙飞凤舞的字画，上面写着“光大武林”四个大字，
据说是出自于武当真人张三丰之手。墙的另一面，挂着一块牌子（sign）。
LONG
);

	set("item_desc", ([
		"sign": @TEXT

弘扬中原武林，欢迎加入讨论。

join        加入讨论
chat        自由发言

TEXT
	]) );
	set("exits", ([
		"northwest"  : __DIR__"nandajie1",
	]) );
	set("no_fight",1);
	set("no_beg",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me, env, *inv;
	int total, i,my_skill;
	string skill;

	me = this_player();

	if((int)me->query("combat_exp") <= 100000)
		return notify_fail("以你现在的能力不足，不能在这里进行讨论。\n");

	if(me->query_temp("talking") == 1)
		return notify_fail("你已经在讨论当中了！\n");

	env = environment(me);
	inv = all_inventory(env);
	for(i = 0, total = 1 ; i < sizeof(inv); i++) {
		if( inv[i] == me ) continue;
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if( !userp(inv[i])) continue;
		total ++;
	}
	if((int)me->query("jing") < 200 || (int)me->query("qi") < 200)
		return notify_fail("你现在精神不好，无法加入讨论。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你的内力不足，无法加入讨论。\n");

	if( total <= 1 )
		return notify_fail("这里没有人和你讨论！\n");

	if(!arg || (sscanf(arg,"%s",skill) != 1))
		return notify_fail("你想要和其他人讨论什么？\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你还没学会，根本无法进行讨论。\n");

	if( (string)SKILL_D(skill)->type()=="knowledge"
	&& skill != "taoism" && skill != "lamaism" && skill != "buddhism")
		return notify_fail(to_chinese(skill)+"只能靠你学习才能提高的。\n");

	if( SKILL_D(skill)->valid_research() && my_skill < SKILL_D(skill)->valid_research())
		return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法通过讨论来加深了解。\n");

	if( !SKILL_D(skill)->valid_research() && my_skill < 200 )
		return notify_fail("你的"+ to_chinese(skill)+"火候不够，无法通过讨论来加深了解。\n");

	if( my_skill >= 800)
		return notify_fail("你的"+ to_chinese(skill)+"已进入高深莫测的境界，再讨论也没有用了。\n");

	my_skill = me->query_skill(skill, 1);
	if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		return notify_fail("可能是实战经验不足，你无法再以"+ to_chinese(skill)+"进行讨论。\n");

	message_vision("$N开始发表对「"+ to_chinese(skill)+"」的看法....\n", me);
	me->set_temp("talking", 1);
	call_out("compelete_join",30,me,skill);
	return 1;
}

private void compelete_join(object me,string skill)
{
	int i, m, n;

	if(!me) return;
	me->delete_temp("talking");
	if( present(me) ) {                     // 如果玩家还在原地
		message_vision("$N和大家讨论了许久，获得了不小的收益，对「"+ to_chinese(skill)+"」也加深了了解。\n", me);
		i = me->query_con() + me->query_spi();
		m = (random(i) + 1) / 3;
		n = m + random(8);
		me->add("potential", m);
		me->add("combat_exp", n);
		tell_object(me, sprintf("你的潜能增加了%d点！\n", m));
		tell_object(me, sprintf("你的经验增加了%d点！\n", n));
		me->improve_skill(skill, random(me->query_int()));
		me->receive_damage("jing",(200 - me->query_con()));
		me->receive_damage("qi",(200 - me->query_int()));
		me->add("neili",- (200 - me->query_int()));
		me->delete_temp("last_damage_from");
	}
	return;
}
int valid_leave(object me,string dir)
{
	if ( me->query_temp("talking") ) return notify_fail( "你还没有讨论完呢！\n" );
	return ::valid_leave(me, dir);
}
