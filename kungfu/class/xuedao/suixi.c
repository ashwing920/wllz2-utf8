//shanyong.c  随喜

#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("随喜", ({ "sui xi", "sui", "xi" }));
	set("long",@LONG
一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。
LONG
);

	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
	set("score",10000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.jtmd" :),
		(: perform_action, "strike.xue" :),
		(: perform_action, "strike.jue" :),
		(: perform_action, "unarmed.luan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	set_skill("lamaism", 100);
	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("xuehai-mogong", 100);
	set_skill("xuedun", 100);
	set_skill("strike", 100);
	set_skill("miexian-zhang", 100);
	set_skill("xue-dao", 100);
	set_skill("unarmed",100);
	set_skill("wuying-shenquan",100);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	create_family("血刀门",6,"弟子");
	set("class", "bonze");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xuedao")->wield();
}
