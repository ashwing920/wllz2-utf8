// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

private void create()
{
	seteuid(getuid());
	set("channel_id", "离线精灵");
}
int main(object me, string arg)
{
	int i,j;
	object *inv, link_ob;
	link_ob = me->query_temp("link_ob");
	inv = all_inventory(me);

	if( LOGIN_D->get_madlock())
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");

	if(!me->query_temp("netdead") && interactive(me)){
		if( me->is_busy())
			return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");

		if(me->query("baby") && !me->query("baby/die") && !me->query("baby/put")
		&& me->query("baby/get"))
			return notify_fail("你还是先把孩子送到托儿所再走吧！\n");

		if( me->over_encumbranced())
			return notify_fail("你的负荷太重，无法离开这个世界。\n");

	}
	if(VENDOR_D->query_bid() == (string)me->query("id")
	|| VENDOR_D->query_vid() == (string)me->query("id")
	|| !VENDOR_D->check_vendor((string)me->query("id")))
		return notify_fail("你现在正在拍卖物品，不能离开游戏。\n");

	if( me->query_condition("f_killer")
	|| me->query_condition("killer")
	|| me->query_condition("parsion"))
		return notify_fail("你现还有官非在身，不能离开游戏。\n");

	if(me->is_fighting())
		return notify_fail("战斗中不能离开游戏！\n");

	if (me->run_override("quit")) return 1;

	for(i=0; i<sizeof(inv); i++){
		if(inv[i]->query("equipped"))
		inv[i]->delete("equipped");
		if( !inv[i]->query_autoload())
		destruct(inv[i]);
	}
	if( link_ob ){
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		if(link_ob->query("passed_ids")){
			BAN_D->remove_pass_id(query_ip_number(me));
			BAN_D->remove_pass_id(me->query_temp("my_ip"));
			tell_object(me,HIW"【系统提示】您的多重登陆权限已经关闭了！\n"NOR);
		}
		destruct(link_ob);
	}

	i=me->query("combat_exp")-me->query_temp("temp_exp");
	if (i < 0 ) i=0;
	j=(me->query("potential") - me->query("learned_points")) - me->query_temp("temp_pot");
	if(!wizardp(me)) {
		write(HIY"\n注意：如果你是在网吧登陆，请确认 Zmud 中是否保留你帐号的密码，\n"
			"避免你的帐号不被他人盗用。欢迎下次光临！再见！！\n"NOR);
		message("system", me->name() + "离开游戏。\n", environment(me), me);
	}
		CHANNEL_D->do_channel(this_object(),
			"sys",sprintf("%s离开游戏，本次连线时间%s。\n\t本次连线经验增长%d，潜能增长%d。目前经验总值[%d]。\n",
			me->name(2),CHINESE_D->chinese_period(FINGER_D->online_time(me)),
			i,j,(int)me->query("combat_exp")));

	if( (int)me->query("combat_exp") - (int)me->query_temp("temp_exp") >= me->query("combat_exp") / 100 ){
		log_file( "static/WARNING", sprintf("%s（%s）在 %s 退出。经验增长：%d 经验总合：%d [连线时间："+CHINESE_D->chinese_period(FINGER_D->online_time(me))+"]\n",
			me->query("name"), me->query("id"), ctime(time()),((int)me->query("combat_exp") - (int)me->query_temp("temp_exp")),
			(int)me->query("combat_exp")));
	}
	if(((int)me->query("potential") - (int)me->query("learned_points")) - (int)me->query_temp("temp_pot") >= 5000 ) {
		log_file( "static/WARNING", sprintf("%s（%s）在 %s 退出。潜能增长：%d 潜能总合：%d [连线时间："+CHINESE_D->chinese_period(FINGER_D->online_time(me))+"]\n",
			me->query("name"), me->query("id"),ctime(time()),
			((int)me->query("potential") - (int)me->query("learned_points")) - (int)me->query_temp("temp_pot"),
			(int)me->query("potential") - (int)me->query("learned_points")));

	}
	TOPTEN_D->topten_checkplayer(me);
	me->save();
	destruct(me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit | exit

当你(你)想暂时离开时, 可利用此一指令。
HELP
	);
	return 1;
}
