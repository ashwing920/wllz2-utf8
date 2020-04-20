// bear.c

inherit NPC;

void create()
{
	set_name("黑熊", ({ "hei xiong", "bear","xiong" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只凶猛的黑熊，形体硕大，人立而行。\n");
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("combat_exp", 30000);
	set("eatable",1);
	set("afterdie",__DIR__"xiongdan");
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 250);
	set_temp("apply/armor", 100);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"黑熊冲着你摇头摆尾地，不知道是什么意思。\n",
		"黑熊挤了挤鼻子，你觉得它好象在笑，顿时一阵紧张。\n",
	}) );
}
