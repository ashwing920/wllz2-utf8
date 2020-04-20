// npc: /d/xingxiu/npc/shachong.c

inherit NPC;

void create()
{
	set_name("沙虫", ({ "sha chong", "chong", "bug" }) );
	set("race","昆虫");
	set("subrace","爬虫");
	set("age", 3);
	set("long", "一只黄褐色的小咀虫，尾巴上有黄蓝相间的环纹。你的直觉告诉你它一定有毒。\n");
	set("attitude", "peaceful");
	set("eatable",1);
	set("afterdie",__DIR__"shachongke");
	set("combat_exp", 300);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 2);
	set_temp("apply/armor", 1);
	setup();
}
