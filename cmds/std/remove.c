// remove.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_remove(object me, object ob);

int main(object me, string arg)
{
        object ob, *inv;
        int i;

        if( !arg )
                return notify_fail("你要脱掉什么？\n");
        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        do_remove(me, inv[i]);
                write("Ok.\n");
                return 1;
        }

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
        string str;

        if( (string)ob->query("equipped")!="worn" )
                return notify_fail("你并没有装备这样东西。\n");

        if( ob->unequip() ) {
                if( !stringp(str = ob->query("remove_msg")) )
                        switch(ob->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = "$N将$n脱了下来。\n";
                                        break;
                                case "bandage":
                                        str = "$N将$n从伤口处拆了下来。\n";
                                        break;
				case "shield":
					str = "$N将$n从肩上解了下来。\n";
					break;
                                default:
                                        str = "$N卸除$n的装备。\n";
                        }
                message_vision(str, me, ob);
                return 1;
        } else
                return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : remove all | <物品名称>

这个指令让你脱掉身上某件防具.

HELP
        );
        return 1;
}

