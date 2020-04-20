// ai-laozhe.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("矮老者", ({ "ai laozhe", "ai" }));
	set("title", HIG"华山第十二代长老"NOR);
	set("long", @LONG
他就是华山的长老矮老者。一张严肃威严的脸，望而生畏。
LONG
);
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("jing",10000);
	set("max_jing",10000);
	set("neili", 12000);
	set("max_neili",12000);
	set("jiali",600);

	set("combat_exp",51200000);

	set_skill("cuff", 800);
	set_skill("force", 800);
	set_skill("blade", 800);
	set_skill("sword", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("strike", 800);
	set_skill("zixia-shengong", 800);
	set_skill("poyu-quan", 800);
	set_skill("fanliangyi-dao", 800);
	set_skill("huashan-sword", 800);
	set_skill("hunyuan-zhang", 800);
	set_skill("feiyan-huixiang",800);
	set_skill("literate", 800);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "fanliangyi-dao");
	map_skill("blade", "fanliangyi-dao");
	map_skill("sword", "huashan-sword");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山剑派", 12, "弟子");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.sanshen" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{

	if((string)ob->query("family") && (string)ob->query("family/family_name") != "华山剑派"){
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}

	if((int)ob->query_skill("force",1) < 300 || (int)ob->query_skill("zixia-shengong",1) < 300){
		command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功还没学到家吧。");
		return;
	}
	if((int)ob->query_skill("dodge",1) < 300 ||(int)ob->query_skill("feiyan-huixiang",1) < 300){
		command("say 我看" + RANK_D->query_respect(ob) + "的飞燕回翔还没学到家吧。");
		return;
	}

	if ((int)ob->query("shen") < 50000){
		command("say 我华山剑派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}

	if((int)ob->query("spi") < 25 ){
		command("say 依我看"+ RANK_D->query_respect(ob)+"灵性不足，恐怕难以习得气宗要领啊！");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "fighter")
	ob->set("class", "fighter");

}
