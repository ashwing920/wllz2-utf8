// guanyin.c
inherit NPC;

string ask_ceshi();
string ask_zheng();
string ask_fu();

void create()
{
        set_name("观音大士",({ "guanyin dashi","guanyin","dashi" }));
        set("gender", "女性" );
        set("age", 23);
        set("long",
"观音大士是天上的神仙，她神通广大直通三界。\n");
        set("level", 200);
        set("per", 200);
        set("inquiry", ([
             "测试" : (: ask_ceshi :),
             "正神" : (: ask_zheng :),
             "负神" : (: ask_fu :),
        ]) );
        set("chat_msg",({
            "观音大士淡淡说道:想年轻吗？多吃点人参果就返老还童了。\n",
        }));
                setup();
}



string ask_ceshi()
{
	object obb;
                object ob;               
	obb = this_player();
               
      obb->set("combat_exp", 3000000);
      obb->add("potential",3000000);
      obb->set_skill("force",311);
      obb->set_skill("dodge",311);
      obb->set_skill("parry",311);
      obb->set_skill("unarmed",311);
      obb->set_skill("sword",311);
      obb->set_skill("blade",311);
      obb->set_skill("staff",311);
      obb->set_skill("hand",311);
      obb->set_skill("strike",311);
      obb->set_skill("leg",311);
      obb->set_skill("cuff",311);
      obb->set_skill("whip",311);
      obb->set_skill("throwing",311);
      obb->set_skill("literate",800);
      obb->add("mud_age",700000);
      ob = new("/clone/money/thousand-gold");
      ob->move(obb);
            return "好了!。";  
}


string ask_zheng()
{
	object obb;
	obb = this_player();

      obb->set("shen",1000000);
            return "好了!。";  
}


string ask_fu()
{
	object obb;
	obb = this_player();


      obb->set("shen",-1000000);
            return "好了!。";  
}
