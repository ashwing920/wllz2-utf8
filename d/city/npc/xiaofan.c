

#include <ansi.h>

inherit NPC;

#define SET_SKILL	   60			  // 定义基本武功的值（随机），自动生成经验

void create()
{
	int n;

	set_name("小贩", ({ "xiao fan" }) );

	set("long", @LONG
他是一个小贩。
LONG
	);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 21);			   
	set("str", 20);			 
	set("cps", 20);		 
	set("cor", 20);				 
	set("per", 20);			 
	set("con", 20);			

	set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);

	set("env/wimpy", 30);		

	n = SET_SKILL + random(10) - 5;	 set_skill("unarmed", (n <= 0) ? 1 : n); 
	n = SET_SKILL + random(10) - 5;	 set_skill("parry",   (n <= 0) ? 1 : n);
	n = SET_SKILL + random(10) - 5;	 set_skill("dodge",   (n <= 0) ? 1 : n);
	
		  setup();
	
	carry_object("/clone/cloth/cloth")->wear();   // 装备
}
