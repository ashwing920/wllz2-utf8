// rm.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));

	if(!file)
		return notify_fail("你要删除那个档案？\n");

	if( rm(resolve_path(me->query("cwd"), file)) )
	{
		log_file("file/RM_FILE", sprintf("[%s]%s rm %s。\n",
			ctime(time()),me->name(2),resolve_path(me->query("cwd"), file)));
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s删除了文件：%s",
			me->name(2),resolve_path(me->query("cwd"), file)));
		write("Ok.\n");
	}
	else {
		write("你没有删除这个档案的权利。\n");
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你(你)删除有权修改的档案。
HELP
	);
	return 1;
}

