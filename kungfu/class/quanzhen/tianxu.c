// /d/quanzhen/npc/tianxu.c  天虚子

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("天虚子", ({ "tianxu zi", "tianxu","zi" }));
	set("long",@LONG
他是全真教专门负责炼丹的道人，别看他作不言语，但是他在道家内丹功
夫上，却是全真教中最出色的一个，他是受王重阳的重托，传授内丹术。
在全教中，有非常高的声望，就连丘处机也得对他礼让三分。
LONG
);
	set("title", HIY "道长" NOR);
	set("gender", "男性");
	set("age", 60);
	set("attitude", "heroism");
	set("shen_type",1);
	set("str", 30);
	set("int", 20);
	set("con", 28);
	set("dex", 25);

	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali",225);

	set("combat_exp",2700000);
	set("score", 10000);

	set_skill("force", 300);
	set_skill("xiantian-qigong", 300);
	set_skill("sword", 300);
	set_skill("quanzhen-jian",300);
	set_skill("dodge", 300);
	set_skill("jinyan-gong", 300);
	set_skill("parry", 300);
	set_skill("unarmed",300);
	set_skill("haotian-zhang", 300);
	set_skill("literate",300);
	set_skill("strike",300);
	set_skill("taoism",300);
	set_skill("whip",300);
	set_skill("duanyun-bian",300);
	set_skill("cuff",300);
	set_skill("chunyang-quan",300);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	map_skill("finger","sun-finger");
	prepare_skill("finger","sun-finger");
	prepare_skill("strike","haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	setup();
	carry_object("/clone/weapon/fuchen")->wield();
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

       