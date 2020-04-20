// duanzc.c 段正淳

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("段正淳", ({ "duan zhengchun", "duan" }));
	set("title",  "大理镇南王" );
	set("long",@LONG
他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。
LONG
);
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("cuff", 800);
	set_skill("strike", 800);
	set_skill("sword", 800);
	set_skill("staff", 800);
	set_skill("finger", 800);
	set_skill("unarmed",800);
	set_skill("kurong-changong", 800);
	set_skill("tiannan-step", 800);
	set_skill("jinyu-quan", 800);
	set_skill("wuluo-zhang", 800);
	set_skill("duanjia-sword", 800);
	set_skill("sun-finger", 800);
	set_skill("literate", 800);
	set_skill("liumai-shenjian",800);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "liumai-shenjian");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 20);

	create_family("大理段家",18,"镇南王");

}
void attempt_apprentice(object ob)
{
	string oldtitle;
	string name,old_name,new_name;
	name = ob->query("name");
	old_name=lower_case(name);
	oldtitle = ob->query("dali_title");
	if ((int)ob->query_skill("kurong-changong",1) < 400 ){
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if ((int)ob->query("shen") < 100000  ) {
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
	if ((string)ob->query("gender") != "男性")
	{
		command("say 我只收男弟子。");
		return;
	}

	oldtitle = ob->query("dali_title");
	if(strsrch(oldtitle, "大理镇南王府") >= 0) {
		command("say 很好，既然入我门来就得忠心为主。");
		command("recruit " + ob->query("id"));
		name = ob->query("name");
		name = replace_string(name,"段","");
		switch(strlen(name)){
			case 2:	new_name = "段" + name;break;
			case 4:	new_name = "段" + name[2..4];break;
			case 6: new_name = "段" + name[4..6];break;
			case 8: new_name = "段" + name[6..8];break;
			default:
		}
		ob->set("name",new_name);
		ob->set("dali_title", oldtitle);
	}
	else
		{
		command("say 你是何人，如此大胆，假冒我府中厮仆！");
		return;
	}
}
