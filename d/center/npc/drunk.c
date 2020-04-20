// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit NPC;

void do_drink();

void create()
{
        set_name("醉汉", ({ "drunk" }));
        set("long", @LONG
这是一位喝得醉熏熏的汉子，手里拿着酒瓶子，正
胡言乱语的不知道说什么。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);
        set("combat_exp",15000);
        set("shen_type",1);
        set("env/wimpy", 30);                   

        set("chat_chance",5);
        set("chat_msg", ({
                (: do_drink :), 
                (: random_move :),
        }));
        setup();
        carry_object("/clone/cloth/cloth")->wear();     // 装备
        carry_object("/clone/food/jiudai");
}
 
void do_drink()
{
        object *list, ob;
        int i, can_drink;
        if( this_object()->query_temp("unconcious") ) return;
        if ((int)this_object()->query("water") >= 380) return;
        list = all_inventory(this_object());
        i = sizeof(list);
        can_drink = 0;
        while (i--) {
                if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
        if (can_drink) {
                command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
                command("drop jiudai");
}
    else {
                command("sigh");
                command("say 酒..... 给我酒....我没醉！！");
    }
        return;
}
 
int accept_object(object who, object ob)
{
        if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say 空的我不要....");
            return 0;
        }
        else {
            command("smile");
            command("say 多谢！");
            command("drink jiudai");
            return 1;
        }
    }
    else return 0;
}
 
