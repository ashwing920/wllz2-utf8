// edit.c

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file )
		return notify_fail("指令格式：edit <档名>\n");
	if( in_edit(me) )
		return notify_fail("你已经在使用编辑器了。\n");
	seteuid(geteuid(this_player(1)));
	ed(resolve_path(me->query("cwd"), file));
	if(in_edit(me)){
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s正在编译文件：%s",
			me->name(2),resolve_path(me->query("cwd"), file)));
		log_file("file/EDIT_FILE", sprintf("%s edit %s (%s)\n",
			me->name(2),resolve_path(me->query("cwd"), file),
		ctime(time())));
	}
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
HELP
);
	return 1;
}
