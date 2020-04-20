// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// yupopo.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",@LONG
她是「灵鹫宫」九天九部中昊天部的首领，她跟随童姥多年, 出生入
死，饱经风霜。
LONG
);
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("jing", 4500);
	set("max_jing",4500);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",120);

	set("combat_exp",1000000);
	set("score",10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);

	set_skill("tianyu-qijian",100);
	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	create_family("灵鹫宫",2,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",10);
}
