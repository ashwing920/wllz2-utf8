// masteryue.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("何太冲", ({ "master he", "master","he" }) );
        set("nickname", YEL "昆仑掌门" NOR);
        set("gender", "男性");
        set("age", 42);
        set("long",@LONG
他就是昆仑派掌门何太冲。他看上去是个和善的中年人，对人总是彬
彬有礼，很有一代宗师的风范。
LONG
);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);

        set("shen_type",1);
        set("jingli",6000);
        set("max_jingli",6000);
        set("neili",6000);
        set("max_neili",6000);
        set("jiali",225);
        set("rank_info/respect", "何掌门");     
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

        set("inquiry", ([
                "何足道" : "那是本派祖师爷。\n",
                "何三圣" : "那是本派祖师爷。\n",
                "五姑" : "那是我的小妾。唉，不过现在病了。\n",
                "班淑娴" : "嘘！别那么大声。\n",
        ]));
        set("chat_chance", 5);
        set("chat_msg", ({
                "何太冲叹道：五姑的病越来越重了，唉 . . . \n",
                "何太冲说道：谁帮我治好五姑的病，我一定重谢他。\n",
        }));
        
        map_skill("dodge", "yaoming-dodge");
        map_skill("force", "xuantian-force");
        map_skill("parry", "zhengliangyi-sword");
        map_skill("sword", "zhengliangyi-sword");
        map_skill("unarmed","sanyin-unarmed");   
        map_skill("leg","chuanyun-tui");
        map_skill("strike","kunlun-zhang");
        map_skill("cuff","zhentian-quan");
 
        create_family("昆仑派", 14, "掌门");
	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike","zhentian-quan");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/sword")->wield();
}
void init()
{       
        object ob; 

        if( interactive(ob = this_player()) && !is_fighting() )  { 
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ((string)this_player()->query("family/family_name")!="昆仑派"){
        switch( random(3) ) {
                case 0:
                        say( "何太冲笑咪咪地说道：这位" + RANK_D->query_respect(ob)+ "，到我昆仑派来有何贵干。\n");
                        break;
                case 1:
                        say( "何太冲搓了搓手，说道：这位" + RANK_D->query_respect(ob)+ "可是来自中原？可认识什么名医？\n");
                case 2:
                        say( "何太冲拱了拱手，说道：这位" + RANK_D->query_respect(ob)+ "可曾学过医术？\n");
                        break;
                }
        } else {
        switch( random(2) ) {
                case 0:
                        say( "何太冲搓了搓手，说道：乖徒儿，你可是来自中原？可认识什么名医？\n");
                        break;

                case 1:
                        say( "何太冲尴尬地笑道：乖徒儿，你可曾学过医术？\n");
                        break;
                 }
        }
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "男性" ){
                command("say 我不收女弟子的，姑娘还是另访名师吧。");
                return;
        }

        if ((int)ob->query_skill("force", 1) < 200) {
                command("say " + RANK_D->query_respect(ob) + "是否还应该多练练内功心法？");
                return;
        }
        command("recruit " + ob->query("id"));

}

