// ren1.c 掌药道长
inherit NPC;
#include <ansi.h>
string ask_dan();
void create()
{
        set_name("掌药道长", ({"zhangyao"}));
        set("gender", "男性");
        set("age", 28);
        set("class", "taoist");
        set("long",@LONG
这是全真教中的掌管所有药物的道人。他年纪不大，但看起来显得少年老
成。
LONG
);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);

        set("combat_exp",3000000);

        create_family("全真教", 4 , "弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        NPC_D->full_init(this_object());
        
}

