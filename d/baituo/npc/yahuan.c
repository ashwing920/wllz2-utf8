// woman.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("丫环", ({ "ya huan","ya","huan"}) );
	set("gender", "女性" );
	set("age", 14);
	set("long", "一个很能干的丫环。\n");
	set("shen_type", 1);
	set("combat_exp",10000+ random(10000));
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

