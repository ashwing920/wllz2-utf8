// xiaofan.c 小贩
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "xiao fan","seller","waiter" }) );
	set("long", @LONG
这是一个小贩，在桃源城贩卖饺子已经多年了。
LONG
);
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 40);
	set("per", 26);
	set("combat_exp",20000+random(20000));
	set("env/wimpy", 40);
	set("chat_chance",5);
	set("chat_msg",({
		"小贩高声叫卖：快来买啦！热腾腾的桃源饺子了！\n",
		"小贩叫喊着：快来买了，刚出炉的热包子咯！\n",
	}));
	
	set("vendor_goods",([
		"/clone/food/baozi": 20,
		"/clone/food/jiaozi": 20,
		"/clone/food/mian": 20,
	]));
	set_skill("unarmed", 50); 
	set_skill("parry",   50);
	set_skill("dodge",   50);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	add_action("do_vendor_list","list");
}