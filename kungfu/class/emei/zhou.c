// zhou.c 周芷若

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("周芷若", ({ "zhou zhiruo","zhiruo","zhou"}));
	set("long",@LONG
她是峨嵋派的第四代掌门弟子。一张脸秀丽绝俗。身着一身淡黄衣裳。
略显清减的巧笑中带了些许无奈。她很寂寞。
LONG
);
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
	}) );
	set("inquiry",([
		"剃度"	: "找我剃度？不对吧。",
		"出家"	: "要出家找我的师姐们去。",
		"还俗"	: "无聊。还俗也找我！",
		"张无忌"  : "这个狠心短命的家伙，我再也不要见她！",
		"赵敏"	: "不要问这个贱婢子！",
		"倚天剑"  : "师父把她交给纪师姊了。",
		"屠龙刀"  : "你想武林称雄？别做梦了。",
		"灭绝师太"  : "师父难得收徒。你先巴结我吧。",
	]));
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);

	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("jingli",3000);
	set("max_jingli",3000);

	set("combat_exp", 6400000);
	set("score",10000);

	set_skill("yitian-sword", 400);
	set_skill("persuading", 400);
	set_skill("force", 400);
	set_skill("throwing", 400);
	set_skill("dodge", 400);
	set_skill("finger", 400);
	set_skill("parry", 400);
	set_skill("unarmed", 400);
	set_skill("strike", 400);
	set_skill("sword", 400);
	set_skill("claw", 400);
	set_skill("literate", 400);
	set_skill("mahayana", 400);
	set_skill("jinding-zhang", 400);
	set_skill("jiuyin-baiguzhao", 400);
	set_skill("tiangang-zhi", 400);
	set_skill("huifeng-jian", 400);
	set_skill("zhutian-bu", 400);
	set_skill("linji-zhuang", 400);
	set_skill("blade",400);
	set_skill("yanxing-dao",400);
	map_skill("blade","yanxing-dao");
	map_skill("force","linji-zhuang");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","yitian-sword");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 4, "掌门弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/emei/obj/ycloth.c")->wear();
}

void attempt_apprentice(object ob)
{

   if (ob->query("shen")<100)
   {
	   command("heng");
	   command("say " + ob->query("name") + "！你是什么东西？偷睹我面容，打扰我清修！");
	   command("!!! " + ob->query("id"));
	   kill_ob(this_player());
   }
   else
	  if ( ob->query_temp("marks/宋夫人") )
	  {
	if ( (int)ob->query("combat_exp") > 200000 &&
		 (int)ob->query("betrayer") > (int)ob->query("K_betrayer"))
	{
		 command("heng");
		 command("say 象你这样不守门规，三心二意。我怎能再收你为徒。");
		 return;
	}
	if ((int)ob->query("per") < 22 )
	{
		command("giggle");
		command("say 这位"+RANK_D->query_respect(ob)+"容貌太也...，哎！还是请回吧！");
	   return ;
	}
	if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 )
	{
	   command("say 这位"+RANK_D->query_respect(ob)+"恐怕资质差了一点。");
	   command("say 不过尚大有潜力，还是先回去磨练磨练。");
	   return ;
	}
	command("say" + ob->query("name") + "看你这么可怜，勉为其难收下你吧。\n");
	command("recruit " + ob->query("id"));
	ob->delete_temp("marks/宋夫人");
	  } 
	  else command("say " + this_player()->query("name") + "你没事就可以走了。\n\n");
   return;
}
