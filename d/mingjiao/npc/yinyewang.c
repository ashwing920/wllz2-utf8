// YinYeWang.c

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name("殷野王", ({ "yin yewang", "yin", "yewang", }));
	set("long",@LONG
他是一位手摇折扇的中年男子，身穿一件白布长袍。他是白眉鹰王殷天正
之子。一双眼睛犹如冷电，精光四射，气势摄人。
LONG
);

	set("title",HIG"明教"BLU"天微堂"NOR"堂主");
	set("nickname", "一飞冲天");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighert");

	set("age", 44);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
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
	create_family("明教", 3, "天微堂堂主");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "tangzhu.h"
