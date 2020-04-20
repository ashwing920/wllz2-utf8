// daochang-dizi.c - 道场弟子

#include <ansi.h>

inherit NPC;

void create()
{
        set("title","百人道场大宗师");
        set_name(npc_name("男性"), ({"zong shi","master" }));
        set("nickname",HIY"勇"HIC"者"HIR"无"HIW"敌"NOR);
        set("long","这位是"+ query("title")+"。\n");
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
