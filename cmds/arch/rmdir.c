// rmdir.c


inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string dir;

        if(!arg) return help(me);

        dir = resolve_path(me->query("cwd"), arg);

        seteuid(geteuid(me));
        if( rmdir(dir) ) write("子目录删除成功。\n");
        else write("你没有权力删除这个子目录。\n");

        return 1;       
}

int help(object me)

{
        write(@HELP
指令格式 : rmdir <子目录名>

删除子目录。

HELP
        );

        return 1;
}
