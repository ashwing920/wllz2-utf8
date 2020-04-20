//cron.c
// 使命[Task]监护精灵

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

static int LAST_HARD_DIS= 0;

void init_cron();
void recall();

void create()
{
	seteuid(getuid());
	set("channel_id", "使命精灵");
	init_cron();
}
int query_last_hard_dis()
{
	return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
	LAST_HARD_DIS = time();
	return time();
}

void init_cron()
{
	mixed *local;
	local = localtime(time());
	if(!((local[1])%40)) recall();

	if(!((local[1])%40))
	if(random(2))TASK_D->init_dynamic_quest();
	else TASK_D->init_dynamic_quest(1);
	call_out("init_cron", 60);
}
void recall()
{
	object *user ;
	int i;
	user = users();
	CHANNEL_D->do_channel(this_object(),"sys","使命系统自动更新完毕！");
	message("system",HIC"【官府通告】刑部衙差：发下本月武林列传使命榜。\n"NOR, users());
	for(i=0; i<sizeof(user); i++)
	if(user[i]->query_temp("dynamic_find")){
		user[i]->delete_temp("dynamic_find");
		user[i]->save();
	}
}
