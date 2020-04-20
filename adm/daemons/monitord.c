// monitord.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

void create()
{
	seteuid(getuid());
	set("name", "监控精灵");
	set("id", "monitord");
	set("channel_id","监控精灵");
}

void report_system_msg (string msg)
{
	CHANNEL_D->do_channel(this_object(), "sys", msg);
	log_file("monitord","["+ctime(time())+"] "+msg+"\n");
}
void report_system_object_msg (object ob, string msg)
{
	CHANNEL_D->do_channel(this_object(), "sys",
		ob->name(2) + msg);
	log_file("monitord","["+ctime(time())+"] "+ob->name(2)+ msg+"\n");
}
