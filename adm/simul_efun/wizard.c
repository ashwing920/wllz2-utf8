// wiz.c

string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}
//下面这些函数是find提示需要进行保护的函数！
//在MASTER_OB里的valid_override()里也进行防止efun::fun()的跨越调用！
nomask mixed *localtime( int time )
{
        if( !intp(time) || ( time < 0 ) )
                time = 0;

        return efun::localtime(time);
}

nomask string ctime(int time)
{
        if(!intp(time))
                return "";
        if( time < 0 )
                time = 0;

        return efun::ctime(time);
}

nomask varargs object snoop(object snooper,object snoopee)
{
        if(objectp(snooper) && objectp(snoopee))
        {
                if(wiz_level(snooper) < wiz_level(snoopee)
                && wizhood(snooper) != "(admin)")
                        return 0;
        }

        if(!objectp(snoopee))
                return efun::snoop(snooper);
        else
                return efun::snoop(snooper,snoopee);
}
#define UPDATE_CMD "/cmds/wiz/update.c"

nomask int exec(object to,object from)
{
        if(previous_object()
        && (previous_object() == find_object(LOGIN_D)
        || previous_object() == find_object(UPDATE_CMD)))
                return efun::exec(to,from);
        else
                error("Permission Denied.\n");
}