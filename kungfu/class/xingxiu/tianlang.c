// tianlang.c 天狼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("nickname", "星宿派三师兄");
	set("long", @LONG
他就是丁春秋的三弟子天狼子。
LONG
);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);

	set("jing",2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);
	set("score",30000);

	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 200);
	set_skill("literate",200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("throwing", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("feixing-shu", 200);
	set_skill("zhaixinggong", 200);
	set_skill("chousui-zhang", 200);
	set_skill("sanyin-wugongzhao", 200);
	set_skill("huagong-dafa", 200);
	set_skill("tianshan-zhang", 200);

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
        carry_object("/d/xingxiu/obj/yao3");
        carry_object("/d/xingxiu/obj/yao1");
        carry_object("/d/xingxiu/obj/fire");
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("shen") > -1000) {
	command("say 我们星宿派从来不和正派的人打交道，你还是离开吧！");
	return;

	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
