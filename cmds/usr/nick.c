// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string tmp;
		
	if( !arg ) 
		return notify_fail("你要替自己取什么绰号？\n");

	tmp = clean_color(arg);

	if(strlen(tmp) > 12 )
		return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");

	if(!CHECK_D->check_msg(arg))
		return notify_fail("抱歉！系统不允许你设置这样信息。\n");
	me->set("nickname", convert_color(arg) + NOR);
	if (arg == "none") me->delete("nickname");
	write("Ok.\n");
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : nick <外号>|none
 
这个指令可以让你为自己取一个响亮的名号或头衔，你如果希望在绰号中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

HELP
"$BLK$ - 黑色            $NOR$ - 恢复正常颜色\n"
"$RED$ - "RED"红色"NOR"            $HIR$ - "HIR"亮红色\n"NOR
"$GRN$ - "GRN"绿色"NOR"            $HIG$ - "HIG"亮绿色\n"NOR
"$YEL$ - "YEL"土黄色"NOR"          $HIY$ - "HIY"黄色\n"NOR
"$BLU$ - "BLU"深蓝色"NOR"          $HIB$ - "HIB"蓝色\n"NOR
"$MAG$ - "MAG"浅紫色"NOR"          $HIM$ - "HIM"粉红色\n"NOR
"$CYN$ - "CYN"蓝绿色"NOR"          $HIC$ - "HIC"天青色\n"NOR
"$WHT$ - "WHT"浅灰色"NOR"          $HIW$ - "HIW"白色\n"NOR

@HELP 


其中系统自动会在字串尾端加一个 $NOR$。

HELP
);
	return 1;
}
