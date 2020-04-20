// bianfu.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蝙蝠", ({ "bianfu","bad" }) );
        set("race","飞禽");
        set("age",10);
        set("long","一只黑色的蝙蝠，红红的眼睛。\n");
        set("attitude","aggressive");
        
        set("str", 26);
        set("cor", 30);
	set("chat_chance",5);
	set("chat_msg",({
		(: random_move :),
	}));
        set("combat_exp",3000000);
        set_temp("apply/attack",300);
        set_temp("apply/damage",300);
        set_temp("apply/armor",300);
        setup();
}
