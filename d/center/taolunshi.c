// taolunshi.c - 武学讨论室

inherit ROOM;

string look_sign();

void create()
{
	set("short", "武学讨论室");
	set("long", @LONG
这里是桃源城的武学讨论室。这里常常挤满了形形色色的武林人士，
是广交天下武林同道的好地方。在讨论室的墙上挂着一幅龙飞凤舞的字画
，上面写着“尚武”两个大字，据说是出自华山剑圣风清扬之手。墙的另
一面，挂着一块牌子（sign）。
LONG
);

	set("item_desc", ([
		"sign": @TEXT
大家一起来讨论武学的秘密吧。

join        加入讨论
chat        自由发言

TEXT
	]) );

	set("exits", ([
		"west"  : __DIR__"roads7",
	]) );
	set("no_magic",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	setup();
}
void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me, env, *inv;
	int total, i;

	me = this_player();

	if(me->query_temp("talking") == 1) return notify_fail("你已经在讨论当中了！\n");

	env = environment(me);
	inv = all_inventory(env);
	for(i = 0, total = 1 ; i < sizeof(inv); i++) {
		if( inv[i] == me ) continue;
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if( !userp(inv[i])) continue;
		total ++;
	}
	if( total <= 1 ) return notify_fail("这里没有人和你讨论！\n");

	message_vision("$N开始加入有关武学秘密的讨论....\n", me);
	me->set_temp("talking", 1);
	call_out("compelete_join",30,me);
	return 1;
}

private void compelete_join(object me)
{
	int i, m, n;

	if(!me) return;
	me->delete_temp("talking");
	if( present(me) ) {                     // 如果玩家还在原地
		message_vision("$N和大家讨论了很久，收益不小。\n", me);
		i = me->query_con() + me->query_spi();
		m = (random(i) + 1) / 3;
		n = m + random(8);
		me->add("potential", m);
		me->add("combat_exp", n);
		tell_object(me, sprintf("你的潜能增加了%d点！\n", m));
		tell_object(me, sprintf("你的经验增加了%d点！\n", n));
	}

	return;
}

int valid_leave(object me,string dir)
{
	if ( me->query_temp("talking") ) return notify_fail( "你还没有讨论完呢！\n" );
	return ::valid_leave(me, dir);
}
