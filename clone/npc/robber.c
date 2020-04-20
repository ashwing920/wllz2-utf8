                               // robber.c

#include <ansi.h>
inherit NPC;
string *family_name = ({
        "古墓新派",
        "云龙门",
        "逍遥派",
        "武当派",
        "华山剑派",
        "灵鹫宫",
        "少林派",
        "雪山派",
        "丐帮",
        "血刀门",
        "星宿派",
        "五毒神教",
        "昆仑派",
        "唐门",
        "神龙教",
        "明教",
        "峨嵋剑派",
});

void create()
{
        string family;
        int n;
        n = random(sizeof(family_name));
        family = family_name[n];
        set("family/family_name",family);

        set_name("蒙面人", ({"robber" }) );
        set("long","这是一名蒙面人，样子十分诡异。\n");
        set("gender","男性");
        set("attitude", "heroism");
        set("str", 20 + random(11));        
        set("per", 20 + random(11));        
        set("int", 20 + random(11));        
        set("con", 20 + random(11));        
        set("dex", 100 + random(11));       
        set("kar", 20 + random(11));    
        set("combat_exp", random(4000) + 1000);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: command("exert recover"): ),
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 20);
        NPC_D->full_init(this_object());
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"急急忙忙地走开了。\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}
