// drift_sense.c - 冥识神通

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
        int lvl = (int)me->query_skill("essencemagic",1);

        if( me->is_fighting() )
                return notify_fail("战斗中无法使用冥识神通！\n");

        if(lvl < 150)
                return notify_fail("你的八识神通不够娴熟，还不能使用冥识神通。\n");

        if( me->query("jingli") < 100 )
                return notify_fail("你的精力不够！\n");

        if( me->query("jing") <= 100 )
                return notify_fail("你的精气不够！\n");

        if( me->is_ghost())
                return notify_fail("鬼魂无法使用冥识神通！\n");

        if( target )
                return notify_fail("冥识神通使用错误！\n");

        write("你要对谁使用冥识神通？\n");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write("中止施法。\n");
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob
        ||!environment(ob)
        ||!interactive(ob)
        ||!me->visible(ob)
        || wizardp(ob)
        ||!living(ob)) {
                write("你无法感受到这个人的灵力 ....\n");
                write("你要对谁使用冥识神通？\n");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("战斗中无法使用冥识神通！\n");
                return;
        } else if( me->query("jingli") < 75 ) {
                write("你的精力不够！\n");
                return;
        }

        if( ob == me->query("id")){
                write("你迷路了吗？\n");
                return;
        }
        me->add("jingli", -75);
        me->receive_damage("jing", 30);

        message_vision( HIY "$N闭目凝神，开始施展冥识神通 ....\n\n" NOR, me);

        if(!ob) {
                tell_object(me,"你闭目凝神，冥冥中看到一个黑乎乎的身影。\n");
        }
        else
        {
                tell_object(me,HIW"你闭目凝神，冥冥中看到"+ob->name()+"在：\n\n"NOR);
                "/cmds/std/look"->look_room(this_player(), environment(ob));
                message("vision", "\n\n一阵不详的预感油然而生，你总觉得黑暗中有一双眼睛正盯着你！\n\n", ob);
                message("vision", "你仔细地看了一下四周，却什么也没有！\n", ob);
        }

}
