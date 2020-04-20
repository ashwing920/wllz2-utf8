#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("上官云", ({ "shang guanyun", "shang",}));
	set("nickname", "雕侠");
	set("long", @LONG
只见他长手长脚，双目精光灿烂，甚有威势。
LONG
);
	set("title",GRN"日月神教青龙堂主"NOR);
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",3000);
	set("neili",3000);
	set("max_neili",1000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("unarmed", 200);
	set_skill("force",200);
	set_skill("literate", 200);
	set_skill("blade", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("tianmo-zhang",200);
	set_skill("sword", 200);
	set_skill("tianmo-sword",200);
	set_skill("tianmo-dao",200);
	set_skill("piaomiao-shenfa",200);
	set_skill("tianmo-dafa",200);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教", 3, "弟子");
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 老夫从来不受徒弟，"+RANK_D->query_respect(ob)+"还是回去吧。");
	return;
}

