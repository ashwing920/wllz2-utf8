// baby.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object baby;
	string gender,baby_g;

	if (duration < 1) return 0;
	me->apply_condition("baby", duration - 1);
	if (duration == 1) {
		if(random(5) >= 2){
			gender = "男性";
			baby_g = "男婴";
		}
		else {
			gender = "女性";
			baby_g = "女婴";
		}
		message_vision("突然一阵撕心裂肺的疼痛淹没了$N，$N不禁惨叫了一声，$N的孩子要出生了！\n$N努力着，为了把这个小生命带到这个世界而努力着，……，\n一阵清脆的孩啼传来，$N的孩子出生了\n",me);
		tell_object(me,"恭喜！你生下了一个白白胖胖的"+ baby_g+"！\n");
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("%s，%s生下了一个%s。",
				NATURE_D->game_time(time()),me->name(),baby_g));
		baby = new("/clone/npc/baby");
		if(me->query("marry"))
			baby->set_name(me->query("name")+"和"+ me->query("marry_name")+"的孩子",({ me->query("id")+"_"+ me->query("marry")+"_baby","baby"}));
		else
			baby->set_name(me->name(1)+"和某人的私生子",({ me->query("id") +"_nobody_baby","baby"}));
		baby->set("gender",gender);
		baby->set("birthday",time());
		baby->set("father_name",me->query("marry_name"));
		baby->set("mather_name",me->query("name"));
		baby->set("father_id",me->query("marry"));
		baby->set("mather_id",me->query("id"));
		baby->set("long",me->name()+"和"+ me->query("marry_name") +"的爱的结晶。\n");
		baby->save();
		baby->move(environment(me));
		me->set("baby/gender",gender);
		me->set("baby/time",NATURE_D->game_time(time()));
		me->set("baby/id",baby->query("id"));
		me->set("baby/make",1);
		me->set("baby/get",1);
		me->receive_wound("qi",100);
		me->receive_wound("jing",100);
		me->set_temp("die_for","死于难产！！");
	}
	if(duration > 599 ){
		if(random(5) == 2)
		tell_object(me,HIM"春花雨露，珠胎暗结，恭喜你怀孕了！\n"NOR);
	}
	else if(duration >= 500 ){
		if(random(5) == 2)
		tell_object(me,HIM"你已经怀孕了，要好好保重身体哦！\n"NOR);
	}
	else if(duration >= 400 && duration < 500){
		if(random(5) == 2)
		tell_object(me,HIM"你的肚子渐渐隆起，行动也不如以前方便了。\n"NOR);
		message("vision", me->name() + "的小腹渐渐隆起，看来是怀孕了。\n", environment(me), me);
	}
	else if(duration >= 300 && duration < 400){
		if(random(5) == 2)
		tell_object(me,HIM"你肚子里的小生命轻轻的挪动，你只觉得肚中幽幽的一阵疼痛。\n"NOR);
	}
	else if(duration >= 200 && duration < 300){
		if(random(5) == 2)
		tell_object(me,HIM"你的肚子越来越大，肚子里的小生命还不时捅了捅你，好痛哟！\n"NOR);
		message("vision", me->name() + "单手撑腰，肚子已经逐渐变大了。\n", environment(me), me);
		me->start_busy(1);
	}
	else if(duration >= 50 && duration < 200){
		if(random(5) == 2)
		tell_object(me,HIM"你肚子里的小宝贝踢得你的肚子阵阵疼痛，好顽皮哦！\n"NOR);
		message("vision", me->name() + "大腹便便，看起来"+ me->query("marry_name")+"做爸爸的日子已经不远了。\n", environment(me), me);
		me->start_busy(2);
	}
	else if(duration < 50 && duration > 10 ){
		if(random(5) == 2)
		tell_object(me,HIM"你只觉得一阵紧过一阵的疼痛向你袭来，看来你的孩子快要出生了！\n"NOR);
		message("vision", me->name() + "捂着肚子，时而邹紧了眉头，显得十分辛苦。\n", environment(me), me);
		me->start_busy(3);
	}
	else if(duration < 10 ){
		tell_object(me,HIM"你只觉得肚子里一阵阵的绞痛，你的孩子快要出生了！\n"NOR);
		message("vision", me->name() + "头冒冷汗，捂着肚子，发出阵阵痛苦的哀号。\n", environment(me), me);
		me->start_busy(4);
	}

	return 1;
}
