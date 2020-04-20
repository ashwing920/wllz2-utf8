// YinWuFu.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("殷无福", ({ "yin wufu", "yin", "wufu", }));
	set("long",@LONG
他是一位老者，身穿一件白布长袍。他是白眉鹰王殷天正的仆从。一双三
角眼阴光四射，让人胆寒。
LONG
);

	set("title",HIG"明教"HIB"天微堂"NOR"属下");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");

	set("age", 58);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 75);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff",100);
	set_skill("jingang-quan",100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	create_family("明教", 4, "天微堂属下");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

