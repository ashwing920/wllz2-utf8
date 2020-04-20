// tang fang.c 唐方

#include <ansi.h>

inherit F_MASTER;
inherit NPC;

string ask_throwing();

void create()
{
	set_name("唐青", ({ "tang qing", "tang" }));
	set("nickname",HIG"唐家堡侍婢"NOR);
	set("long", @LONG
她是唐门第八代传人唐青。
LONG
);
	set("gender", "女性");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("poison",200);
	set_skill("force", 200);
	set_skill("biyun-xinfa", 200);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 200);
	set_skill("unarmed",200);
	set_skill("biye-wu", 200);
	set_skill("parry", 200);
	set_skill("throwing", 200);
	set_skill("zimu-zhen", 200);
	set_skill("literate", 200);
	set_skill("zhuihun-biao",200);
	set_skill("liuxing-dao",200);
	set_skill("wuzhan-mei",200);
	set_skill("sword",200);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");

	create_family("唐门",8,"传人");

        set("inquiry", ([
                   "暗器" : (: ask_throwing :),
        ]) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.wumei" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
	}) );
	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/tangmen/obj/shuxiu")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 想拜入唐门到"HIG"唐家堡找唐不平"NOR + CYN"去吧！");
}

string ask_throwing()
{
	object me;
                int lvl;
                object obj;               
	me = this_player();

	if(me->query("family/family_name")!="唐门")
                                return RANK_D->query_respect(me) + "你不是唐门的人，要什么暗器！？";
  

	if(!(int)me->query_skill("throwing",1))
                                return RANK_D->query_respect(me) + "你都不会基本暗器，要暗器你会用？";

                lvl = me->query_skill("throwing",1);
                obj = new("/d/tangmen/obj/zimuzhen");
                obj->set("weapon_prop/damage",lvl);
                obj->set("no_get",1);
                obj->set("no_give",1);
                obj->set("no_put",1);
                obj->set("no_drop",1);
                obj->move(me);


        return "子母飞针拿去用吧!";  
}



