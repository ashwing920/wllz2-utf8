// Npc: /kungfu/class/shaolin/cheng-zhi.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("澄知", ({"chengzhi luohan","chengzhi",}));
	set("long",@LONG
他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，太阳穴
高高鼓起，似乎身怀绝世武功。
LONG
);
	set("nickname", "清净罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing",1500);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp", 2700000);
	set("score", 5000);

	set_skill("force", 300);
	set_skill("hunyuan-yiqi", 300);
	set_skill("dodge", 300);
	set_skill("shaolin-shenfa", 300);
	set_skill("cuff", 455);
	set_skill("jingang-quan", 455);
	set_skill("parry", 300);
	set_skill("buddhism", 300);
	set_skill("literate", 300);
	set_skill("unarmed",300);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	create_family("少林派", 37, "弟子");

	setup();

	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

