// lu.c

#include <ansi.h>
inherit NPC;									
inherit F_MASTER;								   
void create()
{
	set_name( "陆乘风" ,({ "lu chengfeng", "lu" }));
	set("gender", "男性");
	set("age", 52);
	set("long",@LONG
陆乘风是黄药师的第四个徒弟。他的鬓角已微见白发，但身材魁梧，双眼
有神。
LONG
);
	set("attitude", "friendly");
	set("class", "scholar");
	set("str", 30);
	set("int", 28);
	set("con", 30);
	set("dex", 30);

	set("jing",1000);	
	set("max_jing",1000);
	set("neili",2000);
	set("max_neili",2000);
	set("jiali",100);
	set("shen_type",1);

	set("combat_exp",100000);
	set_skill("music",100);
	set_skill("force", 100);
	set_skill("bibo-shengong", 100);
	set_skill("unarmed", 100);
	set_skill("xuanfeng-leg", 100);
	set_skill("strike", 100);
	set_skill("luoying-zhang", 100);
	set_skill("dodge", 100);
	set_skill("anying-fuxiang", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("luoying-shenjian", 100);
	set_skill("literate",100);
	set_skill("cuixin-zhang",100);

	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "luoying-shenjian");

	set("jinbing", 10);
	create_family("桃花岛", 2, "弟子 归云庄主");

	set("inquiry", ([
		"桃花岛":"这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
		"桃花阵":"往南就是了。",
		"东邪":  "家师人称东邪！呵呵。",
		"西毒":	 "欧阳锋是与家师并世齐名的高手，人称老毒物。",
		"南帝":	 "听家师说段王爷现在出家当了和尚，法名一灯。",
		"北丐":	 "北丐洪七公是丐帮帮主，现在扬州城外。",
		"黄蓉":	 "她是师父的爱女。",
		"黄药师":"你要拜访家师？"
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
	if (ob->query_dex() < 20){
		command("say 我派武功讲究轻灵巧捷。");
		command("say 这位"+RANK_D->query_respect(ob)+"可能是白来归云庄一趟了。");
		return;
	}
	if ((int)ob->query("shen") < 0){
		command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"请回吧。");
		return;
	}
	if (ob->query("gender") == "无性"){
		command("say 师父最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
		return;
	}
	if (ob->query_skill("literate",1) < 10){
		command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
		return;
	}
	command("smile");
	command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
	command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
	command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp,pot,bonus;
	if (query("jinbing") < 0){
		command("say " + RANK_D->query_respect(who) + "我很累，你回头再来领赏吧。");
		return 0;
	}
	if (strsrch(ob->query("name"), "完颜康的头颅") < 0 &&
		strsrch(ob->query("name"), "完颜洪烈的头颅") < 0 &&
		strsrch(ob->query("name"), "欧阳锋的头颅") < 0 &&
		strsrch(ob->query("name"), "欧阳克的头颅") < 0 &&
		strsrch(ob->query("name"), "彭连虎的头颅") < 0 &&
		strsrch(ob->query("name"), "梁子翁的头颅") < 0 &&
		strsrch(ob->query("name"), "灵智上人的头颅") < 0 &&
		strsrch(ob->query("name"), "沙通天的头颅") < 0 &&
		strsrch(ob->query("name"), "侯通海的头颅") < 0 &&
		strsrch(ob->query("name"), "沈青刚的头颅") < 0 &&
		strsrch(ob->query("name"), "吴青烈的头颅") < 0 &&
		strsrch(ob->query("name"), "马青雄的头颅") < 0 &&
		strsrch(ob->query("name"), "钱青健的头颅") < 0 &&
		strsrch(ob->query("name"), "大金兵的头颅") < 0 &&
		strsrch(ob->query("name"), "段天德的头颅") < 0) 
	{
		command("say 给我这些东西有什么用？\n");
		return 0;
	}
	else{
	
	command("say 不错不错，我一直想杀这些金狗，谢你代劳了。");
	exp = 20+random(30);
	bonus=(int)who->query("combat_exp");
	bonus+=exp;
	who->set("combat_exp", bonus);
	pot=(int)who->query("potential");
	bonus=10+random(20);
	pot+=bonus;
	who->set("potential", pot );
	add("jinbing", -1);
	tell_object(who,HIW"陆乘风奖励了你：" + chinese_number(exp)+"点实战经验，"+ chinese_number(bonus) + "点潜能。\n"NOR);
	return 1;
	}
}
