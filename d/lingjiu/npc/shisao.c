// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// shisao.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("石嫂", ({ "shi sao", "shi", "sao" }));
        set("long",@LONG
她是「灵鹫宫」九天九部中朱天部的首领。她跟随童姥多年, 出生
入死，饱经风霜。
LONG
);
        set("title", "朱天部首领");
        set("gender", "女性");
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("jing",4000);
        set("max_jing",4000);
        set("neili",5000);
        set("max_neili",5000);
        set("jiali",120);
        set("combat_exp",2700000);
        set("score",10000);
        set_skill("force",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("hand",200);
        set_skill("strike",200);

        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("yueying-wubu",200);
        set_skill("bahuang-gong",200);
        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");

        create_family("灵鹫宫",3,"弟子");
        setup();
        
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",20);
        
}
