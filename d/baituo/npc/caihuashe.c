// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("菜花蛇", ({ "caihua she", "she" }) );
	set("race", "蛇类");
	set("age", 1);
	set("long", "一只青幽幽的菜花蛇，头部呈椭圆形。\n");
	set("attitude", "peaceful");

	set("str", 15);
	set("cor", 16);
	set("eatable",1);
	set("afterdie","/d/baituo/obj/sherou");
	set("combat_exp",10000+random(50000));

	set_temp("apply/attack", 7);
	set_temp("apply/damage", 4);
	set_temp("apply/defence",6);
	set_temp("apply/armor",5);

	setup();
}
