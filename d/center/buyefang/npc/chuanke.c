// chuangke.c 船客

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("船客", ({ "chuan ke","chuan","ke" }) );
        set("gender","男性");
        set("str",30);
        set("dex",30);
        set("con",30);
        set("per",30);
        set("int",30);
        set("kar",30);
        set("combat_exp",50000);
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("hand",50);
        
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
}
