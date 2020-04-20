// YinWuLu.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("殷无禄", ({ "yin wulu", "yin", "wulu", }));
	set("long",@LONG
他是一位老者，身穿一件白布长袍。他是白眉鹰王殷天正的仆从。一双怪
眼正恶狠狠地瞪着你呢！
LONG
);
	set("title",HIG"明教"HIC"天市堂"NOR"属下");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");

	set("age", 56);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 100);
	set_skill("jingang-quan",100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");
	create_family("明教", 4, "天市堂属下");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

