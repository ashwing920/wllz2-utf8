// LiTianYuan.c

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name("李天垣", ({ "li tianyuan", "li", "tianyuan", }));
	set("long",@LONG
他是一位看起来很慈祥的老者，身穿一件白布长袍。他是白眉鹰王殷天正
的师弟。一双眼睛总是笑眯眯的，但不知为什么，他的下属对他畏如蛇蝎。
LONG
);

	set("title",HIG"明教"CYN"天市堂"NOR"堂主");
	set("nickname", "慈眉善目");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");

	set("age", 55);
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

	prepare_skill("cuff","jingang-quan");
	create_family("明教",3,"天市堂堂主");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "tangzhu.h"
