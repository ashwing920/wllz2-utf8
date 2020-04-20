// reboot.c 事件：自动重启

void create() { seteuid(ROOT_UID); }

#define REBOOT_CMDS	"/cmds/arch/reboot"

// 开始创建事件
void create_event()
{
	// 一个星期后的凌晨七点钟开始
	EVENT_D->at_after(0,0,7,-7);
}
private void auto_reboot()
{
	object *ob,link_ob;
	int i;
	ob = users();

	for(i=0;i<sizeof(ob);i++){
		if(objectp(link_ob = ob[i]->query_temp("link_ob"))) 
		link_ob->save();
		ob[i]->save();
	}
	log_file("static/REBOOT","系统自动重新启动事件开始于["+ ctime(time()) +"]。\n");
	REBOOT_CMDS->start_shutdown(5);
	LOGIN_D->set_lock(1);
}	
// 事件触发
void trigger_event()
{ 	
	auto_reboot();
	create_event();
}
