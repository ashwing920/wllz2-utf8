// banname.c
// Design By Robert 蝴蝶君 email:robert_st@sina.com

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        string name;

        if (!arg) BAN_D->print_ban_name();
        else if (sscanf(arg, "+ %s", name) == 1) {
                if (name[sizeof(name)-1] == '*' || name[sizeof(name)-1] == '?' || name[sizeof(name)-1] == '+')
                        write("不能禁止以 *, +, ? 结尾的ID。\n");
                else {
                        BAN_D->add_ban_name(name);
                        write( "完成。\n" );
                }
        }
        else if (sscanf(arg, "- %s", name) == 1) {
                BAN_D->remove_ban_name(name);
                write( "完成。\n" );
        }
        else help(me);

        return 1;
        
}

int help(object me)
{
        write(@HELP
指令格式：banname                   显示所有强行封闭的中文名字
          banname +|- name          封闭／解封中文名字

强行封闭一些中文名字，用于防止有人蓄意捣乱。


HELP
        );

        return 1;
}
