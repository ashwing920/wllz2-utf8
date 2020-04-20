// cp.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string src, dst, *dirs;

	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 )
		return notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}
	if( file_size(src) <= 0 )
		return notify_fail("操作错误：没有(" + src + ")这个文件。\n");


	if( cp(src, dst) ){
		write("Ok！\n");
		log_file("file/CPFILE", sprintf("%s[%s] copy [%s] to %s [%s]\n",
			me->query("name"),geteuid(me),src,dst,ctime(time())));
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s[%s]将[%s]复制到[%s]",
			me->query("name"),geteuid(me),src,dst));
	}
	else
	{
		write("你没有足够的读写权利。\n");
		log_file("file/CP_ERROR", sprintf("%s[%s] want to copy [%s] to %s [%s] fail\n",
			me->query("name"),geteuid(me),src,dst,ctime(time())));
	}
		 return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : cp <原档名> <目标档名>

此指令可让你(你)拷贝档案。
HELP
	);
	return 1;
}

