
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string cmd,objname;
        object obj;
        if( !arg || arg=="" || sscanf(arg, "%s to %s",objname,cmd)!=2 )
                return notify_fail("你想让他干什么？\n");
        seteuid(getuid());
        
        obj=find_living(objname);
        obj = present(objname, environment(me));
        if(!obj)   obj=find_living(objname);
        if(!obj) return notify_fail("find_body找不着人那！\n");
	if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
	if( wiz_level(me) != wiz_level("(admin)") ) return notify_fail("你想造反？？？\n");
        obj->force_me(cmd);
        return 1;
}

int help(object me)
{
         write(@HELP
指令格式:force sb. doing sth.
HELP
        );
        return 1;
}

