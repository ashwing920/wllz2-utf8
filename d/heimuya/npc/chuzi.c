inherit NPC;

string ask_me();

void create()
{
	set_name("厨师", ({ "chu zi", "chu" }));
	set("title", "日月神教");
	set("long", 
		"日月神教的一个厨子，笑眯眯地看着你，看来很和善的样子。\n");
	set("gender", "男性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_qi", 200);
	set("max_jing", 50);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("combat_exp", 500);

	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("parry", 10);

	create_family("日月神教", 3, "弟子");
	set("inquiry", ([
		"进餐" : (: ask_me :),
	]));

	setup();
	
}

string ask_me()
{
       object me=this_player();
       
       me->set("food", (int)me->max_food_capacity());
       me->set("water", (int)me->max_water_capacity());
  
	return "慢慢吃！别噎住了。";
}
