//Cracked by Kafei
// laoshu.c 老鼠

inherit NPC;

void create()
{
	set_name("老鼠", ({ "lao shu", "shu", "mouse" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只赃兮兮的小老鼠。\n");
	set("attitude", "peaceful");
	set("eatable",1);
	set("afterdie","/clone/food/rat-meat");
	set("combat_exp", 100);
	set_temp("apply/attack", 5);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);
	setup();
}
