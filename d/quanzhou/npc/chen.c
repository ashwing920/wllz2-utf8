// chen.c
// Jay 5/7/96

inherit F_VENDOR_SALE;

void create()
{
	reload("chenapo");
	set_name("陈阿婆", ({ "chen apo", "chen", "apo" }));
	set("title", "杂货铺老板娘");
	set("shen_type", 1);
	set("str", 20);
	set("gender", "女性");
	set("age", 55);
	set("long",
		"陈阿婆久居泉州城，据说她年轻时很有几分风韵，福威镖局\n"
		"当时的少镖头林震南还追求过她。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"林震南" : "阿南生着那俊，那会琢一个河南七子婆，唉。\n",
		"name" : "婆婆我夫家姓陈。陈林半边天嘛。\n",
		"here" : "泉州是个港口，会行船的人很多。\n",
	]));
	set("vendor_goods", ([
		"/clone/obj/twine":1,
		"/d/quanzhou/obj/xiuhua": 1,
		"/d/quanzhou/obj/flower_shoe": 1,
		"/d/quanzhou/obj/pink_cloth": 1,
		"/clone/cloth/goldring": 1,
		"/clone/cloth/necklace": 1,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/cloth/flower_shoe")->wear();
}

void init()
{
	object ob;
	
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_bid","bid");
	add_action("do_deposit","deposit");
	add_action("do_setprice", "set_price");
	add_action("do_status","status");
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	switch(random(2)) {
	case 0 :
		say("陈阿婆笑眯眯地说道：人客来坐。\n");
		break;
	case 1 :
		say("陈阿婆说道：可嘴的，你要买什？\n");
		break;
	}
}
