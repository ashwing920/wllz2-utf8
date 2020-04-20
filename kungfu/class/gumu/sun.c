// sun.c 孙婆婆

#include <ansi.h>

inherit NPC;

string ask_yufeng();

void create()
{
	set_name("孙婆婆", ({"sun popo", "sun"}));
	set("gender", "女性");
	set("age", 55);
	set("long",@LONG
这是一位慈祥的老婆婆，正看着你微微一笑。
LONG
);
	set("attitude", "friendly");

	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 40);

	set("combat_exp",150000);
	set("yufeng",10);

	set_skill("force", 80);
	set_skill("yunv-xinfa", 60);
	set_skill("sword", 90);
	set_skill("yunv-jian", 80);
	set_skill("dodge", 70);
	set_skill("yunv-shenfa", 70);
	set_skill("parry", 60);
	set_skill("unarmed",80);
	set_skill("meinv-quan", 60);
	set_skill("literate",40);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	set("inquiry", ([
		"小龙女" :"龙姑娘是我一手带大的，她从小没了父母，现在又独个儿住在这古墓里，唉..\n",
		"玉蜂": (: ask_yufeng :),
		"驱蜂之术": "驱蜂术可以让你驱使玉蜂攻击对手，也可以让玉蜂帮你带路。\n",
	]));
	set("env/wimpy", 50);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
string ask_yufeng()
{
	object me,obj;
	mapping fam;
	
	me = this_player();
	
	if(!mapp(fam = me->query("family"))
		|| fam["family_name"] != "古墓新派")
		return "玉蜂是我家姑娘饲养的乖乖，你若是不想自寻死路，还是赶快离开这里吧。";
	
	if(query("yufeng") < 1 || me->query_temp("yufeng") > 1)
		return "我这里已经没有玉蜂了，你若是需要，可以到墓门外的小树林那去看看。";
	
	obj = new("/d/gumu/npc/yufeng");
	obj->move(me,1);
	add("yufeng",-1);
	me->add_temp("yufeng",1);
	write("孙婆婆从怀里掏出一只玉蜂，小心翼翼的交给了你。\n");
	return "我这里有一只玉蜂，你带在身上，若是在古墓里迷路了倒是可以派上用场。";
}
