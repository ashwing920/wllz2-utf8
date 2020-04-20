// eventd.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

string *wizard_msg=({
	"\n新手精灵顿了顿，摇头晃脑的念道：\n",
	"\n新手精灵轻轻的抚摸着你的头，说道：\n",
	"\n新手精灵突然从你背后跳了出来，嬉皮笑脸的说道：\n",
	"\n新手精灵伸了伸懒腰，拍拍小嘴，喃喃的道：\n",
});

void create()
{
	seteuid(geteuid());
	set("channel_id","新手精灵");
}
void start_help(object ob)
{
	string msg,file;
	int time;
	
	if(!ob || !environment(ob) || !ob->query("env/newbie_wizard")) return;

	time = (int)ob->query("env/newbie_wizard");
	if(time < 2) time = 30;

	file = sprintf("/doc/newbie/%d.txt",(int)ob->query("help")+1);	
	if(file_size(file) < 1) {
		tell_object(ob,HIY"新手精灵语重声长的说道：嗯，我就教你这么多了，江湖的日子就靠你自己了！再见！\n"NOR);
		tell_object(ob,HIY"新手精灵说完，恋恋不舍的缓缓向天界飞去了，不时深情的看了看你，挥了挥手；\n刹那间，你发现她的脸上挂着星点晶莹的泪花 . . .\n"NOR);
		ob->delete("env/newbie_wizard");
		return;
	}

	msg = HIY + wizard_msg[random(sizeof(wizard_msg))] +NOR;
	msg +=WHT"────────────────────────────────\n"NOR;
	msg += read_file(file);
	msg +=WHT"────────────────────────────────\n"NOR;
	
	ob->add("help",1);
	tell_object(ob,msg);
	call_out("start_help",time,ob);

}
