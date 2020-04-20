// animal: eat_fish.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("噬人鱼", ({ "fish", "yu" }) );
	set("race", "游鱼");
	set("age", 3);
	set("long", "这是一只身形并不很大的鱼，浑身覆满绚丽的鳞片，\n"
		"一口锋利的牙齿，正虎视耽耽的看着你\n");
	set("attitude", "aggressive");
	set("max_qi",1000);
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 1000000);
	set("eatable",1);
	set("afterdie","/d/npc/m_weapon/tan/item/zhenzhu");
	set_temp("apply/attack", 45);
	set_temp("apply/damage", 60);
	set_temp("armor", 53);
	setup();
}
