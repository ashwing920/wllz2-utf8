// ny netkill

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("何铁手", ({ "he tieshou", "he" }));
	set("title", "五毒神教教主");
	set("long", "她凤眼含春，长眉入鬓，嘴角含着笑意，甚是美貌。\n");
	set("gender", "女性");
	set("age", 21);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);


	set_skill("force", 800);
	set_skill("wudu-shengong", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("wudu-bian",800);
	set_skill("wudu-zhang",800);
	set_skill("wudu-xinfa",800);
	set_skill("whip",800);		
	set_skill("guimei-shenfa", 800);
	set_skill("strike",800);
	set_skill("pour",800);
	set_skill("literate",800);
	set_skill("unarmed",800);
	set_skill("poison",800);
	set_skill("hook",800);
//	set_skill("wudu-gou",800);
	
//	map_skill("hook","wudu-gou");
	map_skill("unarmed","wudu-zhang");
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "guimei-shenfa");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-bian");
	map_skill("whip", "wudu-bian");

	create_family("五毒神教", 18, "教主");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	setup();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/d/wudu/obj/shenyi")->wear();
	add_money("gold",1);
}

void init()
{	
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") > -10000 ) {
		command("say 若不心狠手辣，如何能学得高深的毒术。");
		return;
	}
	if ( (int)ob->query_skill("wudu-xinfa",1) < 300 )
		{command( " say 你的五毒心法太低了，学不了高深的武功 ");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	ob->set("title",HIW "五毒神教教主座下弟子" NOR);
	
}

