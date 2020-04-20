// yuanhou.c

inherit NPC;

void create()
{
	set_name("巨猿",({ "big monkey","yuan","monkey"}) );
	set("gender","雄性");
	set("race", "野兽");
	set("age", 2);
	set("long",@LONG
一只巨大的猿猴，一身乌黑毛发，足足有两个人高。深陷的眼睛里充满了饥饿
，野性。
LONG);
	set("str",40);
	set("dex",40);
	set("con",40);
	set("int",40);
	set("attitude","aggressive");
	set("max_qi",45000);
	set("qi",45000);
	set("max_jing",25000);
	set("jing",25000);
	set("neili",50000);
	set("max_neili",50000);
	set("jingli",40000);
	set("max_jingli",40000);
	set("combat_exp",3000000);
	set_skill("force",300);
	set_skill("unarmed",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_temp("apply/armor",500);
	set_temp("apply/dodge",200);
	set_temp("apply/damage",500);
	setup();
}
