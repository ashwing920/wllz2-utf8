// Npc: /kungfu/class/shaolin/dao-pin.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("道品禅师", ({"daopin chanshi","daopin","chanshi",}));
	set("long",@LONG
他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿
一袭灰布镶边袈裟，似乎有一身武艺。
LONG
);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("max_jing",1000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp", 800000);
	set("score", 100);

	set_skill("force", 200);
	set_skill("hunyuan-yiqi", 200);
	set_skill("dodge", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("finger", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("blade", 200);
	set_skill("cibei-dao", 200);
	set_skill("parry", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	prepare_skill("finger", "nianhua-zhi");

	create_family("少林派", 39, "弟子");

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

#include "/kungfu/class/shaolin/dao.h"

