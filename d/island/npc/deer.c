//Cracked by Kafei
// yetu.c 野兔

inherit NPC;

void create()
{
	set_name("梅花鹿", ({ "meihua lu", "lu", "deer" }) );
	set("race", "野兽");
	set("age", 5);
	set("long","一只温顺的梅花鹿，睁着圆圆的眼珠望着你，显得十分好奇。\n");
	set("attitude", "peaceful");
	set("combat_exp", 500);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 12);
	set_temp("apply/armor", 11);
	setup();
}
