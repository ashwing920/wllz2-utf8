// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// lanjian.c

inherit NPC;

void create()
{
        set_name("兰剑", ({ "lan jian", "lan"}));
        set("long",@LONG
这是个容貌姣好的女子, 瓜子脸蛋，眼如点漆，清秀绝俗。你总觉得在哪
见过她。
LONG
);
        set("gender", "女性");
        set("age", 18);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("jing",3000);
        set("max_jing",3000);
        set("neili",4500);
        set("max_neili",4500);
        set("jiali",225);

        set("combat_exp",2700000);
        set("score",10000);
        set_skill("force",300);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("parry",300);
        set_skill("hand",300);
        set_skill("strike",300);
        set_skill("sword",300);

        set_skill("zhemei-shou",300);
        set_skill("liuyang-zhang",300);
        set_skill("tianyu-qijian",300);
        set_skill("yueying-wubu",300);
        set_skill("bahuang-gong", 300);

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
