#include <ansi.h>
inherit NPC;

void create()
{
	set_name("张夫人", ({ "zhang furen", "zhang",}));
	set("long", @LONG
这女子肌肤微黄，双眼极大，黑如点漆。她掌管日月教在苗疆的下属“五
毒教”，使毒手法诡秘奇特，令人防不胜防。
LONG
);
	set("nickname",HIW"日月神教白虎堂旗主"NOR);
	set("gender", "女性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",150);
	set("combat_exp",100000);

	set_skill("wuchang-zhang",100);
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
	map_skill("staff", "wuchang-zhang");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/weapon/staff")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
