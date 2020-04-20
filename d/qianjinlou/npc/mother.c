// mother.c - 鸨母

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("鸨母", ({ "mother" }) );
        set("long", @LONG
她是一名老鸨母，一把年纪了，还学人家妞妞捏捏的，看
起来十分便忸。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age",55);
	set("per",26);

        set("combat_exp",random(30000)+10000);
	set("shen_type",-1);
        set("env/wimpy", 30);			//

        setup();
        
	carry_object("/clone/cloth/pink-silk")->wear();	// 装备
	carry_object("/clone/cloth/gold-clasp")->wear();

        add_money("gold", 1);				// 金钱
}
