// jiaotou.c - 教头

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("教头", ({ "jiao tou","master","jiao" }) );
	set("long", @LONG
他是枫林武馆的教头。高大威猛，看起来好象身手不凡的样子。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 45);
	set("str", 30);
	set("per", 28);
     

	set("combat_exp",100000);
	set("shen_type",1);

	set("env/wimpy", 30);
	set_skill("spear",200);
	set_skill("chixie-qiang",200);
	set_skill("unarmed",200); 
	set_skill("force",200);
	set_skill("parry",100);
	set_skill("dodge",100);
	set_skill("perception",100);
	map_skill("spear","chixie-qiang");
	map_skill("parry","chixie-qiang");
	set("inquiry", ([
		"学费"     : "嗯....知识是无价的，不过如果你有心的话——只要十两银子。\n",
	]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
	add_money("silver", 10);
}
void init()
{
	add_action("do_skills","skills");
	add_action("do_skills","cha");
}
int do_skills(string arg)
{
	object ob;
	ob = this_player();

	if(!id(arg) || !ob->query_temp("mark/教头")) return 0;
	tell_object(ob,name() +"说道：你可以从我这里学习以下这些武功：\n\n");
	write(@TEXT
─────────────────────────────────
  赤蝎枪法[chixie-qiang]                   - 心领神会 200/    0
  基本轻功[dodge]                          - 平平淡淡 100/    0
  基本内功[force]                          - 心领神会 200/    0
  基本招架[parry]                          - 平平淡淡 100/    0
  听风辨器[perception]                     - 平平淡淡 100/    0
  基本枪法[spear]                          - 心领神会 200/    0
  基本拳脚[unarmed]                        - 心领神会 200/    0
─────────────────────────────────
TEXT);
	return 1;

}
int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/教头")){
		say(this_object()->query("name") + "说道：咦？我不记得收过你这个学生啊....\n");
		return 0;
	}
	ob->add_temp("mark/教头", -1);
	return 1;
}

int accept_object(object who, object ob)
{

	if (!(int)who->query_temp("mark/教头"))
		who->set_temp("mark/教头", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		say(this_object()->query("name") + "点了点头，说道：很好，"+ "从今天起你随时可以来向我学习各种粗浅功夫。\n");
		who->add_temp("mark/教头", ob->value() / 10);
		return 1;
	 }
}
