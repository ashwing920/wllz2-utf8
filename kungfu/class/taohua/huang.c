
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_yuxiao();

void create()
{
	set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
	set("title", "桃花岛主");
	set("nickname", HIY "东邪" NOR );
	set("gender", "男性");
	set("age", 42);
	set("long",@LONG
他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。
LONG
);
	set("attitude", "peaceful");
	set("class", "scholar");

	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);
	set("chat_msg", ({
		"黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
		"黄药师低头沉思，悠然不语。\n",
	}));
	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "powerup" :),
		(: perform_action, "parry.tianwai" :),
		(: perform_action, "sword.hua" :),
		(: perform_action, "finger.hui" :),
		(: perform_action, "finger.jinglei" :),
		(: perform_action, "unarmed.kuangfeng" :),
	}) );

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);

	set("book_count",1);
	set("get_yuxiao",1);
	set("combat_exp",51200000);
	set("shen_type",1);
	
	set_skill("music",400);
	set_skill("cuixin-zhang",800);
	set_skill("force", 800);
	set_skill("bibo-shengong", 800);
	set_skill("hand", 800);
	set_skill("finger", 800);
	set_skill("tanzhi-shentong", 800);
	set_skill("unarmed", 800);
	set_skill("strike", 800);
	set_skill("luoying-zhang", 800);
	set_skill("xuanfeng-leg", 800);
	set_skill("dodge", 800);
	set_skill("anying-fuxiang", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("luoying-shenjian", 800);
	set_skill("yuxiao-jian", 800);
	set_skill("lanhua-shou", 800);
	set_skill("qimen-wuxing",800);
	set_skill("count",800);
	set_skill("literate",800);

	map_skill("force"  , "bibo-shengong");
	map_skill("finger" , "tanzhi-shentong");
	map_skill("hand"   , "lanhua-shou");
	map_skill("strike", "luoying-zhang");
	map_skill("unarmed" , "xuanfeng-leg");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "yuxiao-jian");
	map_skill("sword"  , "luoying-shenjian");
	prepare_skill("unarmed","xuanfeng-leg");
	prepare_skill("strike","luoying-zhang");

	set("inquiry", ([
		"秘籍"   : (: ask_me :),
		"旋风扫叶腿法" : (: ask_me :),
		"黄蓉"   : "你敢直称我女儿的闺名？ \n",
		"玉箫" : (: ask_yuxiao :),
	]));
	create_family("桃花岛", 1, "岛主");
	setup();
	carry_object(__DIR__"obj/yuxiao")->wield();
	carry_object(__DIR__"obj/bupao")->wear();
	carry_object("clone/book/jiuyin2");

}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
		command("say 我不收资质差的弟子，您请回吧！");
		return;
	}
	if ((int)ob->query_skill("bibo-shengong",1) < 300 ) {
		command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
		return;
	}
	if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
		command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 200) {
		command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
		return;
	}

	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	object ob;

	if((string)this_player()->query("family/family_name") != "桃花岛")
		return RANK_D->query_respect(this_player()) + "非我弟子，不知此话从何谈起？";

	if((int)this_player()->query_skill("xuanfeng-leg",1) < 120)
		return RANK_D->query_respect(this_player()) +"的旋风扫叶腿火候不足，还需多加努力啊。";

	if(query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";

	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("听说%s拿到旋风扫叶腿法了。",this_player()->name()));
	return "好吧，这本「旋风扫叶腿法」你拿回去好好钻研。";
}
string ask_yuxiao()
{
	object ob;
	
	if(this_player()->query("family/family_name") != "桃花岛")
		return RANK_D->query_respect(this_player()) + "与我派素无来往，不知此话从何说起？";
	
	if(query("get_yuxiao") < 1)
		return "你来晚了，玉箫我已经给其他弟子了。";
	
	if(this_player()->query_skill("music",1) < 120)
		return "我桃花岛弟子都是文雅之人，这位"+ RANK_D->query_respect(this_player())+"的五音十二律还需要多多研究呀。";

	add("get_yuxiao",-1) ;
	ob=new(__DIR__"obj/yuxiao");
	ob->move(this_player());
	return "既然你对音律方面有这般兴趣，我就把这把玉箫送给你，希望你好好领悟。";
}
