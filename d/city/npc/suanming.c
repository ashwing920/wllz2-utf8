// suanming.c 算命先生

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("算卦先生", ({"suangua xiansheng","xiansheng"}) );
	set("nickname",YEL"包准"NOR);
	set("str",20);
	set("long",
		"他是一位老道的算命先生。\n");
	set("age",40);
	set("gender","男性");
	set("combat_exp",200000);
	set_skill("unarmed",30);
	set_skill("force",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance_combat",30);
	set("chat_chance",4);
	set("chat_msg",({
		"算命先生偷偷问你：想不想算命啊?\n"NOR,
		"算命先生对你说道：算一次一两黄金，不对不要钱。\n"NOR,
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object who,object ob)
{
	object me = this_player();

	if((string)ob->query("id")=="gold")
	{	
		write("算命先生埋头掐指一算，哈哈，有了。\n");
		command("say "+me->query("name")+"，你的福缘是："+HIC+(string)me->query("kar")+"\n");
		if((int)me->query("shen")>=100000)
		{
			if((string)me->query("gender")=="女性")
				command("chat 哈哈！旷世侠女"+me->name()+"真是难得一遇啊。\n");
			else 
				command("chat 哈哈！旷世大侠"+me->name()+"真是难得一见啊.\n");
		}
		return 1;
	}
}
