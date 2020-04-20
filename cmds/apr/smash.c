// smash.c 2-22-95

#include <ansi.h> 
#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() 
{
        seteuid(getuid());
        set("channel_id", "毁灭精灵[Smash]");
}

int main(object me, string arg)
{
        object ob;
        string name1, name2;
        if(!arg) return notify_fail("指令格式：smash <living>\n");
        ob = present(arg, environment(me));
        if(!ob) return notify_fail("找不到这个生物。\n");
        if(userp(ob) && !wizardp(ob))
                return notify_fail(HIG"蝴蝶君突然出现你的眼前，说道：刀下留人！你不能摧毁玩家！！！\n"NOR);
        if( !ob->is_character() || ob->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        name1 = (string)me->query("name");
        name2 = (string)ob->query("name");
        tell_room(environment(me),name1+"高举双手大喝：去死吧！只见天上一道闪电不偏不倚地击中"+name2+"，将之化为一堆灰烬。\n"+NOR, ({me, ob}));
        tell_object(ob,name1+"高举双手大喝：去死吧！只见天上一道闪电不偏不倚地击中了你。\n"+NOR);
        write("你高举双手大喝：去死吧！从天上降下一道闪电将"+name2+"化作一堆灰烬。\n");
        write("天空中又传来了一阵阴笑声。\n"+NOR);
        CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s[%s]将%s[%s]毁灭了。",me->name(),me->query("id"),ob->name(),ob->query("id")));
        log_file("static/smash.log",sprintf("%s(%s) smash %s(%s) at %s。\n", me->name(), me->query("id"), ob->name(),ob->query("id"),ctime(time())));
        ob->die();
        return 1;
}
 
int help(object me)
{
	write(@HELP

指令格式: smash <生物>
 
HELP);
	return 1;
}

