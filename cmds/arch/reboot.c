// shutdown.c with time loop.

#include <ansi.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

int counting = 0;

int help (object me)
{
	write(@HELP
指令格式: reboot < min|now >

例：
	reboot      :  显示这个信息。
	reboot now  :  马上重新起动游戏。
	reboot 3    :  等三分钟，然后重新起动游戏。

HELP
);
	return 1;
}
int start_shutdown(int i)
{
	if( !intp(i) ) i = 3;
	message_system(code_name() +"将在"+ chinese_number(i) +"分钟后重新启动，请在线玩家退出，稍后尝试连线。"NOR);
	call_out("countdown", 60, i);
	counting = 1;
	return 1;
}
int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i, time;

	if( me != this_player(1) ) return 0;

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动本游戏。\n");

	user = filter_array(objects(), (: userp :));
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	log_file("static/REBOOT", geteuid(me) + " reboot "+code_name()+" on: "+ ctime(time()) + "\n");
	seteuid(getuid());

	if (!arg) return help(me);

	if (arg == "now") {
		message_system(code_name()+"现重新启动。请在线玩家退出，请稍候一分钟再尝试连线。");
		if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
		shutdown(0);
	}

	if (sscanf(arg,"%d", time) != 1) return help(me);

	if( !intp(time) || time < 1) return help(me);

	if(counting != 0) return notify_fail("系统已经进入重新启动状态了。\n"NOR);

	if(start_shutdown(time)){
		write("游戏开始进入重启倒计时！......\n");
		LOGIN_D->set_lock(1);
	}
	else {
		return notify_fail ("定时Reboot有问题，请检查 /cmds/arch/reboot.c  \n");
	}
	return 1;
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message_system(code_name()+"将在"+ chinese_number(min) + "分钟后重新启动，请在线玩家退出，稍后尝试连线。");
		call_out("countdown", 60, min);
	} else {
		message_system(code_name()+"现重新启动。请在线玩家退出，稍候一分钟再尝试连线。");
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
	object *ob,link_ob;
	int i;

	ob = filter_array(children(USER_OB),(: userp :));
	i=sizeof(ob);
	for(i=0;i<sizeof(ob);i++){
		if(!environment(ob[i]) )continue;
		if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
		ob[i]->save();
		link_ob->save();
	}
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
}
