// monkey.c

inherit NPC;

void create()
{
	set_name("猴子", ({ "monkey" }) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 5);
	set("long","这只猴子在在桃树间跳上跳下，还不时津津有味地啃几口着蜜桃。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("water", 200);
	set("food", 200);
	set("apply/attack", 10);
	set("apply/defense", 10);
	set("chat_chance",5);
	set("chat_msg", ({
		"猴子冲着你大扮鬼脸，叽叽歪歪一阵乱叫......！\n",
		"猴子轰的一声一起从这株树跳到那株树，把你吓了一大跳！\n",
	}) );
	setup();
}
