// wugu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG "五姑" NOR, ({ "wu gu"}));
        set("shen_type", 0);
        set("age",31);
        set("gender", "女性");
        set("per",7);
        set("long",@LONG
只见她一张肿得犹如猪八戒一般，双眼深陷肉里，几乎睁不开眼睛，喘气
甚急，像是扯着风箱。
LONG
);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "班淑娴" : "那个贱妇总有一天我会杀了她。\n",
                "陷害" : "你什么意思......。\n",
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

