// pitiao-ke.c - 皮条客

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("皮条客", ({ "pitiao ke", "pitiao" }) );
        set("long", @LONG
他是千金楼的皮条客，为千金楼可赚了不少钱。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 35);
        set("combat_exp",random(30000)+10000);
	set("shen_type",1);

        set("env/wimpy", 30);
        setup();
        
	carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 1);
}

void init()
{       
        object ob;

	if( this_object()->query_temp("unconcious") ) return;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }
}
void greeting()
{
	object ob;
	ob = this_player();
	switch(ob->query("gender")){
		case "男性":
			say("皮条客嬉皮笑脸的迎了上来，笑道：" + RANK_D->query_respect(ob)+"里面请，里面请！\n");
			break;
		case "女性":
			say("皮条客惊讶的说道：这位"+ RANK_D->query_respect(ob)+"怎么也跑到这里来了？\n");
			break;
		case "无性":
			say("皮条客笑道：哎呀！真是奇了，如今世道，太监也来寻乐子来了。\n");
			break;
	}
	return;
}