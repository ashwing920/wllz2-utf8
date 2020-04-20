// azi.c 阿紫

inherit NPC;

string ask_me();

void create()
{
        set_name("阿紫", ({ "a zi" }));
        set("nickname", "星宿派小师妹");
        set("long",@LONG
她就是丁春秋弟子阿紫。她容颜俏丽，可眼神中总是透出一股邪气。
LONG
);
        set("gender", "女性");
        set("age", 15);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", -1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);

        set("jing",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("jiali",75);
        set("combat_exp",100000);

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
	carry_object("/d/xingxiu/obj/yao");
	carry_object("/d/xingxiu/obj/yao2");
        carry_object("/d/xingxiu/obj/xxqingxin-san");
        carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/staff")->wield();
}

void attempt_apprentice(object ob)
{
        command("say 嘿！本姑娘没心思收徒弟，去找那老妖怪好了。");
        command("face " + ob->query("id"));

}
