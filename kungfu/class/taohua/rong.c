// rong.c 黄蓉
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_chicken();

void create()
{
	set_name("黄蓉", ({"huang rong", "huang", "rong"}));
	set("title", "桃花岛主独生爱女");
	set("gender", "女性");
	set("age", 18);
	set("long",@LONG 
这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱
。她生性跳脱飞扬，喜欢四处乱跑。
LONG
);

	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("jing",2000);       
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("jia",1);
	
	set("combat_exp",800000);
	set("score", 0);
	
	set_skill("music",200);
	set_skill("force",200);
	set_skill("bibo-shengong", 200);
	set_skill("unarmed", 200);
	set_skill("xuanfeng-leg", 200);
	set_skill("strike", 200);
	set_skill("luoying-zhang", 200);
	set_skill("dodge", 200);
	set_skill("anying-fuxiang", 200);
	set_skill("parry", 200);
	set_skill("literate",200);
	set_skill("sword", 200);
	set_skill("luoying-shenjian",200);
	set_skill("cuixin-zhang",200);
	
	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("sword"  , "luoying-shenjian") ;
	
	create_family("桃花岛", 2, "弟子");

	set("inquiry", ([
		"黄药师" : "爹爹呀, 不在厅里麽? ",
		"郭靖"   : "怎么? 你有我靖哥哥的消息吗? ",
		"洪七公" : "师父他老人家就喜欢吃叫化鸡! ",
		"叫化鸡" : (: ask_chicken :)
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/shudai")->wear();

}

void init()
{
	object ob;
	mapping myfam;

	if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
	if ((!myfam || myfam["family_name"] != "桃花岛")){
		remove_call_out("saying");
		call_out("saying",2,ob);
		}
	}
	add_action("do_kiss", "kiss");
}
int do_kiss ( string arg )
{
	object ob ;
	ob = this_player () ;
	if( !arg )return 1;
	if( arg == "rong" || arg == "huang rong" || arg == "huang") {
	if((string) ob -> query ("gender") == "男性")
		command ("say 救命啊！救命啊！"+ ob->query("name") + "要非礼我！") ;
	else
	message_vision("\n黄蓉对$N笑道：“好姐姐不要这样，我怕痒！”", ob);
	return 1 ;
	}
}
void saying(object ob)
{
	if (!ob || environment(ob) != environment())return;
	if ((string)ob->query("gender") == "男性"){
		command("ah");
		command("say 你是什么人，竟敢乱闯我的闺房？再不滚出去，看我怎么整你！");
		return;
	} else  {
	command("look "+ ob->query("id"));
	command("say 好久没生人来过了，不知这位"+ RANK_D->query_respect(ob)+ "可有我靖哥哥的消息？");
	return;
	}
}

void attempt_apprentice(object ob)
{
	if((int)ob->query_temp("marks/蓉儿")==1
	 && query("jia")){
		say( "黄蓉一脸笑意：“多谢你带来靖哥哥的口信！”\n");
		say( "黄蓉轻轻一笑：我不收徒的..可也不能让你白来，这软猥甲就送给你吧．\n");
	new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
	tell_object(ob,"黄蓉从身上脱下一件软猥甲递给你。\n");
	ob->delete_temp("marks/蓉儿");
	add("jia",-1);
	message("channel:rumor",HIM"【武林传奇】某人："+ ob->name()+"从黄蓉那里拿到软猥甲了！\n"NOR,users());
	}
	else
	command("say 我年纪这么小就收徒弟，岂不让人笑掉大牙！");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/鸡", 1))
		return "你这个人怎么这么烦？老说车轱辘话！\n";
	else{
		command("say 叫化鸡可是杭州著名特产，我爹当年费了好大的劲才搞到了制作它的秘方。");
		command("say 你问它来干什么？");
		this_player()->set_temp("marks/鸡", 1);
		return "你可以出去了。\n";
	}
}
