// gaoli.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("高丽商", ({ "gaoli shang", "shang" }));
	set("title", "新罗坊老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"这是个高丽商人，长得和中国人没啥区别。连卖的东西也差不多。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/clone/misc/mabudai": 20,
                "/clone/cloth/beixin": 20,
                "/clone/cloth/toukui": 20,
                "/clone/cloth/cycle": 20,
                "/clone/cloth/surcoat": 20,
                "/clone/cloth/shield": 20,
                "/clone/cloth/huwan": 20,
                "/clone/cloth/zhitao": 20,
                "/clone/cloth/huyao": 20,
                "/clone/cloth/caoxie": 20,
                "/clone/cloth/pixue": 20,
                "/clone/cloth/shoutao": 20,
                "/clone/cloth/tieshou": 20,
                "/clone/cloth/jinsijia": 20,
                "/clone/misc/sleepbag": 20,
                "/clone/misc/fire": 20,
	]));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
	 
}
