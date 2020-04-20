// Npc: /kungfu/class/shaolin/xuan-ku.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄苦大师", ({"xuanku dashi","xuanku","dashi",}));
	set("long",@LONG
他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材瘦高，脸上满
布皱纹，手臂处青筋绽露，似乎久经风霜。
LONG
);
	set("nickname", "罗汉堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing", 1000);
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
	set_skill("staff", 400);
	set_skill("blade", 400);
	set_skill("sword", 400);
	set_skill("luohan-quan", 400);
	set_skill("weituo-gun", 400);
	set_skill("xiuluo-dao", 400);
	set_skill("fumo-jian", 400);
	set_skill("buddhism", 400);
	set_skill("literate", 400);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "luohan-quan");
	map_skill("cuff", "luohan-quan");
	map_skill("staff", "weituo-gun");
	map_skill("blade", "xiuluo-dao");
	map_skill("sword", "fumo-jian");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八罗汉阵"	   : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :)
	]));

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

#include "/kungfu/class/shaolin/xuan-ku.h"
