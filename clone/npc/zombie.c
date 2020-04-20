// zombie.c

#include <ansi.h>
inherit NPC;
void do_bite();
void create()
{
	set_name("僵尸", ({ "zombie" }) );
	set("long", "这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
	set("max_jing", 400);
	set("max_qi", 400);
	set("max_jingli", 600);
	set("str", 60);
	set("cor", 40);
	set("haunt", 0);
	set("chat_chance", 30);
	set("chat_msg_combat", ({
		"僵尸口中发出荷荷的叫声。\n",
		"僵尸的脸上开始痉挛，一阵抽搐，发狂似地大叫。\n",
		"僵尸五指箕张，咬牙切齿，露出狰狞的笑容。\n",
		(: do_bite :),
	}) );
	set_skill("unarmed", 40);
	set_skill("dodge", 30);

	set_temp("apply/damage", 25);
	set_skill("unarmed", 1);
	set_skill("jiuyin-baiguzhao", 1);
	set_skill("qingfu-shenfa", 1);
	set_skill("force", 1);
	set_skill("magic", 1);
	set_skill("spells", 1);
	set_skill("xuehai-mogong", 1);
	set_skill("dodge", 1);
	set_skill("parry", 1);
	map_skill("dodge", "qingfu-shenfa");
	map_skill("force", "xuehai-mogong");
	map_skill("unarmed", "jiuyin-baiguzhao");
	map_skill("parry", "jiuyin-baiguzhao");

	setup();
}

void init()
{
	object targ;
	string target;

	::init();
	if(query("haunt") == 1) {
		if( ! (target = query("haunttar"))||target->query("env/important") )  return;
		if(objectp(targ = present(target, environment()))) {
			message_vision("$N眼睛忽然睁开，喃喃地说道：" RED "杀....死....$n....\n" NOR, this_object(), targ);
			this_object()->kill_ob(targ);
			this_object()->set_leader(targ);
			targ->kill_ob(this_object());
		}
	}
}
int is_zombie() { return 1; }

void animate(object who, int level)
{
	int exp, temp, iRet,i;
	mapping skill_status;
	string *sname;
	set("possessed", who);
	set_leader(who);
	set("max_neili", level*3);
	set("neili", level*6 );
	set("max_jingli", level*3);
	set("jingli", level*6);
	set("max_jing", level*3);
	set("jing", level*6);
	exp = level * level /150 * random(level) * 100 ;
	set("combat_exp", exp);
	if ( mapp(skill_status = query_skills()) ) {
		skill_status = query_skills();
		sname  = keys(skill_status);
		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			iRet = (exp/level/level)*10;
			set_skill(sname[i], iRet);

		}
	}
	set("jiali", query_skill("force") / 4);
	setup();
	
}

void dispell()
{
	if( environment() ) {
		say( name() + "缓缓地倒了下来，化为一滩血水。\n");
	}
	destruct(this_object());
}

int heal_up()
{
	object master;
	int lvl;

	if( objectp(master = query("possessed"))) { 
		lvl = (int)master->query_skill("blackart", 1);
		if((int)master->query("jingli") > lvl ) {
			message("tell", HIR + name() +  "告诉你：我....需....要....你....的....力....量....\n" NOR, master );
			master->add("jingli", -lvl);
			master->receive_damage("jing", lvl / 10);
			::heal_up();
			return 1;            
		} 
	} 
	call_out("dispell", 1);
	return ::heal_up();
}

void do_bite()
{
	object *enemy;

	say( name() + "口中喷出一股中人欲呕的臭气，使你觉得头晕脑胀。\n" );
	enemy = query_enemy();
	for(int i=0; i<sizeof(enemy); i++) {
		if( !enemy[i] ) continue;
		enemy[i]->receive_damage("jing", 20);
		COMBAT_D->report_status(enemy[i], "jing");
	}
}
