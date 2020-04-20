// smith.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 5400);
	set("attitude", "friendly");
	set("vendor_goods",([
		   "/clone/weapon/changjian": 20,
		   "/clone/weapon/hammer": 20,
		   "/d/city2/obj/tudao": 20,
		   "/d/xingxiu/obj/tiegun": 20,
		   "/clone/weapon/gangdao": 20,
	]));
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		   remove_call_out("greeting");
		   call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
	 
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("铁匠说道：欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。\n\n");
}
