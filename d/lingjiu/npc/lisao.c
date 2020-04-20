// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// lisao.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("李嫂", ({ "li sao", "li", "sao" }));
	set("long",@LONG
她是 [灵鹫宫] 的厨师。
LONG
);
	set("gender", "女性");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("jing",2500);
	set("max_jing",2500);
	set("neili",10000);
	set("max_neili",10000);
	set("jiali",100);

	set("combat_exp",500000);
	set("score",10000);
	set_skill("force", 100);
	set_skill("unarmed",100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong",100);

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
	add_money("silver",10);
}

