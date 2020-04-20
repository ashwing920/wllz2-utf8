// lazhang.c  拉章活佛 
 
#include <ansi.h> 

inherit NPC; 
inherit F_MASTER; 

string ask_for_join();

void create() 
{ 
	set_name("拉章活佛", ({ "lazhang huofo", "huofo", "lazhang" })); 
	set("long",@LONG 
拉章活佛是雪山寺有道的高僧，对佛法有精深的研究。他身穿一件黄色袈
裟，头带僧帽。慈眉善目，似乎手无缚鸡之力。 
LONG 
); 

	set("gender", "男性"); 
	set("age", 50); 
	set("attitude", "peaceful"); 
	set("shen_type", -1); 
	set("str", 30); 
	set("int", 30); 
	set("con", 30); 
	set("dex", 30); 

	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 6000); 
	set("max_neili",6000); 
	set("jiali",225); 
	set("combat_exp",2700000); 
	set("score", 30000); 

	set_skill("longxiang",300);
	set_skill("necromancy",300);
	set_skill("force",300);
	set_skill("xiaowuxiang",300);
	set_skill("dodge",300);
	set_skill("shenkong-xing",300);
	set_skill("unarmed",300);
	set_skill("yujiamu-quan",300);
	set_skill("parry",300);
	set_skill("sword",300);
	set_skill("mingwang-jian",300);
	set_skill("lamaism",300);
	set_skill("literate",300);
	set_skill("staff",300);
	set_skill("xiangmo-chu", 300);
	set_skill("strike",300);
	set_skill("huoyan-dao", 300);
	set_skill("hammer",300);
	set_skill("riyue-lun",300);
	set_skill("magic",300);
	set_skill("essencemagic",300);
	set_skill("dashou-yin",300);
	set_skill("hand",300);
	map_skill("magic","essencemagic");
	map_skill("hammer","riyue-lun");
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "yujiamu-quan");
	map_skill("staff", "xiangmo-chu");
	map_skill("hand", "dashou-yin");
	map_skill("sword","mingwang-jian");
	map_skill("strike","huoyan-dao");
	prepare_skill("hand", "dashou-yin");
	prepare_skill("unarmed", "yujiamu-quan");
 
	create_family("雪山寺", 3, "活佛"); 
	set("class", "lama"); 

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
	]));

	setup(); 
 
	carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
	carry_object("/d/xueshan/obj/sengmao")->wear(); 
 
	add_money("silver",100);
} 
 
 
void attempt_apprentice(object ob) 
{ 
 
	if ((string)ob->query("gender") != "男性") { 
		command("say 修习密宗内功需要纯阳之体。"); 
		command("say 这位" + RANK_D->query_respect(ob) + "还是请回吧！"); 
		return; 
	} 
 
	if ((string)ob->query("class") != "lama") { 
		command("say 我佛门的清规戒律甚多。"); 
		command("say 这位" + RANK_D->query_respect(ob) + "还是请回吧！");
		ob->set_temp("pending/join_bonze", 1);
		command("say 施主若真心皈依我佛，就请跪下(kneel)受戒。\n");

		return; 
	} 
 
	if ((string)ob->query("family/family_name") != "雪山寺"){ 
		command("say 这位" + RANK_D->query_respect(ob) + "既非本寺弟子，还是请回吧！");
		command("say 这位" + RANK_D->query_respect(ob) + "不如先跟葛伦布师傅学习？");
		return; 
	} 
 
	if ((int)ob->query_skill("lamaism", 1) < 200) { 
		command("say 入我雪山寺，修习密宗心法是首要的。"); 
		command("say 这位" + RANK_D->query_respect(ob) + "是否还应该多多钻研本门的心法？");
		return; 
	} 
 
	command("nod"); 
	command("say 你就随我学习佛法吧！"); 
	command("recruit " + ob->query("id")); 

}

void init()
{
	add_action("do_kneel", "kneel");

}

string ask_for_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="lama" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";

	if( (string)me->query("gender") != "男性" )
		return "施主若真心向佛，真是可喜可贺，可惜本寺只收男徒。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_bonze") )return 0;

	message_vision("$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",me, this_object() );

	command("smile");
	me->set("class", "lama");
	return 1;
}

