//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
// baima.c 白马

inherit NPC;

void create()
{
	set_name("白马", ({ "bai ma" }));
	set("long","一匹骏马，全身雪白，无一根杂毛。\n");
	set("race","野兽");
	set("age", 5);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 30);
	set("int", 18);
	set("combat_exp", 1000);
	setup();
}
