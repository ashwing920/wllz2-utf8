// 玩家家丁.c 家丁

inherit NPC;

void create()
{
        set_name("家丁", ({ "jia ding", "jia" }));
        set("gender", "男性");
        set("age", 16);

        set("combat_exp", 3000);
        set("player_waiter",1);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
        setup();

        add_money("silver",3);
        carry_object("/clone/cloth/cloth")->wear();
}


void init()
{
	add_action("do_fangmu", "fangmu");
}
int do_fangmu(string arg)
{
	object me, horse;

	me = this_player();

	if(me->query_temp("fangmu"))
		return notify_fail("你正在放牧！\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法放牧！\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(!objectp(horse = me->query_temp("ride_ob"))
	|| !present(horse,me))
		return notify_fail("你要牧什么？\n");

	message_vision("$N开始放牧“" + horse->name() + "”....\n", me);
                tell_object(me, "你的“" + horse->name() + "”已经精神百倍了！\n" );
                horse->set("horse_prop/life",horse->query("horse_prop/max_life"));
                me->start_busy(5);
	return 1;
}
