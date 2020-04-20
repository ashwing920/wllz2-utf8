// daochang-dizi.c - 道场弟子

#include <ansi.h>

inherit NPC;

void create()
{
	set("title",HIY"武林大宗师"NOR);
	set_name("白发老者",({"baifa laozhe","laozhe","master"}));
	set("nickname",HIG"返璞"HIR"归真"NOR);
	set("long",@LONG
莫看他白发苍苍却是鹤发童颜。清瘦的脸颊，深陷的双眼炯炯有神。从他
喘息的气息中，顿可领略他内力修为何等的深厚。
LONG
);
	set("gender","男性");
	set("age",60);
	set("attitude", "heroism");
	set("is_zongshi",1);
	set("chat_chance_combat",250);
	set("chat_msg_combat", ({
		(: perform_action,"leg.lianhuan":),
		(: perform_action,"spear.zhimeng":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
		(: exert_function, "taixuan" :),
	}));

	set("max_jing",15000);
	set("jing",15000);
	set("max_qi",30000);
	set("qi",30000);
	set("max_neili",50000);
	set("neili",50000);
	set("jiali",300);

	add_temp("apply/damage",700);
	add_temp("apply/armor",700);
	add_temp("apply/dodge",700);
	add_temp("apply/attack",700);
	add_temp("apply/unarmed",700);

	set("combat_exp",20000000);

	set_skill("force",550);
	set_skill("taixuan-gong",550);
	set_skill("leg",550);
	set_skill("jueming-tui",550);
	set_skill("cuff",550);
	set_skill("kongming-quan",550);
	set_skill("spear",550);
	set_skill("duanhun-qiang",550);
	set_skill("unarmed",550);
	set_skill("xianglong-zhang",550);
	set_skill("dodge",550);
	set_skill("shaolin-shenfa",550);
	
	map_skill("dodge","shaolin-shenfa");
	map_skill("cuff","kongming-quan");
	map_skill("leg","jueming-tui");
	map_skill("unarmed","xianglong-zhang");
	map_skill("spear","duanhun-qiang");
	map_skill("force","taixuan-gong");

	create_family("武当派", 18,"弟子");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/spear")->wield();
}
void init()
{
	object me,ob;

	ob = this_object();

	if( interactive(me = this_player()) && !ob->is_fighting()
	&& !ob->query_temp("wait")) {
		remove_call_out("greeting");
		call_out("greeting",2,me,ob);
		ob->set_temp("wait",1);
	}
}
void greeting(object me,object ob)
{
	int lvl,time;
	lvl = environment()->query("lvl");

	if(!ob || !me || environment(me) != environment(ob)) return;
	switch( random(3) ) {
		case 0:
			say(ob->name(1)+"作了个揖道：这位" + RANK_D->query_respect(me)+ "，我是百人道场的第"+ chinese_number(lvl)+"层弟子，请出招吧！\n");
			break;
		case 1:
			say(ob->name(1)+"冷冷的笑道：能上到我百人道场"+ chinese_number(lvl)+"层，想必身手不凡，废话少说，准备接招吧！\n");
			break;
		case 2:
			say(ob->name(1)+"说道：挑战前有十秒让你做准备，如果你想中途退出比试，请往东面的休息室。\n");
			break;
	}
	time = 10;
	remove_call_out("check_time");
	call_out("check_time",5,time,me,ob);
}
void check_time(int time,object me,object ob)
{
	if( !me || !ob || environment(me) != environment(ob)
	|| me->is_fighting() || ob->is_fighting()) return;

	time -= 5;

	if( time <= 0){
		say("\n"+ ob->name(1)+"喝道："+ me->name(1)+"！接招吧！！\n\n");
		ob->kill_ob(me);
		me->kill_ob(ob);
	}
	else {
		tell_object(me,ob->name(1)+"急道：准备好了吗？还有"+ chinese_number(time)+"秒就要开始了！\n");
		call_out("check_time",5,time,me,ob);
	}
	return;

}
void afterdie_func(object killer)
{
	object room;

	if(killer){
		room = find_object("/d/daochang/zongshi_room");
		if(!room) room = load_object("/d/daochang/zongshi_room");
		room->reset_status();
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s[%s]成功挑战百人道场，成为新一代的武林大宗师！",killer->name(1),geteuid(killer)));
		tell_object(killer,HIW"恭喜！由于你成功的打败了百人道场的一百个弟子，晋升为新一代的武林大宗师。\n"NOR);
		killer->set("is_zongshi",1);
		killer->move(room);
	}
}
