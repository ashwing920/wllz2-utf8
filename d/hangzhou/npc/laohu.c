// laofu.c 老虎
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("老虎", ({ "laohu", "tiger","hu" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", @LONG
一只斑斓猛虎，雄伟极了。
LONG);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("combat_exp", 30000);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 300);
	set_temp("apply/armor",100);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"老虎在浚巡，吓得你大气都不敢出。\n",
		"老虎仰天长啸，声震山谷，黄叶纷坠。\n",
	}) );
}

