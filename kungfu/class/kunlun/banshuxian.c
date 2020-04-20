//master ban by wyz

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("班淑娴", ({ "ban shuxian", "ban", "shuxian"}) );
	set("nickname",YEL"掌门夫人"NOR);
	set("gender", "女性");
	set("age", 38);
	set("long",@LONG
她就是昆仑派掌门何太冲的妻子。她脾气粗暴，气量狭窄昆仑上下都对她
十分畏惧。她已是三十出头了，仍是风韵尤存。
LONG
);      
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 35);
	set("con", 50);
	set("per", 28);
	set("dex", 80);
	set("jingli",2000);
	set("max_jingli",2000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("rank_info/respect", "掌门夫人");   
	set("combat_exp",2700000);

        set_skill("perception",300);
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("xuantian-force", 300);
        set_skill("sword", 300);
        set_skill("literate",300);
        set_skill("zhengliangyi-sword", 300);
        set_skill("yaoming-dodge", 300);
        set_skill("sanyin-unarmed",300);
        set_skill("unarmed",300);
        set_skill("strike",300);
	set_skill("cuff", 300);
	set_skill("zhentian-quan",300);
	set_skill("leg",300);
	set_skill("chuanyun-tui",300);
	set_skill("kunlun-zhang",300);
       
        map_skill("dodge", "yaoming-dodge");
        map_skill("force", "xuantian-force");
        map_skill("parry", "zhengliangyi-sword");
        map_skill("sword", "zhengliangyi-sword");
        map_skill("unarmed","sanyin-unarmed");   
        map_skill("leg","chuanyun-tui");
        map_skill("strike","kunlun-zhang");
        map_skill("cuff","zhentian-quan");
 
	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike","zhentian-quan");

	create_family("昆仑派", 14, "掌门夫人");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "女性" ){    
		command("say 男人都不是好东西，给我滚。");
		return;
	}

	if ((int)ob->query_skill("force", 1) < 200) {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练内功心法？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
}
