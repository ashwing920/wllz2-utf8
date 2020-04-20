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
里获得一件宗师兵器。
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
        	"宗师兵器": (: ask_me :),
        	"兵器": (: ask_me :),
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
        add_action("do_select","选");
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
	object me;
	
	me = this_player();
	
	if(!(int)me->query("is_zongshi"))
		return "你还没有获得宗师资格，百人道场的宗师兵刃可是你随便能拿的？";
	
	if((int)me->query("zongshi_gift"))
		return "我百人道场已授予这位"+ RANK_D->query_respect(me)+"宗师奖励，莫非你还嫌不够？";
	
	me->set_temp("ask_weapon",1);
		return  "我百人道场提供四件神兵利器给予各位武林大宗师使用，\n\n目前所提供的兵器有：\n"
			"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n"
			WHT"百战狂刀：魅力 +10、身法 -5、臂力 +4、定力 -5、杀伤力 +800\n"
			"百战神剑：魅力 + 8、身法 -6、臂力 +6、定力 -4、杀伤力 +800\n"
	    		"百神之枪：魅力 +12、身法 -5、臂力 +2、定力 -5、杀伤力 +800\n"
	    		"百战之棍：魅力 + 9、身法 -3、臂力 +5、定力 -7、杀伤力 +800\n"
	    		"百战之鞭：魅力 +12、身法 -1、臂力 +2、定力 -8、杀伤力 +800\n"NOR
	    		CYN"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n"
	    		"这位"+ RANK_D->query_respect(me) +"请选择适手的一件兵器吧。\n\n"
	    		"(为了防止错误选择而导致遗憾，请输入完整中文字，如：选 百战之鞭)";
}
int do_select(string arg)
{
	object me,obj;
	me = this_player();

	if(!(int)me->query_temp("ask_weapon")
	|| !(int)me->query("is_zongshi") 
	|| (int)me->query("zongshi_gift")) return 0;
	
	if(!arg || arg == "")
		return notify_fail("为了防止错误选择而导致遗憾，请输入完整中文字，如：选 百战之鞭\n");
	
	if(arg != "百战狂刀" && arg != "百战神剑" && arg != "百神之枪" && arg != "百战之棍"
	&& arg != "百战之鞭")
		return notify_fail("没有你所要选择的兵器，目前百人道场所提供的兵器有：\n"
			"百战狂刀：魅力 +10、身法 -5、臂力 +4、定力 -5、杀伤力 +800\n"
			"百战神剑：魅力 + 8、身法 -6、臂力 +6、定力 -4、杀伤力 +800\n"
	    		"百神之枪：魅力 +12、身法 -5、臂力 +2、定力 -5、杀伤力 +800\n"
	    		"百战之棍：魅力 + 9、身法 -3、臂力 +5、定力 -7、杀伤力 +800\n"
	    		"百战之鞭：魅力 +12、身法 -1、臂力 +2、定力 -8、杀伤力 +800\n");
	
	switch(arg){
		case "百战狂刀": obj = new("/clone/master_weapon/blade");break;
		case "百战神剑": obj = new("/clone/master_weapon/sword");break;
		case "百神之枪": obj = new("/clone/master_weapon/spear");break;
		case "百战之棍": obj = new("/clone/master_weapon/staff");break;
		case "百战之鞭": obj = new("/clone/master_weapon/whip");break;
	}
	obj->move(me);
	me->set("zongshi_gift",1);
	message_vision("$N从身后的兵器架上取出一"+ obj->query("unit") + obj->name(1)+"对$n说道：这把就是经百人道场炼造的"+ obj->name(1)+"，现在就交给你了。\n",this_object(),me);
	log_file("zongshi_gift",sprintf("[%s] %s[%s]获取了一件%s。\n",ctime(time()),me->name(1),me->query("id"),obj->name(1)));
	me->save();
	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s，%s从百人道场获得了一%s%s。",NATURE_D->game_time(),me->query("name"),obj->query("unit"),obj->name(1)));
	return 1;
}