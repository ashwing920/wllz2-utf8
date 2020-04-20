int help(object);

int main(object me,string arg) {
        string file,fileName;
        int line;

        if( !arg || arg == "" )
                return help(me);

        if( sscanf(arg,"%s %d", fileName, line ) != 2 ) {
                fileName = arg;
                line = 20;
        }
        if (file=="here") file=base_name(environment(me))+".c";
	else
        file = resolve_path(me->query("cwd"), fileName);

        if( file_size(file) < 0 )
                return notify_fail("没有这个档案。\n");
        if( !read_file(file) )
	{
        	me->set("cwf", file);
        	return tail(file);
        }
        	me->set("cwf", file);
        	write(implode(explode(read_file(file), "\n")[<line..],"\n"));
        	write( "\n" );
        	return 1;
}

int help(object me) {
        write("指令格式：tail <文件名> | <行数>。\n");
        return 1;
}

