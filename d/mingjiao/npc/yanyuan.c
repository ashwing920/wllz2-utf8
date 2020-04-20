// YanYuan.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("颜垣", ({ "yan yuan", "yan", "yuan", }));
	set("long",@LONG
他是一个矮矮胖胖的汉子，身穿一件白布长袍。他天生神力，手中的两头
狼牙棒有万夫不当之勇，真是一条威风凛凛的汉子。
LONG
);
	set("title",HIG"明教"HIY"厚土旗"NOR"掌旗使");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");

	set("age", 48);
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

	create_family("明教", 3, "厚土旗掌旗使");

	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "zhangqishi.h"