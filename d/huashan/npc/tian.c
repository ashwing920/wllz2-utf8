// yue-lingshan.c

inherit NPC;

void create()
{
	 set_name("田伯光", ({ "tian boguang", "tian"}) );
	set("gender","男性");
	set("age",34);
	set("per", 29);
	set("str", 16);
	set("con", 24);
	set("dex", 30);
	set("int", 27);

	set("attitude", "friendly");
	set("max_jing",1500);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 120);
	set("combat_exp", 3000000);

	set("long",@LONG
田伯光是江湖上一个名声不是很好的人，但却是令狐冲的好友.
LONG
);


	set_skill("unarmed",400);
	set_skill("sword",400);
	set_skill("force",400);
	set_skill("parry",400);
	set_skill("dodge",400);
	set_skill("literate",400);
	set_skill("huashan-sword",400);
	set_skill("huashan-neigong",400);
	set_skill("huashan-ken",400);
	set_skill("huashan-zhangfa",400);
	set_skill("huashan-shenfa",400);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	setup();

	carry_object(__DIR__"obj/green_water_sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();

}
void die()
{
	destruct(this_object());
	this_player()->move("/d/huashan/luoyan");
}
void feng()
{
	this_player()->move("/d/huashan/luoyan");
	message_vision("突然$N眼前一亮,只觉得一阵风,你就到了风清扬老前辈的面前！\n",this_player());
}
