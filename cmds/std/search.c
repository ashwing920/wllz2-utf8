// eat.c
// Design By robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int time;

	time = environment(me)->query_temp("search_time");

	if(!environment(me)) return 0;

	if((int)me->query("jing") < 30 || (int)me->query("qi") < 30)
		return notify_fail("你太累了，还是休息一下再找吧。\n");

	if( environment(me)->query_temp("task_fail") == me)
		return notify_fail("这里已经被你翻遍了，没什么好找的了。\n");

	if(me->query_temp("searching"))
		return notify_fail("你正在找东西呢！\n");


	environment(me)->add_temp("search_time",1);
	if(time > random(30)+20) {
		environment(me)->set_temp("task_fail",me);
	}
	write("你开始细心的四处搜索，每一个角落都不放过. . .\n");
	me->set_temp("searching",1);
	me->add("jing",-20);
	me->add("qi",-20);
	call_out("compelete_search",1,me);
	return 1;
}

protected void compelete_search(object me)
{
	object obj;
	string filename,filename1;
	int len;

	filename=base_name(environment(me));
	len=strlen(filename);

	len--;
	while(filename[len]!='/' && len>0) {
		len--;
	}

	filename1=filename[0..(len-1)];

	me->delete_temp("searching");
	if(filename1 != me->query("quest/quest_path")){
		tell_object(me,"你翻了好一阵子，什么也没找到，可能找错地方了。\n");
		return;
	}

	if( random(10) == 1
	&& me->query("kar") > random(10)+ 21){
		obj= new("/clone/money/silver");
		message_vision("$N翻了大半天，终于找到了一锭"HIW"白银"NOR"！\n",me);
		obj->move(me);
		return;
	}
	if(!me->query("quest/search_name")
	|| (int)me->query("quest/task_time") < time()
	|| me->query("quest/search_finish")){
		message_vision("$N翻了大半天，结果什么也没有找到。\n",me);
		return;
	}
	switch (random(15)){
		case 4:
			obj = new("/clone/misc/taskobj");
			obj->set("name",me->query("quest/search_name"));
			obj->set("owner_name",me->query("quest/obj_master"));
			obj->set("owner_id",me->query("quest/obj_master_id"));
			obj->move(me);
			me->set("quest/search_finish",1);
			message_vision("$N花了九牛二虎之力，终于找到$n了！\n",me,obj);
			break;
		default:
			message_vision("$N翻了大半天，依然什么也找不着！\n",me);
			break;
	}
	return;
}
int help(object me)
{
    write(@HELP
指令格式 : eat <物品名称>

这个指令可以让你吃食物。

HELP
    );
    return 1;
}

