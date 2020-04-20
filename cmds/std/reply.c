// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);
private void create() {seteuid(getuid());}
int main(object me, string arg)
{
        string target, mud;
        object obj;

        if(me->ban_say()) return 0;
        if(!arg || arg=="")
                return notify_fail("你要回答什么？\n");

        if(!stringp(target = me->query_temp("reply")))
                return notify_fail("刚才没有人和你说过话。\n");

        if(!wizardp(me) && me->query_condition("no_speak"))
                return notify_fail("你支支吾吾的，半天也说不出句话来。\n");

        if(sscanf(target, "%s@%s", target, mud)==2) {
                GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
                write("网路讯息已送出，可能要稍候才能得到回应。\n");
                return 1;
        }

        obj = find_player(target);

        if(!obj)
                return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");

        if(!living(obj))
                return notify_fail(obj->name()+"现在无法听到你的话！\n");

        write(WHT"『私语』"+HIY "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
        tell_object(obj, sprintf(WHT"『私语』"+HIY"%s回答你：%s\n"NOR, me->name(1), arg));

        obj->set_temp("reply", me->query("id"));
        if(obj->query_temp("netdead")) tell_object(me,HIW"对方现在是断线状态，可能不会回答你哦！\n" NOR);
        else if(interactive(obj) && query_idle(obj)>120) tell_object(me, sprintf(HIW + "对方现在已发呆了" + HIY + " %d " + HIW  + "分钟，可能不会回答你哦！\n" + NOR, query_idle(obj)/60));
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
        );
        return 1;
}
