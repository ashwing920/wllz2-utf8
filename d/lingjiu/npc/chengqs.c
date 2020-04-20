// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// fumy.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("程青霜", ({ "cheng qingshuang", "cheng"}));
	set("long",@LONG
她是「灵鹫宫」九天九部中钧天部的副首领。
LONG
);
	set("title", "钧天部副首领");
	set("gender", "女性");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("jing",3500);
	set("max_jing",3500);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",225);

	set("combat_exp",2700000);
	set("score",10000);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);

	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");


	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	add_money("silver",5);
}

