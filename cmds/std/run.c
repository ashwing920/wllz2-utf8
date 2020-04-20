// run.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object *inv,ob,corpse;
	string move_path, msg;
	int i,total;
	mapping prop;

	if( !arg ) return help(me);

	if( me->is_fighting())
		return notify_fail("你现在正在战斗！\n");

	if( me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(!environment(me)->query("outdoors"))
		return notify_fail("这里空间太小，不能骑马！\n");

	if(me->query_temp("fangmu"))
		return notify_fail("你正在放牧！\n");

	if(TRANS_D->trans_to(arg) == "none")
		return notify_fail("你要到什么地方？\n");

	if(!objectp(ob = me->query_temp("ride_ob"))
		|| !present(ob,me))
		return notify_fail("你没有坐骑！\n");

	if(!mapp(prop = ob->query("horse_prop")))
		return notify_fail("你搞错了吧？怎么骑上了这个家伙？\n");

	if( prop["life"] <= 0 )
		return notify_fail("你的"+ ob->name() +"已经累得不能动了！\n");


	if( stringp(msg = me->query("env/msg_mgo")) )
		message_vision( msg + "\n", me);
	else
		message_vision("$N跨上" + ob->name() + NOR "，两腿一踢，消失在茫茫人海之中。\n", me);

	move_path = TRANS_D->trans_to(arg);
	me->move(move_path);

	if( stringp(msg = me->query("env/msg_mcome")) )
		message_vision(msg + "\n", me);
	else
		message_vision("一阵烈马的啼鸣，$N骑着「" + ob->name() + NOR "」出现在人群中。\n", me);

	prop["life"] -= 2;
	
	if( prop["life"] <= 0 ){
		if(ob->player_animal() && prop["max_life"] > 1
			&& (int)me->query("make_horse/max_life") > 1) {
				tell_object(me,"你的"+ ob->name()+ "由于劳累过度，生命力降低了。\n");
				me->add("make_horse/max_life",- 1);
				prop["max_life"] -= 1;
				me->save();
		}
		else {
			message_vision(ob->name() +"再也坚持不住，终于累死了。\n", me);
			ob->unequip();
			ob->delete("equipped");
			me->delete_temp("is_riding");
			me->delete_temp("ride_ob");
			if( ob->player_animal()) me->delete("make_horse");
			inv = all_inventory(ob);
			total = sizeof(inv);
			for( i = 0; i < total; i ++ ) inv[i]->move(me);
			corpse=new(CORPSE_OB);
			corpse->set_name(ob->name() + NOR"的尸体",({"corpse"}));
			corpse->set("long","一匹已经死掉了的马匹。\n");
			corpse->move(environment(me));
			destruct(ob);
			if(random(100) == 50) {
				message_vision("$N突然把持不住，重重的摔倒在地上。\n",me);
				me->unconcious();
			}
			return 1;
		}
	}
	if(prop["life"] <= 8) {
		tell_object(me,ob->name()+"已经显得很劳累了。\n" NOR);
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : run <地点>

利用坐骑到达某个地点。目前可以利用坐骑去的地方有：

桃源城：         ty      大理：           dl      佛山：           fs
成都：           cd      长安：           ca      扬州：           yz
北京：           bj　　　泉州：           qz　　　新疆：           xj
昆明：           km      衡阳城：　　　　 hyc     灵州：        　 lz
苏州：           sz      杭州：           hz	  襄阳：	   xy


HELP
	);

	return 1;
}
