// daochang-dizi.c - 道场弟子

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set("title","侍者");
	set_name(npc_name("男性"), ({"shi zhe","master" }));
	set("long",@LONG
这位是百人道场四大侍者之一，据说只要成功挑战百人道场，便可从他那
里获得一本关于《独孤剑气》的剑法秘籍。
LONG
);
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("chat_msg_combat", ({
		(: perform_action,"leg.lianhuan":),
		(: perform_action,"spear.zhimeng":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	add_temp("apply/damage",700);
	add_temp("apply/armor",700);
	add_temp("apply/dodge",700);
	add_temp("apply/attack",700);
	
	set("inquiry",([
		"宗师武功": (: ask_me :),
		"秘籍": (: ask_me :),
	]));
	set("combat_exp",20000000);
	set_skill("force",550);
	set_skill("taixuan-gong",550);
	set_skill("leg",550);
	set_skill("jueming-tui",550);
	set_skill("cuff",550);
	set_skill("kongming-quan",550);
	set_skill("spear",550);
	set_skill("duanhun-qiang",550);
	set_skill("unarmed",550);
	set_skill("xianglong-zhang",550);

	map_skill("cuff","kongming-quan");
	map_skill("leg","jueming-tui");
	map_skill("unarmed","xianglong-zhang");
	map_skill("spear","duanhun-qiang");
	map_skill("force","taixuan-gong");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/spear")->wield();
}
void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}
void greeting(object ob)
{
	if(!ob || environment() != environment(ob)) return;
	if( ob->query("is_zongshi")){
		say(this_object()->name()+"一抱拳道：这位就是新一代武林宗师"+ ob->name(1)+"吧！恭喜！恭喜！\n");
	}
	else {
		say(this_object()->name()+"怒道：你没有打败百人道场弟子，如何闯进百人道场密室的？\n");
		tell_object(ob,"话音刚落，只见"+this_object()->name()+"挥掌就向你打来，你闪躲不及，被他的招式打中 . . .\n");
		ob->move("/d/center/guangchang");
		ob->unconcious();
	}       
}
string ask_me()
{
	object me,obj;
	
	me = this_player();
	
	if(!(int)me->query("is_zongshi"))
		return "你还没有获得宗师资格，百人道场的宗师武功恐怕你是学不了的了。";
	
	if((int)me->query("zongshi_gift"))
		return "这位"+ RANK_D->query_respect(me)+"已获得本道场的宗师奖励，莫非你还嫌不够？";

	obj = new("/clone/book/dugujianqi_book");
	obj->move(me);
	message_vision("$N对$n点了点头，说道：这本《独孤剑气》你就拿去好好参详吧，秘籍只有一本，记得切勿丢失了。\n",this_object(),me);
	me->set("zongshi_gift",1);
	me->save();
	log_file("zongshi_gift",sprintf("[%s] %s[%s]从百人道场获得了一本%s。\n",ctime(time()),me->name(1),me->query("id"),obj->name(1)));
	return CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s，%s从百人道场获得了一本《独孤剑气》。",NATURE_D->game_time(),me->name(1)));
	
}
