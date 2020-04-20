// set_title.c
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me,string arg)
{
	string str,obj;
	object ob;
	
	if(!arg || sscanf(arg,"%s %s",obj,str) != 2)
		return notify_fail("指令格式：set_title <sb> <title>\n");
	
	ob = find_player(obj);
	if( !ob ) ob = find_living(obj);
	if( !ob ) ob = present(obj, environment(me));
	if( !ob ) return notify_fail("找不到这个人。\n");
	if(wiz_level(ob) > wiz_level(me))
		return notify_fail("你没有权利设置这个人的 Title。\n");
	
	ob->set("title",convert_color(str) + NOR);
	write("你将"+ ob->name(1)+"的Title设置为："+ convert_color(str)+"。\n"NOR);
	tell_object(ob,me->name(1)+"将你的Title设置为："+ convert_color(str)+"。\n"NOR);
	return 1;
	
}
 
int help(object me)
{
	write(@HELP

指令格式：set_title <sb> <title>
 
设置、修改该人物的头衔（Title）。
 
HELP
);
}
 
