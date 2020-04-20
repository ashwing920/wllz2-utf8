//ouyangke.c

#include <ansi.h>

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。\n");
	set("title", "白驼山少庄主");
	set("nickname", HIM"玉面蛇心"NOR);
	set("gender", "男性");
	set("age", 27);
	set("attitude","friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 24);
	set("con", 25);
	set("dex", 126);
	set("per",26);
	set("jing",3000);
	set("max_jing",3000);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",1250000);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("staff", 200);
	set_skill("hamagong",200);
	set_skill("chanchu-bufa",200);
	set_skill("shexing-diaoshou",200);
	set_skill("lingshe-zhangfa", 200);
	set_skill("training",200);
	set_skill("hand",200);
	set_skill("literate",200);
	set_skill("perception",200);
	set_skill("strike",200);
	set_skill("poison",200);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	create_family("白驼山派",2,"弟子");
	set("chat_chance",5);
	set("chat_msg", ({
		"欧阳克唱道: 漂亮姑娘你请留步....让我多看你一眼......\n",
		"欧阳克色迷迷地看着街边的小姑娘。\n",
		"欧阳克把纸扇一展，转过身去，深情地吟道：红颜知己最难得￣\n",
	}) );
	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: perform_action, "unarmed.suo" :),
		(: perform_action, "dodge.jinchan" :),
		(: perform_action, "dodge.move" :),
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",10);
}
void init()
{
	object ob;
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ||  is_fighting()) return;
	if ((string)ob->query("gender")=="女性"){
	switch(random(3)){
		case 0:command("rose "+(string)ob->query("id"));break;
		case 1:command("kiss "+(string)ob->query("id"));break;
		case 2:command("love "+(string)ob->query("id"));break;
		}

	} else
		say("欧阳克叹了一口气说：这位"+RANK_D->query_respect(ob)+",你要是能给我弄一个女人来就好了。\n");
	return;
}
void attempt_apprentice(object ob)
{
	string name,new_name;
	name = ob->query("name");

	if((string)ob->query("family/family_name") == "白驼山派"){
		if((int)ob->query("combat_exp") < 10000)
			command("say 你的经验太低，我还不能收你。继续努力吧。");
		else {
			name = ob->query("name");
			name = replace_string(name,"欧阳","");
			switch(strlen(name)){
				case 2:	new_name = "欧阳" + name;break;
				case 4:	new_name = "欧阳" + name[2..4];break;
				case 6: new_name = "欧阳" + name[4..6];break;
				case 8: new_name = "欧阳" + name[6..8];break;
				default:
			}
			ob->set("name",new_name);
			command("say 你跟着我要好好学。");
			command("recruit "+ob->query("id"));
		}
		return;
    	}
	if ((string)ob->query("gender") == "女性")
		message_vision("欧阳克动情地说道：这位" + RANK_D->query_respect(ob) +"真乃我的红颜知己，\n我现在还不能收你，只能送你上白驼山。\n",ob);
	else
		message_vision("欧阳克笑笑说：这位"+RANK_D->query_respect(ob)+"，我现在还不能收你，只能送你上白驼山。\n",ob);

	write(HIY "只见欧阳克把纸扇往你眼前一晃，\n你觉得眼前一闪，身体轻飘飘地飞了出去￣￣\n" NOR);
	ob->move("/d/baituo/liangong.c");
}
int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性"){
		message_vision("欧阳克摆摆手说道：这位"+RANK_D->query_respect(ob)+"，我怎能欺负女孩子呢！\n", ob);
		return 0;
	}
	if ((string)ob->query("family/family_name") == "白驼山派"){
		if((int)ob->query("combat_exp")<100000)
		return notify_fail("欧阳克笑道：你的经验太低了,再练几年吧。！\n");
	}
		message_vision("欧阳克一拱手说道：这位"+RANK_D->query_respect(ob)+"，在下领教了。\n", ob);
	return 1;
}
