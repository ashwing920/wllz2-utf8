// transite.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG"粉红丝绢"NOR, ({ "si juan", "juan","si"}) );
        set_weight(100);
        set("long", @LONG
这是一条什么图案都没有的粉红丝绢。绣(xiu)上一些图案，一定非常好看。
LONG
);
        set("unit", "条");
        set("value",0);
        set("material","cloth");
        set("no_get",1);
        set("no_get_from",1);
        set("no_steal",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_beg",1);
}
void init()
{
        if(environment()==this_player())
        add_action("do_xiu", "xiu");
}
int do_xiu(string arg)
{
        object me;
        me = this_player();
        
        if(!id(arg))    
                return notify_fail("你要绣什么？\n");
        
        if(me->is_busy())
                return notify_fail("你正忙着呢！\n");
        
        if(me->is_fighting())
                return notify_fail("你正在战斗中！\n");
        
        if(me->query("gender") != "女性")
                return notify_fail("这是女人家的手艺，你抢什么呀？\n");
                
        if(!me->query_temp("xiu_job"))
                return notify_fail("人家没请你刺绣，你就省点力气吧！\n");
        
        if(me->query_temp("working"))
                return notify_fail("你正在做刺绣呢，不能分心。\n");

        if( me->query("jing") < 20 || me->query("qi") < 20)
                return notify_fail("你太累了，再刺下去恐怕会累死。\n");
        if( me->query_temp("xiu_job_finish"))
                return notify_fail("终于把丝绢绣好了，快去交(give)个曾柔吧！\n");

        if( me->query_temp("xiu_finish") > (me->query("per") / 3  + random(10))){
                tell_object(me,"一条绣着戏水鸳鸯的丝绢终于做了，你满意的看了看，决定将它交给曾柔。\n");
                me->set_temp("xiu_job_finish",1);
                return 1;
        }
        
        tell_object(me,"你心灵手巧，拿起针线往丝绢上小心翼翼的刺去。\n");
        call_out("finish_xiu",1,me);
        me->set_temp("working",1);
        me->start_busy(1);
        return 1;
}
private void finish_xiu(object me)
{
        if(!me->query_temp("working") || !me->query_temp("xiu_job")
        || !me) return;

        me->delete_temp("working");
        
        switch(random(5)){
                case 1:
                        tell_object(me,"绣花针慢慢的穿过丝绢，你显得得心应手。\n");
                        me->add_temp("xiu_finish",1);
                        break;
                case 2:
                        tell_object(me,RED"你突然一分神，绣花针刺到了指尖，你忍不住尖叫了声：哎呀，好疼哟！\n"NOR);
                        me->add("jing",-10);
                        me->add("qi",-10);
                        me->add_temp("xiu_finish",1);
                        break;
                case 3:
                        tell_object(me,"你小心翼翼的把丝绢翻了翻，依据纹路将绣花针刺了进去。\n");
                        me->add_temp("xiu_finish",1);
                        break;
                default:
                        tell_object(me,"真是心灵手巧，你照着丝绢上的图案，有条有理的做着刺绣。\n");
                        me->add_temp("xiu_finish",1);
                        break;
        }
        return;
}
void owner_is_killed() { destruct(this_object()); }
