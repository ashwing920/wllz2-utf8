// reboot.c 事件：自动开奖

void create() { seteuid(ROOT_UID); }


// 开始创建事件
void create_event()
{
	// 一个星期的晚上九点开始
	EVENT_D->at_after(0,0,6,-21);
}
// 事件触发
void trigger_event()
{ 	
	"/adm/daemons/lotd"->ready_start();
}
