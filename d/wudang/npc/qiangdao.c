// xiao_tufei.c

inherit NPC;

void create()
{
	set_name("黑衣人",({"hei yiren","hei"}));
	set("gender", "男性" );
	set("long","一个蒙面的黑衣人，手持钢刀，样子十分诡异。\n");
	set("age",22);
	set("str",25);
	set("dex",20);
	set("con",18);
	set("int",15);
	set("cor",30);

	set_temp("apply/damage",300);
	set_temp("apply/armor",500);

	set("combat_exp",2000000);
	set("shen_type", -1);
	set("attitude","aggressive");

	set_skill("blade",300);
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("liuhe-daofa",300);
	set_skill("xiaoyaoyou",300);
	set_skill("shexing-diaoshou",300);
	set_skill("huntian-qigong",300);
	
	map_skill("blade","liuhe-daofa");
	map_skill("unarmed","shexing-diaoshou");
	map_skill("force","huntian-qigong");
	map_skill("dodge","xiaoyaoyou");
	map_skill("parry","liuhe-daofa");

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/male3-cloth")->wear();
	add_money("silver",10);
}
void afterdie_func(object killer)
{
	if(killer->query_temp("ask_dudajin")
	&& present("yu daiyan",killer))
	killer->add_temp("pk_qiangdao",1);
}
