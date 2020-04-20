//modified by potato,Sep 6,1999

#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("许雪亭", ( { "xu xueting", "xu" }) );
	set("title", "神龙教青龙使");
	set("nickname", HIR "热血神龙" NOR);
	set("gender", "男性" );
	set("age", 55);
	set("long",@LONG
这是个五十来岁的高瘦汉子，着一袭青衣，昂然挺立。
LONG
);

	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	set("shen_type",-1);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);

	set("jing",2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);
	set("score", 2500);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("poison",200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("taoism", 200);
	set_skill("literate", 200);
	set_skill("sword",200);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("inquiry", ([
		"百花腹蛇膏" : (: ask_gao :),
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"口号" : "\n万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"许雪亭忽然一怕脑袋，说：对了，可以用百花腹蛇膏！\n",
		"许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘么手里了！\n",
		"许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。\n",
	}) );
	setup();
	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
int ask_gao()
{
say(
"\n许雪亭悄声对你说：这可是本教禁物啊。它一遇鲜血，便生浓香，\n"
"我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气\n"
"一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？\n"
);
	return 1;
}

int accept_object(object who, object ob)
{
	object obn;

	if(!who || environment(who) != environment() ) return 0;
	if(!objectp(ob)) return 0;
	if(!present(ob, who))
		return notify_fail("你没有这件东西。\n");
	if((string)ob->query("name") != "腹蛇胆"
		&& (string)ob->query("name") != HIG "百香花" NOR )
		return notify_fail("许雪亭摇头道：如果杀不了洪安通，给我什么也没用啊。。。\n");
	if((string)ob->query("name") == "腹蛇胆" ){
		  if(query_temp("baixianghua")){
		  message_vision("\n许雪亭见是腹蛇胆，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
		  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
			return 1;
	}
		else	{
		if(query_temp("fushedan")){
			message_vision("\n许雪亭见是腹蛇胆，对$N摇头道：腹蛇胆我有了，就差百香花了。\n",who);
			return 0;
	}
		else	 {
		message("vision","许雪亭看见腹蛇胆，大喜道：有了腹蛇胆，只差百香花了。\n",environment(who));
		set_temp("fushedan",1);
		return 1;
			}
		}
	}
	if ( (string)ob->query("name") == HIG "百香花" NOR){
		  if(query_temp("fushedan")){
		  message_vision("\n许雪亭见是百香花，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
		  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
		  return 1;
	}
		else	{
	if(query_temp("baixianghua")){
		message_vision("\n许雪亭见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。\n",who);
		return 0;
	}
		else	 {
		message("vision","许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。\n",environment(who));
		set_temp("baixianghua",1);
		return 1;
			}
		}
	}
}

int recognize_apprentice(object ob)
{
	if (!ob->query("shenlongjiao")){
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+"你我素不相识，我凭什么要教你呢？ \n");
		return 0;
		}
	return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="xu" )return 0;
	if(wizardp(ob)) return 0;
	if (!ob->query("shenlongjiao")){
		message_vision("$N摇了摇头。\n",this_object());
		write("许雪亭说道：你怎么能看我的武功呢？\n");
		return 1;
	}
	command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)			 - 一代宗师  200/	\n"+
"  基本内功 (force)			 - 一代宗师  200/	\n"+
"  读书写字 (literate)			  - 了然於胸  200/	\n"+
"  基本招架 (parry)			 - 一代宗师  200/	\n"+
"  基本剑法 (sword)			 - 深不可测 100/	\n"+
"□太极剑法 (taiji-jian)			- 一代宗师  200/	\n"+
"□太极拳 (taiji-quan)			  - 登峰造极  200/	\n"+
"□太极神功 (taiji-shengong)		- 登峰造极  200/	\n"+
"  道学心法 (taoism)			- 深不可测 200/	\n"+
"□梯云纵 (tiyunzong)			   - 登峰造极  200/	\n"+
"  基本拳脚 (unarmed)			   - 一代宗师  200/	\n");
	return 1;
}

