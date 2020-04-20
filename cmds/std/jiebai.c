// jiebai.c

#include <ansi.h>
#include <localtime.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, old_target;

        if(me->query("age") < 15)
                return notify_fail("小孩子一边玩儿去。\n");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("你想和谁结拜？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");

        if( !userp(obj) )
                return notify_fail("你只能和玩家拜把子。\n");

        if( !living(obj) )
                return notify_fail("嗯...你还是先把"+obj->name()+"弄醒吧。\n");

        if (me->query("jiebai") && strsrch(me->query("jiebai"), obj->query("name")+"、") >= 0)
                return notify_fail("你已经和人家结拜过了。\n");

        if (me->query("jiebai") && strsrch(me->query("jiebai_id"), obj->query("id")+"、") >= 0)
                return notify_fail("你已经和人家结拜过了。\n");

        if( me->query("marry") == obj->query("id")
        || obj->query("marry") == me->query("id"))
                return notify_fail("做了夫妻还结拜，真是亲上加亲，好主意！不过不行。:(\n");

        if(obj==me)
                return notify_fail("你不能和自己结拜。\n");

        if( userp(obj) && (object)obj->query_temp("pending/jiebai")!=me ) {
                message_vision("\n$N对著$n说道：" + RANK_D->query_self(me) + me->name() + "，对"
                + RANK_D->query_respect(obj) + "心仪已久，愿彼此生死与共，肝胆相照！\n\n", me, obj);
                if( objectp(old_target = me->query_temp("pending/jiebai")) )
                        tell_object(old_target, RED + me->name() + "取消了和你结拜的念头。\n" NOR);
                me->set_temp("pending/jiebai", obj);

                tell_object(obj, YEL "如果你愿意和对方结为异性骨肉，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 jiebai 指令。\n" NOR);
                write(RED "对方必须同意才能结拜。你等着吧。\n" NOR);
                return 1;
        }

        message_vision("\n$N对着$n高声说道：不求同年同月同日生，但愿同年同月同日死！\n\n", me, obj);
        if( me->query("gender") == "男性" && obj->query("gender") == "男性"){
                message("channel:chat",HIG"【武林列传】"+ me->query("name") +"和"+ obj->query("name")+"于" + NATURE_D->game_time() + "结拜，成为异姓兄弟！\n"NOR,users());
        }
        else if( me->query("gender") == "女性" && obj->query("gender") == "女性"){
                message("channel:chat",HIG"【武林列传】"+ me->query("name") +"和"+ obj->query("name")+"于" + NATURE_D->game_time() + "结拜，成为异姓姐妹！\n"NOR,users());
        }
        else if( me->query("gender") == "男性" && obj->query("gender") == "女性"
        || me->query("gender") == "女性" && obj->query("gender") == "男性"){
                message("channel:chat",HIG"【武林列传】"+ me->query("name") +"和"+ obj->query("name")+"于" + NATURE_D->game_time() + "结义金兰，成为生死之交！\n"NOR,users());
        }
        else
        me->delete_temp("pending/jiebai");
        if(!me->query("jiebai"))
                me->set("jiebai", obj->query("name")+"、");
        else
                me->set("jiebai", me->query("jiebai") + obj->query("name")+"、");
                me->add("jiebai_id",obj->query("id")+"、");

        if(!obj->query("jiebai"))
                obj->set("jiebai", me->query("name")+"、");
        else
                obj->set("jiebai", obj->query("jiebai") + me->query("name")+"、");
                obj->add("jiebai_id",me->query("id")+"、");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : jiebai <某人>

这个指令用来和别人的结拜，当然对方必须也同意。

HELP
    );
    return 1;
}
