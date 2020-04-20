// ban.c

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        string site;

        if (!arg) BAN_D->print_banned();
        else if (sscanf(arg, "+ %s", site) == 1) {
                if (site[sizeof(site)-1] == '*' || site[sizeof(site)-1] == '?' || site[sizeof(site)-1] == '+')
                        write("不能禁止以 *, +, ? 结尾的地址。\n");
                else {
                        BAN_D->add_banned(site);
                        write( "完成。\n" );
                }
        }
        else if (sscanf(arg, "- %s", site) == 1) {
                BAN_D->remove_banned(site);
                write( "完成。\n" );
        }
        else help(me);

        return 1;
        
}

int help(object me)
{
        write(@HELP
指令格式：ban                   显示所有强行封闭的地址
          ban +|- site          封闭／解封地址

强行封闭一些地址，用于防止有人蓄意捣乱。

关联信息：pass
HELP
        );

        return 1;
}
