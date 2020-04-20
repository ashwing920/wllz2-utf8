// exam.c (Ronger  11-98)

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	mapping my;
	string type;
	
	seteuid(getuid(me));
	
	if(!arg || sscanf(arg,"%s",type)!=1)
		return help(me);

	if( type != "armor" && type != "防具" && type != "weapon" && type != "武器" && type != "兵器")
		return notify_fail("你要查询什么类型？\n");

	if( type == "armor" || type == "防具"){
		if(!me->query("armor"))
			return notify_fail("你目前还没有自造防具。\n");
		else
		my = me->query("armor");
		write("──────────────────────────────────────\n");
		write(sprintf("防具名称：%-12s\n",my["name"]));
		write(sprintf("目前级别：%d/%d\n" ,my["lv"], my["value"]));
		write(sprintf("防 护 力：%d\n",my["lv"] * 10));
		write(sprintf("损 害 度：%d/%d\n",my["bad"],my["lv"] * 10));
		write(sprintf("抗 寒 度：%d\n",my["armor_cool"]));
		write(sprintf("防毒侵害：%d\n",my["armor_poison"]));
		write("──────────────────────────────────────\n");
	}
	if( type == "weapon" || type == "武器" || type == "兵器"){
		if(!me->query("weapon"))
			return notify_fail("你还没有自制的武器。\n");
		else
		my = me->query("weapon");
		write("──────────────────────────────────────\n");
		write(sprintf("武器名称：%-12s\n",my["name"]));
		write(sprintf("打造时间：%s\n" ,my["time"]));
		write(sprintf("材    料：%-12s\n",my["or"]));
		write(sprintf("类    型：%s\n",my["type"]));
		write(sprintf("目前级别：%d/%d\n",my["lv"],my["value"]));
		write(sprintf("坚 硬 度：%d\n",my["rigidity"]));
		write(sprintf("伤 害 力：%d\n",my["lv"] * 10));
		write("──────────────────────────────────────\n");
	}
	return 1;
}
 
int help(object me)
{
	write(@HELP

指令格式：meinfo <armor>| meinfo <weapon> 
	  meinfo <防具> | meinfo <武器> 
 
这个指令可以显示你自制的武器或自造防具的详细资料。

HELP
    );
    return 1;
}
