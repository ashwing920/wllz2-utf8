#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老头子", ({ "lao touzi", "zi",}));
	set("nickname", "黄河老祖");
	set("long", @LONG
此人身材极之肥胖，远看有如一大肉球般，可身法却极之轻灵，动作如闪
电般迅速。
LONG
);
	set("title",GRN"日月神教青龙堂坛主"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("combat_exp",100000);

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
	carry_object("/d/heimuya/npc/obj/bi")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
