// xihuazic by wyz

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("西华子", ({ "xihua zi", "zi", "xihua" }) );
	set("gender", "男性");
	set("age", 29);
	set("long",@LONG
他就是昆仑派的大师兄，为人好打抱不平，嫉恶如仇。他长得矮矮胖
胖的。
LONG
);
	set("attitude", "peaceful");
	set("str", 25);
	set("shen_type",1);
	set("int", 35);
	set("con", 50);
	set("per", 28);
	set("dex", 80);
	set("jingli",2000);
	set("max_jingli",2000);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali",150);
	set("rank_info/respect", "大师兄");             
	set("combat_exp",800000);
 
        set_skill("perception",200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("xuantian-force", 200);
        set_skill("sword", 200);
        set_skill("literate",200);
        set_skill("zhengliangyi-sword", 200);
        set_skill("yaoming-dodge", 200);
        set_skill("sanyin-unarmed",200);
        set_skill("unarmed",200);
        set_skill("strike",200);
	set_skill("cuff", 200);
	set_skill("zhentian-quan",200);
	set_skill("leg",200);
	set_skill("chuanyun-tui",200);
	set_skill("kunlun-zhang",200);
       
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

	create_family("昆仑派", 15, "大师兄");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
}
void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为昆仑派出力啊。");
	command("recruit " + ob->query("id"));
 }
void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
