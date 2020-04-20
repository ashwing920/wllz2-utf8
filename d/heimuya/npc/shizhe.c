#include <ansi.h>
inherit NPC;

void create()
{
	set_name("护法使者", ({ "shi zhe", "zhe",}));
	set("long", @LONG
此人头上罩着黑色头罩，根本看不见相貌，是由教主请手调教出来的高手
，负责着教坛的守卫。
LONG
);
	set("title",HIW"日月神教护法"NOR);        
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"护法使者高声说道：“教主令旨英明，算无遗策。”\n",
		"护法使者说道：“教主千秋万载，一统江湖。”\n",
		"护法使者高叫道：“教主文成武德，仁义英明，中兴圣教，泽被仓生。”\n",
	}));

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("combat_exp", 10000);

	set_skill("tianmo-zhang",100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);        
	set_skill("piaomiao-shenfa",100);
	set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");

	create_family("日月神教",3,"弟子");

	setup();

	carry_object(__DIR__"obj/dao")->wield();
	carry_object(__DIR__"obj/armor")->wear();
}
void init()
{
	object me, ob;
	mapping fam;

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	 && !ob->query_temp("hmy_enter")
	&& !present("heimu ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "日月神教" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say 你是谁？  怎么闯到日月神教里来了？！");
			command("say 快给我速速离开，下次看到决不轻饶！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到日月神教里来撒野！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       
 }
