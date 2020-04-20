// mv.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string src, dst;

	seteuid(geteuid(me));

	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 )
		return notify_fail("指令格式: mv <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if(file_size(src) <= 0)
		return notify_fail("操作错误：没有("+ src +")这个文件。\n");

	CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s[%s]将[%s]移动到[%s]",me->query("name"),geteuid(me),src,dst));
	log_file("file/MV_FILE",sprintf("%s[%s] move [%s] to [%s]\n",me->name(),me->query("id"),src,dst));

	if( !rename(src, dst) )
		write("Ok.\n");
	else
		write("你没有足够的读写权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : mv <原档名> <目标档名>

此指令可让你(你)修改某个档案或目录名称。
HELP
	);
	return 1;
}

