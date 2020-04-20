// hongma.c 红马

inherit NPC;

void create()
{
	set_name("红马", ({ "hong ma" }));
	set("long","一匹骏马，全身火红，无一根杂毛。\n");
	set("race", "野兽");
	set("age", 5);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 30);
	set("int", 18);
	set("combat_exp", 1000);
	setup();
}
