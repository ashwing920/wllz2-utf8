// yuanhou.c

inherit NPC;

void create()
{
	set_name("猿猴",({ "monkey","hou"}) );
	set("gender","雄性");
	set("race", "野兽");
	set("age", 2);
	set("long",@LONG
一只大猿猴，一身乌黑毛发，足足有一个人高。深陷的眼睛里充满了饥饿
，野性。
LONG);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "aggressive");
	set("max_qi",10000);
	set("qi",10000);
	set("max_jing",5000);
	set("jing",5000);
	set("neili",8000);
	set("max_neili",8000);
	set("combat_exp",3000000);
	set_skill("force",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_temp("apply/armor",200);
	set_temp("apply/dodge",200);
	set_temp("apply/damage",100);
	setup();
}
