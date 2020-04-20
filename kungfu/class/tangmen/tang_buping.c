// tang buping.c 唐不平

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐不平", ({ "tang buping", "tang" }));
	set("nickname", HIW "闪电手" NOR);
	set("long",@LONG
他是唐门第八代传人，是江湖新一辈中颇有名气的人物。他大约二十有余
，脸上还带着一股孩子气。
LONG
);
	set("gender", "男性");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);

	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali",75);
	set("combat_exp", 100000);

	set_skill("poison",100);
	set_skill("force", 100);
	set_skill("biyun-xinfa", 100);
	set_skill("dodge", 100);
	set_skill("qiulinshiye", 100);
	set_skill("strike", 100);
	set_skill("unarmed",100);
	set_skill("biye-wu", 100);
	set_skill("parry", 100);
	set_skill("throwing", 100);
	set_skill("zimu-zhen", 100);
	set_skill("literate", 100);
	set_skill("zhuihun-biao",100);
	set_skill("liuxing-dao",100);
	set_skill("wuzhan-mei",100);
	set_skill("sword",100);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");
	create_family("唐门", 8, "传人");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({

		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你。");
	command("recruit " + ob->query("id"));
}
