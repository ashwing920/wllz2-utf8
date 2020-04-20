// benxiang.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("本相", ({ "ben xiang","xiang"}) );
	set("gender", "男性" );
	set("long", "一个枯黄精瘦的僧人，他是本因方丈的师兄。\n");
	set("title", "天龙寺第十七代僧人");
	set("class", "bonze");
	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing", 2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp", 800000);
	set("score", 10000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 200);
	set_skill("sword", 200);
	set_skill("tiannan-step", 200);
	set_skill("kurong-changong", 200);
	set_skill("duanjia-sword", 200);
	set_skill("liumai-shenjian", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","liumai-shenjian");
	create_family("大理段家",17,"高僧");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}
#include "ben.h"

