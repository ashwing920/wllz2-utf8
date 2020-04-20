// smith.c - 铁匠

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("铁三", ({ "tie san","tie jiang","tie"}));
        set("nickname",HIC"铁匠"NOR);
        set("long", @LONG
他是这家打铁铺的老板铁三，家中世代以打铁为业，铸造出不少好铁器。
LONG
);

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 26);
        set("str", 30);
        set("cps", 30);
        set("per", 22);
        set("combat_exp",random(30000)+10000);
        set("shen_type",1);
        set("env/wimpy", 30);
        set("chat_chance",10);
        set("chat_msg",({
        	"铁三把一块红通通的烙铁放进水中，立刻发出哧哧的声响。\n",
        	"叮叮..当当，铁三手拿大铁锤，正在敲打一块烙铁。\n",
        	"铁三笑呵呵的说：桃源城里，有谁不知道俺铁三是出了名的铁匠师父。\n",
        }));
        setup();
        
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/hammer")->wield();

        add_money("silver", 10);
}

