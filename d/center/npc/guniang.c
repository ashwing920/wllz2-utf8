// guniang.c - 二胡姑娘
// Design By Robert 蝴蝶君 Email:robert_st@263.net


#include <ansi.h>

inherit NPC;

void create()
{
        set_name("香香", ({ "xiang xiang","xiang","gu niang"}));
        set("title","二胡姑娘");
        set("long", @LONG
这是一位穷苦的小姑娘，终日在客栈中拉二胡维持生计。从来没有人问过
她的姓名，后来，人们便以二胡姑娘称呼她。
LONG
);

        set("attitude", "friendly");
        set("gender", "女性" );
        set("age", 18);
        set("per", 30);                 
        set("combat_exp",random(30000)+10000);
        set("shen_type",1);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

