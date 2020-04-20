// more.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) 
		return notify_fail("指令格式 : more <档名>|<物件名> \n");

	file = resolve_path(me->query("cwd"), arg);

	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}

	CHANNEL_D->do_channel(find_object(SEC_OB),"sys",
			sprintf("%s查阅：%s",me->name(2),file));

	me->start_more(read_file(file));

	log_file("file/MORE_FILE", sprintf("[%s] %s more %s \n",
		ctime(time())[0..15], geteuid(me), file ) );

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档名>|<物件名>
HELP
    );
    return 1;
}

