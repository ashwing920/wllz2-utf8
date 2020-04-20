// kickout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,link_ob;
	int DisableMsg;
	string reason;

	DisableMsg = 0;

	if( !arg ) 
		return notify_fail("指令格式 : kickout <id> because <why>。\n" );

	if( sscanf(arg, "-h %s", arg) ) DisableMsg = 1;

	if( sscanf(arg, "%s because %s", arg, reason) < 1 )
		return notify_fail("指令格式 : kickout <id> because <why>。\n" );

	seteuid(ROOT_UID);

	obj = find_player(arg);

	if(!objectp(obj)) obj = present(arg, environment(me));
	if(!obj || !userp(obj)) return notify_fail("没有这个玩家....。\n");

	if( me == obj )
		return notify_fail("用quit这条指令好些:) 。\n");

	if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
		if( wiz_level(me) != wiz_level("(admin)") )
			return notify_fail("你想造反？？？\n");

	if(objectp(link_ob = obj->query_temp("link_ob"))){
		link_ob->set("kickout_time",time());
		link_ob->save();
		catch(destruct(link_ob));
	}

	if( !DisableMsg) 
		message_system(sprintf("由于触犯游戏规则，%s被系统请出了"+ code_name() +"。",obj->name(2)));
	
	CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s被%s踢出了%s。",
			obj->name(2),me->name(2),code_name()));
	log_file("static/kickout",
		sprintf("%s将%s踢出游戏，因为：%s\n", me->name(2),obj->name(2), reason));
	
	write("哼。。。终于出了这口恶气！\n");
	obj->save();
	tell_object(obj,HIR"\n\t由于你触犯了游戏规则，系统将你列入不欢迎人物名单！再见！！\n"NOR);
	catch(destruct(obj));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kickout -h <id> because <reason>

此命令可以强迫恶意的玩家离线，请先再三考虑，慎用此命令。
如果加上 -h 则不显示 rumor channel 的信息。

HELP );
	return 1;
}
