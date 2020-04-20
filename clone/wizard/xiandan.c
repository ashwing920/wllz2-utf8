// fengyun-stone.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"仙丹"NOR, ({"xian dan","dan" }) );
        set_weight(100);
        set("long",@LONG
流传于仙界的仙丹，吃下去一定有何神奇功效。
LONG
);
        set_weight(100);
        set("no_pawn",1);
        set("is_monitored",1);
        remove_call_out("deststone");
        call_out("deststone",180,this_object());
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value",0);
                set("material","food");
        };
        setup();
}

void init()
{
        if(environment()==this_player())
        add_action("do_eat","eat");
}
int do_eat(string arg)
{
        object ob,me;
        ob = this_object();
        me = this_player();
        
        if(!id(arg))
                return notify_fail("你要吃什么？\n");
        
        message_vision("$N拿起一颗$n二话不说就往嘴里塞了进去。\n",me,ob);

        switch(random(10)){
                case 1:
                        if(me->query("kar") < 30) {
                                me->add("kar",1);
                                tell_object(me,HIY"恭喜，你的运气增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 2:
                        if(me->query("str") < 40) {
                                me->add("str",1);
                                tell_object(me,HIY"恭喜，你的臂力增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 3:
                        if(me->query("per") < 40){
                                me->add("per",1);
                                tell_object(me,HIY"恭喜，你的魅力增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 4:
                        if( me->query("con") < 30) {
                                me->add("con",1);
                                tell_object(me,HIY"恭喜，你的根骨增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 5: 
                        if(me->query("int") < 30) {
                                me->add("int",1);
                                tell_object(me,HIY"恭喜，你的悟性增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 6: 
                        if(me->query("spi") < 30) {
                                me->add("spi",1);
                                tell_object(me,HIY"恭喜，你的灵性增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;

                case 7: 
                        if(me->query("cor") < 30) {
                                me->add("cor",1);
                                tell_object(me,HIY"恭喜，你的定力增加了一点。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 8:
                        if(me->query("dex") < 100) {
                                me->add("dex",1);
                                tell_object(me,HIY"恭喜，你的身法增加了一点。\n"NOR);
                        }
                        else {
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 9:                        
                        if(me->query("age") > 40){
                                me->add("mud_age",-86400);
                                me->add("age",-1);
                                tell_object(me,HIY"突然间，你觉得自己显得年轻了许多。\n"NOR);
                        }
                        else {
                                tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                                me->set("food",me->max_food_capacity());
                                me->set("water",me->max_water_capacity());
                        }
                        break;
                case 10:
                        me->add("weiwang",1000);
                        tell_object(me,HIY"由于你表现良好，你的威望增加了一千点。\n"NOR);
                        break;
                case 11:
                        me->add("food",me->max_food_capacity());
                        me->add("water",me->max_water_capacity());
                        me->set("eff_qi",me->query("max_qi"));
                        me->set("eff_jing",me->query("max_jing"));
                        me->set("qi",me->query("max_qi"));
                        me->set("jing",me->query("max_jing"));
                        me->set("neili",me->query("max_neili"));
                        tell_object(me,HIG"你突然觉得精神抖擞，气血旺盛。\n"NOR);
                        break;
                case 12:
                        me->set("bellicosity",0);
                        tell_object(me,HIM"你突然觉得心情平和，原来是你的杀气已经消失了。\n"NOR);
                        break;
                case 13:
                        me->set("PKS",0);
                        tell_object(me,HIC"恭喜，你的杀戮太多，上天将你的戾气化解了。\n"NOR);
                        break;
                case 14:
                        me->set("VKS",0);
                        tell_object(me,HIW"恭喜，上天给了你一次重生的机会，你的被杀次数消失了。\n"NOR);
                        break;
                default:
                        tell_object(me,"你觉得肚子饱饱的，不用再吃东西了。\n");
                        me->set("food",me->max_food_capacity());
                        me->set("water",me->max_water_capacity());
                        break;
        }
        destruct(this_object());
}
void deststone()
{
        destruct(this_object());
}
void owner_is_killed() { destruct(this_object()); }

