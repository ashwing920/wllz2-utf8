// by snowcat on 7/5/1997
inherit NPC;

int random2(int i)
{
	return (random(i)+uptime()) % i;
}

// Micro: 在场景中还另有调用，要小心处理。
void set_ok()
{
	set("str", 40+random2(8));
	set("spi", 40+random2(8));
	set("cor", 40+random2(8));
	set("con", 40+random2(8));
	set("cor", 40+random2(8));
	set("cps", 40+random2(8));
	set_skill("unarmed", random2(10));
	set_skill("dodge", random2(10));
	set_skill("parry", random2(10));
}

void create()
{
	set_name("斗鸡", ({ "dou ji", "ji" }) );
	set("race", "飞禽");
	set("subrace","走禽");
	set("gender", "雄性");
	set("age", 2);
	set("long", "一只雄赳赳的斗鸡。\n");
	set("attitude", "friendly");
	set_ok();
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite"}) );

	setup();
}