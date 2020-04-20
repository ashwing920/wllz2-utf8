#include <ansi.h>
inherit NPC;

void create()
{
	set_name("杨莲亭", ({ "yang lianting", "yang",}));
	set("long",@LONG
此人身形魁梧，满脸胡须，形貌极为雄健威武，可下盘虚浮，看来无甚内功。
LONG
);
	set("title",HIW"日月神教总管"NOR);
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 22);
	set("con", 21);
	set("dex", 19);

	set("max_jing",2000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",100);
	set("combat_exp",100000);

	set_skill("tianmo-zhang",100);
	set_skill("piaomiao-shenfa",100);
	set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
