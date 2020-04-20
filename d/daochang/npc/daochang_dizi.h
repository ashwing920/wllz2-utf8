
#include <ansi.h>

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
			say(ob->name(1)+"说道：挑战前有二十秒钟你做准备，如果你想中途退出比试，请往东面的休息室。\n");
			break;
	}
	time = 20;
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
	int lvl = environment(this_object())->query("lvl");

	if(killer){
		room = find_object("/d/daochang/daochang"+(lvl+1));
		if(!room) room = load_object("/d/daochang/daochang"+(lvl+1));
		room->reset_status();
		message_vision("$N成功的打败了"+ this_object()->query("title")+"，终于可以进入了百人道场第"+ chinese_number(lvl+1) +"层了。\n",killer);
		killer->move(room);
	}
}
