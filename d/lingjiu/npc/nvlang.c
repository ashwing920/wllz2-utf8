// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// 蒙面女郎

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蒙面女郎", ({ "nv lang", "nv"}));
        set("long",@LONG
这是个身材娇好的女郎, 轻纱遮面，一双秀目中透出一丝杀气。
LONG
);
        set("gender", "女性");
        set("age", 20);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("jing",6000);
        set("max_jing",6000);
        set("neili",4000);
        set("max_neili",4000);
        set("jiali",200);

        set("combat_exp",3000000);
        set("score", 100000);
        set_skill("force", 200);
        set_skill("unarmed",200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand",200);
        set_skill("strike",200);
        set_skill("sword",200);

        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("tianyu-qijian",200);
        set_skill("yueying-wubu",200);
        set_skill("bahuang-gong", 200);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");

        create_family("灵鹫宫",3,"弟子");
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver",15);
}
