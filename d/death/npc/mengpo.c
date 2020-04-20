// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit NPC;

int give_soup();

void create()
{
        set_name("孟婆", ({ "mengpo", "meng"}) );
        set("gender", "女性" );
        set("age", 220);
        set("long", @LONG
据说孟婆追随老伴到地府之后，因生活无着落，人心甚好，所以阎王特准
她在这里做点生意，因为孟婆汤（ｓｏｕｐ）好，所以以卖汤为生，后阎
王传其一方，可以使人忘却地狱的苦痛，于是孟婆的生意便一日好过一日
。投生的人都爱在此买一碗后走上轮回之路。
LONG);
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_temp("apply/astral_vision",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "孟婆对你说：＂在下面受了不少苦吧，来碗汤吧！＂\n",
                "孟婆说：＂孩子，上路前喝一碗吧！＂\n",
        }) );
        set("inquiry", ([
                "孟婆汤" : (: give_soup:),
                "soup" : (: give_soup:)

        ]));
        setup();
        add_money("silver", 5);
        carry_object("/clone/cloth/cloth")->wear();
}

int give_soup()
{
        object obj;
        if( !query("given"))
        {
                message_vision("$N以熟练的手法舀起一碗汤递给$n。\n",this_object(),this_player());
                command("say 别厌弃，快点儿喝，喝完好上路！\n");
                obj = new(__DIR__"obj/dang");
                obj->move(this_player());
                if(!random(10))set("given",1);
        }
        else
                command("say 唉呦！刚刚卖光，你等着，我就去再熬一锅！\n");
                return 1;
}

void reset()
{
        delete("given");
}
