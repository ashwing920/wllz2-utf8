// tiger.c 老虎
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("老虎", ({ "tiger", "laohu", "hu" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", @LONG
一只斑斓猛虎，雄伟极了。
LONG
);
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 30000+random(20000));
	set_temp("apply/attack", 20000);
	set_temp("apply/defense", 30000);
	set_temp("apply/armor", 1000);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"老虎在浚巡，吓得你大气都不敢出。\n",
		"老虎仰天长啸，声震山谷，黄叶纷坠。\n",
	}) );
}

