// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 2);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n"
		"陆大有整天调教得它无比伶俐，现在正骑在陆大有的脖子上。\n");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");
	set("max_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("combat_exp", 50000);
	set_skill("force", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set("chat_chance", 15);
	set("chat_msg", ({
		"小猴伸出小抓挠挠头，冲你扮个鬼脸。\n",
		"小猴懒洋洋地打了个哈欠，爬到陆大有头顶，又翻身下到主人肩头。\n",
		"小猴伸抓捉住了身上的虱子，看了两眼，使劲就是一捏！\n",
	}));
	setup();

}
