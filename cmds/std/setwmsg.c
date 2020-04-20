//setwmsg.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help();

int main(object me,string arg)
{
	string type,msg,*block_msg;
	int i;

	block_msg = ({"$WEAPON","【","】","巫师","天神","蝴蝶君","小鸟儿",});

	if(!arg || sscanf(arg,"%s %s",type,msg) != 2) return help();

	i = sizeof(block_msg);

	for(i=0;i<sizeof(block_msg);i++){
		if(strsrch(msg,block_msg[i]) == -1) continue;
		write("描述里出现了非法字符！\n");
		return 1;
	}
	if(!CHECK_D->check_msg(msg))
		return notify_fail("描述里出现了非法字符！\n");

	if(strsrch(msg,"$N") < 0)
		return notify_fail("描述里必须又“$N”符号来代表你自己。\n");

	if(type != "-w" && type != "-u")
		return notify_fail("没有这种形式。\n");

	if(!(me->query("weapon/make")))
		return notify_fail("你没有自制的兵器！\n");


	if(type == "-w"){
		me->set("weapon/wield_msg",convert_color(msg));
		write("Ok.\n");
		return 1;
	}
	else if( type == "-u"){
		me->set("weapon/unwield_msg",convert_color(msg));
		write("Ok.\n");
		return 1;
	}
	else
		return notify_fail("描述设置失败，请选择具体参数。详细请看帮助文件。\n");
}

int help()
{
	string  f=RED+"★"+NOR;
	write(
"指令格式 : setwmsg -w|-u <具体描述>\n"
+"\n"
+f+"这个指令可以让你为自己的武器加入装备以及卸下时的描述\n"
+"      语言。\n"
+"      -w : 将后续文字作为兵器装备时的描述语言。\n"
+"      -u : 将后续文字作为卸下兵器时的描述语言。\n"
+"\n"
+f+"你如果希望在描述中使用 ANSI 的控制字元改变颜色，\n"
+"      可以用以下的控制字串：\n"
+"\n"
+"$BLK$ - 黑色  $NOR$ - 正常色   $RED$ - 红色   $HIR$ - 亮红色\n"
+"$GRN$ - 绿色  $HIG$ - 亮绿色   $YEL$ - 土黄色  $HIY$ - 黄色\n"
+"$BLU$ - 深蓝色  $HIB$ - 蓝色   $MAG$ - 浅紫色  $HIM$ - 粉红色\n"
+"$CYN$ - 蓝绿色  $HIC$ - 天青色   $WHT$ - 浅灰色  $HIW$ - 白色\n"
+"其中系统自动会在字串尾端加一个 $NOR$。\n"
+"\n"
+f+"在描写中使用$N代替自己。\n"
+"\n"
+f+"注意如果在兵器名称后还有描写文字那么需要从新定义颜色\n"
+"      否则按默许颜色处理。\n"

	);
	return 1;
}
