// setfrd.c

inherit F_CLEAN_UP;

#include <login.h>
#include <ansi.h>

int help(object me);

int main(object me, string arg)
{
	object ob;
	string *frd_list,id;
	frd_list = me->query("my_friends");

	seteuid(ROOT_UID);

	if( !arg || arg=="" ) {
		if( !pointerp(frd_list) || !sizeof(frd_list) )
			write("你目前并没有设置任何好朋友。\n");
		else {
			write("你现在的好朋友设置如下：\n" + implode(frd_list, ", ") + "。\n");
		}
		return 1;
	}
	if( arg && arg!="") {
		if(sscanf(arg,"+ %s",id) == 1){
				if( id == me->query("id"))
					return notify_fail("什么？你连自己都不认识了吗？\n");
				if( frd_list && member_array(id,frd_list) != -1 )
					return notify_fail("你的好友名单中已经有"+ id +"这个玩家了。\n");

				ob = new(LOGIN_OB);
				ob->set("id",id);

				if( !ob->restore())
					return notify_fail("没有这个玩家："+ id +" \n");

				if( !pointerp(frd_list) )
					me->set("my_friends", ({ ob->query("id") }) );
				else if( member_array(id,frd_list) == -1 )
					me->set("my_friends",frd_list + ({ ob->query("id") }) );
					tell_object(me,"你将"+ ob->query("name") + "加入你的好友名单。\n");

				destruct(ob);
				return 1;
		}
		else if(sscanf(arg,"- %s",id) == 1){

				if( !pointerp(frd_list) )
					return notify_fail("你目前并没有设置任何好朋友。\n");
				if( member_array(id,frd_list) == -1 )
					return notify_fail("你的好朋友列表中并没有"+ id +"这个名字。\n");

				ob = new(LOGIN_OB);
				ob->set("id",id);

				if( !ob->restore() )
					return notify_fail("没有这个玩家："+ id +" \n");

				me->set("my_friends",frd_list - ({ ob->query("id") }) );
				tell_object(me,"你将"+ ob->query("name") + "从好友名单中删除了。\n");

				destruct(ob);
				return 1;
		}
	}
	return help(me);
}
int help(object me)
{
	write(@HELP

这个指令是提供给你设置游戏中好朋友的名单以方便联系。

指令格式：frd + id      将游戏中的玩家名字加入到你的好友名单。
	　frd - id      将该玩家id从你的好友名单中移除。

HELP
);
	return 1;
}

