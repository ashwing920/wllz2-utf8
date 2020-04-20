//recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_rec;
        mapping family;

        if (!arg) return notify_fail("指令格式：recruit|shou [cancel]|<对象>\n");
        if (arg=="cancel"){
        old_rec = me->query_temp("pending/recruit");
        if( !objectp(old_rec) )
                return notify_fail("你现在并没有收录任何人为弟子的意思。\n");
                write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
                tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
                me->delete_temp("pending/recruit");
                return 1;
        }
        if (!(ob=present(arg,environment(me)))) return notify_fail("你想收谁作弟子？\n");
        if (ob==me) return notify_fail("收自己为弟子？好主意....不过没有用。\n");

        if (ob->is_apprentice_of(me)){
                message_vision("$N拍拍$n的头，说道：「好徒儿！」\n", me, ob);
                ob->set("class",me->query("class"));
                return 1;
        }

        if( userp(me) ) return notify_fail("玩家不能收徒！\n");
        if( !me->query("family") )
                return notify_fail("你并不属於任何门派，你必须先加入一个门派，或自己创一个才能收徒。\n");

        // If the target is willing to apprentice us already, we do it.
        if ((object)ob->query_temp("pending/apprentice") == me){
                if(!living(ob)){
                message_vision(
                        "$N决定收$n为弟子。\n\n"
                        "不过看样子$n显然没有办法行拜师之礼。\n\n",me, ob);
                return 1;
        }
        if((ob->query("family")) && ( (string)me->query("family/family_name") !=
                (string)ob->query("family/family_name") ) ) {

        if(ob->query("betrayer") || ob->query("family") && ob->query("combat_exp") > 10000){
                        CHANNEL_D->do_channel(me,"rumor",sprintf("听说%s[%s]背叛了%s！%s向%s发下了追杀令！",
                        ob->name(),ob->query("id"),ob->query("family/family_name"),ob->query("family/family_name"),ob->name()));
                        ob->set("old_family",ob->query("family"));
                        ob->apply_condition("oldfamily_killer",300);
                        ob->set("betrayer_family/"+ ob->query("family/family_name"),1);
                        message_vision(
                        "$N决定屈尊投入$n门下！！\n\n"
                        "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",ob, me);
                        ob->set("score", 0);
                        ob->add("betrayer", 1);
                } else

                message_vision(
                "$N决定收$n为弟子。\n\n"
                "$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」\n",me,ob);
        }
                if((string)me->query("family/family_name") != (string)ob->query("family/family_name")){
                        CHANNEL_D->do_channel(me,"party",sprintf("哈哈！！今日我"+ me->query("family/family_name")+"又多了一位"+ RANK_D->query_respect(ob)+"啦！"));
                }
                me->recruit_apprentice(ob);
                ob->delete_temp("pending/apprentice");

                /*
                if ((ob->query("class")!="bonze") && (ob->query("class")!="eunach") &&
                (me->query("class")!="bonze") && (me->query("class")!="eunach"))
                */
                ob->set("class",me->query("class"));

                write("恭喜你新收了一名弟子！\n");
                family = ob->query("family");
                tell_object( ob, sprintf("恭喜您成为%s的第%s代弟子。\n",
                family["family_name"],chinese_number(family["generation"]) ));
                return 1;
        } else
                {
                old_rec = me->query_temp("pending/recruit");
                if( ob==old_rec )
                        return notify_fail("你想收" + ob->name() + "为弟子，但是对方还没有答应。\n");
                else if( objectp(old_rec) )
        {
                write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
                tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
        }
                me->set_temp("pending/recruit", ob );
                message_vision("\n$N想要收$n为弟子。\n", me, ob);
                tell_object(ob, YEL "如果你愿意拜" + me->name() + "为师父，用 apprentice指令。\n" NOR);
           return 1;
        }
}


int help(object me)
{
        write(@HELP
指令格式 : recruit|shou [cancel]|<对象>

这个指令能让你收某人为弟子, 如果对方也答应要拜你为师的话.

See Also:          apprentice
HELP
        );
        return 1;
}
