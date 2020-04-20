// shihou.c 狮吼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("nickname", "星宿派二师兄");
	set("long", @LONG
他就是丁春秋的二弟子狮吼子。他三十多岁，狮鼻阔口，一望而知不是中
土人士。
LONG
);
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);

	set("jing",3000);
	set("max_jing", 3000);
	set("neili",4500);
	set("max_neili", 4500);
	set("jiali",225);
	set("combat_exp", 2700000);

	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("poison", 300);
	set_skill("literate",300);
	set_skill("unarmed", 300);
	set_skill("force", 300);
	set_skill("throwing", 300);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("claw", 300);
	set_skill("feixing-shu", 300);
	set_skill("zhaixinggong", 300);
	set_skill("chousui-zhang", 300);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("huagong-dafa", 300);
	set_skill("tianshan-zhang", 300);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	map_skill("unarmed","chousui-zhang");
	map_skill("throwing","feixing-shu");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/xingxiu/obj/yao");
        carry_object("/d/xingxiu/obj/fire");
}

void attempt_apprentice(object ob)
{
	if(ob->query_skill("zhaixinggong",1) < 200)
{
	command("say 摘星功是星宿派的独门绝技之一，依我看，你的摘星功还未到火候呀！");
	return;

	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
