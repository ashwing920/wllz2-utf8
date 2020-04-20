#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("冬儿", ({ "kkking" }) );
        set("long","风云中最大的帮派，权力帮的天王。\n");
	set("nickname", BLU"鬼王"NOR);
        create_family("权力帮",2,"天王");
	set("str", 20);
        set("cor", 20);
        set("cps", 20);
	set("agi",20);
	set("int",20);
	set("attitude","friendly");
        set("max_neili", 10000);
        set("max_jingli",2000);
	set("neili", 10000);
        set("jiali", 30);
	set("combat_exp", 1000000);
	set_temp("apply/damage",500);
	set("chat_chance", 2);
	set("chat_msg", ({
                "冬儿说道：上天入地，十九人魔。\n",
                "冬儿说道：帮主神出鬼没，我也不知道他的行踪。\n",
        }) );
	setup();
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "quanli");
}
