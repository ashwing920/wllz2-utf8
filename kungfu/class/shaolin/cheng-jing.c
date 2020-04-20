// Npc: /kungfu/class/shaolin/cheng-jing.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("澄净", ({"chengjing luohan","chengjing",}));
	set("long",@LONG
他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，
太阳穴高高鼓起，似乎身怀绝世武功。
LONG
);
	set("nickname", "精进罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing",1000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali",225);
	set("combat_exp", 2700000);
	set("score", 5000);

	set_skill("force", 300);
	set_skill("hunyuan-yiqi", 300);
	set_skill("dodge", 300);
	set_skill("shaolin-shenfa", 300);
	set_skill("claw", 300);
	set_skill("longzhua-gong", 300);
	set_skill("parry", 300);
	set_skill("buddhism", 300);
	set_skill("literate", 300);
	set_skill("unarmed",300);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");

	prepare_skill("claw", "longzhua-gong");

	create_family("少林派", 37, "弟子");

	setup();

	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

