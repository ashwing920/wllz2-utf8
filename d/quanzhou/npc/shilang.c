//Cracked by Kafei
inherit NPC;
#include <ansi.h>

string ask_me();

void create()
{
	set_name("施琅", ({ "shi lang","shi","lang" }));
	set("title","靖海侯");
	set("long",
		"施琅是一员能征惯战的水将，刚刚平定台湾，御赐靖海侯。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 30);
	set("int", 26);
	set("con", 28);
	set("dex", 26);
	set("max_qi", 1300);
	set("max_jing", 1300);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jingli", 1300);
	set("max_jingli", 1300);
	set("jiali", 60);
	set("combat_exp", 160000);


	set("inquiry", ([
		"韦小宝" : (: ask_me :),
		"韦爵爷" : (: ask_me :),
		"郑成功" : "国姓爷外战英勇，内政糊涂，终于成了现在这个样子。\n",
		"国姓爷" : "当今的天子是大清皇上，乱臣贼子怎称国姓？\n",
		"皇上" : "这也是你问得的吗？\n",
		"大清" : "当今国号，谁人不知。\n",
		"台湾" : "那就是老夫平定的，哈哈哈。\n",
		"郑克爽" : "那小子比你强不了多少。\n",
	]));

	setup();
	carry_object("/clone/weapon/gangjian")->wield();

}

int accept_fight(object me)
{
	command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
	return 0;
}
string ask_me()
{
	object ob;

	if (this_player()->query_temp("shi-ling"))
		return("我还想问你呢，你找到他了吗？\n");
	ob = new(__DIR__"obj/lingpai");
	ob->move(this_player());
	this_player()->set_temp("shi-ling",1);
	command("ah");
	command("say 我正要去找他呢。");
	return "好吧，这支令牌你拿去，我的水军听你差遣，找到了他快告诉我。";
}
