//#pragma optimize
//#pragma save_binary

inherit F_DBASE;

#include <ansi.h>

int clean_up() { return 1; }

void auto_relaim();

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "内存精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "内存精灵已经启动。");
	call_out("auto_relaim", 40);
	call_out("check_player",60);
}

void auto_relaim()
{
	int i;

	if (i = reclaim_objects())
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("系统自动清除 %d 个变量。", i));

	remove_call_out("auto_relaim");
	call_out("auto_relaim", 300 + random(60));
}
void check_player()
{
	object *ob;
	object obj;
	int i;

	ob = filter_array(children(USER_OB),(: userp :));
	i=sizeof(ob);
	for( i=0;i<sizeof(ob);i++) {
		if(!environment(ob[i]) || !living(ob[i]) )continue;
		if(ob[i]->query_condition("killer") > 600){
			obj=new("/clone/npc/fae-shizhe");
			obj->move(environment(ob[i]));
			obj->set_leader(ob[i]);
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说武林侠义盟派出了罚恶使者%s，前往「%s」追杀恶贼%s。",obj->name(),environment(ob[i])->query("short"),ob[i]->query("name")));
		}
		else if(ob[i]->query_condition("killer") > 300
			&& ob[i]->query("PKS") - ob[i]->query("VKS") > 10 ){
			obj = find_object("clone/npc/xunbu");
			if(!obj) obj= load_object("clone/npc/xunbu");
			if(!obj->is_fighting()){
				tell_room(environment(ob[i]),sprintf("%s走了过来。\n",obj->name(1)));
				obj->move(environment(ob[i]));
				obj->set_leader(ob[i]);
			CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("派出%s一名前往%s追杀凶犯%s。",
				obj->name(2),environment(ob[i])->short(),ob[i]->name(2)));
			}
		}
	}
	remove_call_out("check_player");
	call_out("check_player",60 + random(60));
}
