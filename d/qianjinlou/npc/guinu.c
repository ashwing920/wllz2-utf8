// guinu.c - 龟奴

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("龟奴", ({ "gui nu" }) );
        set("long", @LONG
他是一名龟奴，经常嬉皮笑脸的，让人感觉十分恶心。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 35);
        set("combat_exp",random(30000)+10000);
	set("shen_type",1);
        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/guinu-cloth")->wear();
        add_money("silver", 2);
}
