// see.c
// Design By robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string filename,filename1,city_name;
	int len;

	filename=base_name(environment(me));
	len=strlen(filename);

	len--;
	while(filename[len]!='/' && len>0) {
		len--;
	}
	filename1 = base_name(environment(me));
	city_name = filename[1..(len-1)];

	if(!environment(me)) return 0;

	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if( me->is_fighting())
		return notify_fail("你正在战斗中！\n");
	if((int)me->query("jing") < 30 || (int)me->query("qi") < 30)
		return notify_fail("你太累了，还是休息一下再说吧。\n");
	if(!me->query_temp("xuncheng"))
		return notify_fail("你目前没有巡城任务，无需要视察周围环境。\n");
	if((int)me->query_temp("see"))
		return notify_fail("你正在视察周围环境呢！\n");
	if(city_name != (string)me->query_temp("xuncheng"))
		return notify_fail("你好象巡错地方了吧？\n");
	if(me->query_temp("xuncheng_path/"+ environment(me)->query("short")) > 0)
		return notify_fail("这里你已经巡视过了，不用再巡视了。\n");

	message_vision("$N开始环顾四周，仔细视察周围的环境！\n",me);
	me->set_temp("see",1);
	me->add("jing",-20);
	me->add("qi",-20);
	me->start_busy(2);
	call_out("compelete_see",1,me,filename1);
	return 1;
}
private void compelete_see(object me)
{
	object obj;

	me->delete_temp("see");
	me->start_busy(0);
	switch(random(30)){
		case 10:
			obj=new("/clone/npc/xc_npc");
			obj->move(environment(me));
			tell_object(me,"你突然听到远处传来一阵呼救声：“救命啊，救救我啊……\n");
			tell_object(me,sprintf("你急忙跑过去一看，原来是一个%s正在欺负一位可怜的%s。\n",obj->name(),obj->query("help_ob_name")));
			message_vision( sprintf( "$N对%s喝道：“大胆狂徒，敢在光天化日之下欺压百姓！”\n",obj->name()),me);
			message_vision( sprintf( "%s对$N喝道：“不要命了，敢管大爷的闲事！”\n",obj->name()), me);
			me->set_temp("xuncheng_path/"+ environment(me)->query("short"),1);
			me->set_temp("xuncheng_path/"+ obj->name(1),1);
			me->kill_ob(obj);
			obj->kill_ob(me);
			obj->set_leader(me);
			break;
		case 15:
			tell_object(me,"你发现一个盐贩子正在贩卖私盐，你喝道：该死的，竟敢贩卖私盐？！\n");
			tell_object(me,"盐贩子听你一喊，连忙收拾摊档，拔腿就跑！\n");
			me->set_temp("xuncheng_path/"+ environment(me)->query("short"),1);
			break;
		default:
			tell_object(me,environment(me)->query("short")+ NOR"附近治安良好，你可以放心离开了。\n");
			me->set_temp("xuncheng_path/"+ environment(me)->query("short"),1);
			break;
	}
	return;

}
int help(object me)
{
    write(@HELP
指令格式 : see

这个指令可以让你巡视周围环境，主要是做巡城任务的时候使用。

HELP
    );
    return 1;
}
