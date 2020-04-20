// masteryue.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("何足道", ({ "he zudao", "master","he" }) );
	set("nickname", "何三圣");      
	set("gender", "男性");
	set("age", 162);
	set("long",@LONG
他就是昆仑派的开山祖师，江湖上人称“昆仑三圣”的何足道。
LONG
);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);

        set("shen_type",1);
        set("jingli",8000);
        set("max_jingli",8000);
        set("neili",12000);
        set("max_neili",12000);
        set("jiali",375);
	set("rank_info/respect", "何师祖");
        set("combat_exp",51200000);
 
        set_skill("perception",800);
        set_skill("force", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("xuantian-force", 800);
        set_skill("sword", 800);
        set_skill("literate",800);
        set_skill("zhengliangyi-sword", 800);
        set_skill("yaoming-dodge", 800);
        set_skill("sanyin-unarmed",800);
        set_skill("unarmed",800);
        set_skill("strike",800);
	set_skill("cuff", 800);
	set_skill("zhentian-quan",800);
	set_skill("leg",800);
	set_skill("chuanyun-tui",800);
	set_skill("kunlun-zhang",800);
	set_skill("xunlei-sword",800);

        map_skill("dodge", "yaoming-dodge");
        map_skill("force", "xuantian-force");
        map_skill("parry", "zhengliangyi-sword");
        map_skill("sword", "xunlei-sword");
        map_skill("unarmed","sanyin-unarmed");   
        map_skill("leg","chuanyun-tui");
        map_skill("strike","kunlun-zhang");
        map_skill("cuff","zhentian-quan");
 
	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike","zhentian-quan");
	create_family("昆仑派", 13, "三圣");

	setup();
	
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/d/kunlun/obj/qizi")->wield();
	carry_object("/clone/weapon/sword")->wield();
}
void attempt_apprentice(object ob)
{   
	if ((int)ob->query_skill("xuantian-force", 1) < 300) {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练本门的内功心法？");
		return;
	}
	command("say 好吧，我就收下你吧！");
	command("recruit " + ob->query("id"));
}
