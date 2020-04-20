// shihou.c 出尘子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("出尘子", ({ "chuchen zi", "chuchen" }));
        set("nickname", "星宿派八师兄");
        set("long", @LONG
他就是丁春秋的八弟子出尘子。他身才矮胖，可手中握的钢杖又长又重。
LONG
);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);

        set("jing",1000);
        set("max_jing",1000);
        set("neili", 1000);
        set("max_neili",1000);
        set("jiali",75);
        set("combat_exp", 100000);
        set("score", 20000);

	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("poison", 100);
	set_skill("literate",100);
	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("throwing", 100);
	set_skill("dodge", 100);
	set_skill("strike", 100);
	set_skill("claw", 100);
	set_skill("feixing-shu", 100);
	set_skill("zhaixinggong", 100);
	set_skill("chousui-zhang", 100);
	set_skill("sanyin-wugongzhao", 100);
	set_skill("huagong-dafa", 100);
	set_skill("tianshan-zhang", 100);

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
        carry_object("/d/xingxiu/obj/yao1");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
}

void init()
{
        object ob;
        mapping myfam;

        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
        if ((!myfam || myfam["family_name"] != "星宿派") &&(!wizardp(ob))
        && ob->query("combat_exp") > 10000 ) {
                this_object()->kill_ob(ob);
                }
        }
}


void attempt_apprentice(object ob)
{
        command("say 老仙还没允许我收徒呢。");
}
