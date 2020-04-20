 // bai_player.c
// Zen 1999-01-06

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);
void give_title(object me);
void set_faction_title(object me);
int main(object me, string arg)
{
        object ob, old_app;

        if( me->query_temp("sleeping") ) return notify_fail("你现在正躺着呢。\n");

        if( environment(me)->query("restrict_action") ) 
                return notify_fail("这里不能做这件事情。\n");

        if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

        if( !arg ) return help(me);

        if( arg == "cancel" ) {
                old_app = me->query_temp("pending/bai");
                if( !objectp(old_app) ) return notify_fail("你现在并没有拜任何人为师的意思。\n");
                write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                me->delete_temp("pending/bai");
                return 1;
        }

        if( !(ob = present(arg, environment(me))) || !ob->is_character() )
                return notify_fail("你想拜谁为师？\n");

        if( !living(ob) ) return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

        if( ob == me ) {
                notify_fail("拜自己为师？好主意....不过没有用。\n");
                if( !me->query("faction/head")) return 0;
                give_title(me);
                tell_object(me,"您恢复了自己的头衔。\n");
                return 1;
                }
        if( me->is_player_apprentice_of(ob) ) {
                message_vision("$N恭恭敬敬地向$n磕头请安，叫道：“师父！”\n", me, ob);
                if( me->query("faction/generation")) 
                        set_faction_title(me);//zen:普通弟子才重设title
                give_title(me);// 重新设定玩家的RANK
                return 1;
        }
        if( me->query("faction/head")) return notify_fail("你是一派之主，不能改拜别人。\n");
        if( !ob->query("faction"))
                return notify_fail(ob->name() + "既不属於任何门派，也没有开山立派，不能拜师。\n");
        if(!userp(ob)
                || (!ob->query("faction/head") && !ob->query("faction/second") ))
                return notify_fail("他不是门派的负责人。\n");
        // If the target is willing to recruit us already, we do it.
        if( (object)ob->query_temp("pending/recruit") == me ) {
                if( me->query("faction")) {
                        me->delete("faction");
                        message_vision("$N决定背叛师门，改投入$n门下！！！\n\n", me, ob);
                }else message_vision( "$N决定拜$n为师。\n\n", me, ob);

                message_vision( "$N决定拜$n为师。\n\n"
                        "$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n", me, ob);


                me->set("faction/name",ob->query("faction/name"));
                ob->add("faction/times",1);   
                me->set("faction/generation",ob->query("faction/times"));
                set_faction_title(me);//zen:普通弟子才重设title
                give_title(me);// 重新设定玩家的RANK
                ob->delete_temp("pending/recruit");
                me->delete_temp("pending/apprentice");
                tell_object(ob,sprintf("恭喜您新收了一名%s。\n", me->query("faction/faction_title")));
                printf("恭喜您成为%s。\n", me->query("title"));

                return 1;
        
        } else {

                old_app = me->query_temp("pending/apprentice");
                if( ob == old_app )
                        return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
                else if( objectp(old_app) ) {
                        write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                        tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                }

                message_vision("$N想要拜$n为师。\n", me, ob);
                me->set_temp("pending/apprentice", ob );
                tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit_player 指令。\n" NOR);
        
                return 1;
        }
}

void set_faction_title(object me)
{
        string faction;
        int generation, exp;

        if( !(faction = me->query("faction/name"))) return;
        if( !(generation = me->query("faction/generation"))
                && me->query("faction/faction_title")) return;
        exp = me->query("combat_exp");

        if( exp <= 100000 ) generation = 1;
        else if( exp <= 250000 ) generation = 2;
        else if( exp <= 500000 ) generation = 3;
        else if( exp <= 1000000 ) generation = 4;
        else if( exp <= 5000000 ) generation = 5;
        else if( exp <= 80000000 ) generation = 6;
        else if( exp <= 15000000 ) generation = 7;
        else generation = 8;
        me->set("faction/generation", generation) ;

        switch(generation){
                case 1: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "弟子"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "弟子"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "职员"); return;
                        case "天空界":   me->set("faction/faction_title","豪兵"); return;
                        default:
                        }
                return;
                }
                case 2: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "坛主"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "坛主"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "秘书"); return;
                        case "天空界":   me->set("faction/faction_title","勇者"); return;
                        default:
                        }
                return;
                }
                case 3: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "堂主"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "堂主"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "副主任"); return;
                        case "天空界":   me->set("faction/faction_title","豪将"); return;
                        default:
                        }
                return;
                }
                case 4: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "护法"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "护法"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "主任"); return;
                        case "天空界":   me->set("faction/faction_title","修罗"); return;
                        default:
                        }
                return;
                }
                case 5: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "法王"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "法王"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "副经理"); return;
                        case "天空界":   me->set("faction/faction_title","战魂"); return;
                        default:
                        }
                return;
                }
                case 6: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "长老"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "长老"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "经理"); return;
                        case "天空界":   me->set("faction/faction_title","战龙"); return;
                        default:
                        }
                return;
                }
                case 7: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "掌教长老"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "掌庄长老"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "副主席"); return;
                        case "天空界":   me->set("faction/faction_title","狂龙"); return;
                        default:
                        }
                return;
                }
                case 8: {
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "副楼主"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "副庄主"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "副总裁"); return;
                        case "天空界":   me->set("faction/faction_title","武神"); return;                        default:
                        }
                return;
                }
                default :{
                switch(faction) {
                        case "孤星楼":   me->set("faction/faction_title", "弟子"); return;
                        case "《江湖人》杂志社":   me->set("faction/faction_title", "弟子"); return;
                        case "飞氏集团":   me->set("faction/faction_title", "职员"); return;
                        case "天空界":   me->set("faction/faction_title","豪兵"); return;
                        default:
                        }
                return;
                } 
        }
}
void give_title(object me)
{
        string faction,faction_title;
        faction = me->query("faction/name");
        faction_title = me->query("faction/faction_title");
        switch(faction) {
                case "孤星楼":   me->set("title",HIC""+faction+faction_title + ""NOR); return;
                case "《江湖人》杂志社":   me->set("title",HIR""+faction+faction_title + ""NOR); return;
                case "飞氏集团":   me->set("title",HIW""+faction+faction_title + ""NOR); return;
                case "天空界":   me->set("title",MAG""+faction+""WHT+faction_title + ""NOR); return;
                default:
        }
        return;
}
int help(object me)
{
        write(@HELP
指令格式：bai_player <对象>     拜某人为师
          bai_player cancel     取消拜师

这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即
行拜师之礼，否则要等到对方用recruit_player 指令收你为弟子才能正式拜师。

请注意你已经假如玩家门派，又背叛师门投入别人门下，你应该事先得到原师傅的许可。

如果对你的师父使用这个指令，会变成向师父请安。
 
请参考相关指令：expell、recruit_player。

HELP
        );

        return 1;
}

