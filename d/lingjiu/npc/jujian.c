// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// jujian.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("菊剑", ({ "ju jian", "ju"}));
	set("long",@LONG
这是个容貌姣好的女子, 瓜子脸蛋，眼如点漆, 清秀绝俗。
你总觉得在哪见过她。
LONG
);
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",3500);
	set("max_jing",3500);
	set("neili",4000);
	set("max_neili",4000);
	set("jiali",150);
	set("combat_exp",800000);
	set("score",10000);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("sword",200);

	set_skill("zhemei-shou",200);
	set_skill("liuyang-zhang",200);
	set_skill("tianyu-qijian",200);
	set_skill("yueying-wubu",200);
	set_skill("bahuang-gong", 200);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-jianfa");

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	add_money("silver",15);
}

