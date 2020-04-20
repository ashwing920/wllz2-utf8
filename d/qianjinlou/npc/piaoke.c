// piaoke.c - 嫖客

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(npc_name("男性"), ({ "piao ke" }) );
        set("title","嫖客");
        set("long", @LONG
他是一名经常出入于千金楼的一个富家公子。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 35);
        set("combat_exp",random(30000)+10000);
        set("shen_type",-1);
        set("env/wimpy", 30);                   
        setup();
        carry_object("/clone/cloth/cloth")->wear();     // 装备
        add_money("silver", 50);                        // 金钱
}
