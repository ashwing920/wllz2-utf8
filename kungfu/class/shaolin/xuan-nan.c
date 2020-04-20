// Npc: /kungfu/class/shaolin/xuan-nan.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄难大师", ({"xuannan dashi","xuannan","dashi",}));
	set("long",@LONG
他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材极瘦，两手更
象鸡爪一样。他双目微闭，一副没精打采的模样。
LONG
);
	set("nickname", "般若堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score", 50000);

	set_skill("force", 400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("dodge", 400);
	set_skill("shaolin-shenfa", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("club", 400);
	set_skill("finger", 400);
	set_skill("strike", 400);
	set_skill("jingang-quan", 400);
	set_skill("wuchang-zhang", 400);
	set_skill("yizhi-chan", 400);
	set_skill("banruo-zhang", 400);
	set_skill("buddhism", 400);
	set_skill("literate", 400);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");
	map_skill("club", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八罗汉阵"	   : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :)
	]));

	setup();

	carry_object("/d/shaolin/obj/chanzhang")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


#include "/kungfu/class/shaolin/xuan-nan.h"

