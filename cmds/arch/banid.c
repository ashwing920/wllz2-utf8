// banid.c
// zen 99-07-02

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        string id;

        if (!arg) BAN_D->print_ban_id();
        else if (sscanf(arg, "+ %s", id) == 1) {
                if (id[sizeof(id)-1] == '*' || id[sizeof(id)-1] == '?' || id[sizeof(id)-1] == '+')
                        write("不能禁止以 *, +, ? 结尾的ID。\n");
                else {
                        BAN_D->add_ban_id(id);
                        write( "完成。\n" );
                }
        }
        else if (sscanf(arg, "- %s", id) == 1) {
                BAN_D->remove_ban_id(id);
                write( "完成。\n" );
        }
        else help(me);

        return 1;
        
}

int help(object me)
{
        write(@HELP
指令格式：banid                   显示所有强行封闭的ID
          banid +|- id            封闭／解封ID

强行封闭一些ID，用于防止有人蓄意捣乱。

关联信息：pass
HELP
        );

        return 1;
}
