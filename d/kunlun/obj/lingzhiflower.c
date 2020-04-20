//lingzhi.c 灵脂兰

inherit ITEM;

#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
        add_action("do_break","break");
}
void create()
{
        set_name(MAG"灵脂兰"NOR,({"lingzhi flower","lingzhi","flower"}));
        set("unit", "株");
        set("value", 60);
        set("long", "鬼魅的灵芝兰，闻起来有一股淡淡的檀香之气。\n");
        setup();
}
int do_eat(string arg)
{
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        message_vision(RED"$N看着那么美丽的"+this_object()->name()+RED+"，想也不想,一口把"+this_object()->name()+RED+"吞了!\n" NOR,this_player());
        if(random(2)==0)
                this_player()->unconcious();
        else{
                this_player()->set_temp("die_for","中灵芝兰毒而死了！");
                this_player()->die();
        }
        this_object()->move(VOID_OB);
        destruct(this_object());
        return 1;
}
int do_break(string arg)
{
        if( !arg || !id(arg) )
                return notify_fail("你想踩什么？\n");
        if (environment()==this_player())
                   return notify_fail("灵芝兰在你身上怎么踩呀。\n");
        if (query("name")=="烂掉的灵芝兰") return 0;
        set_name("烂掉的灵芝兰", ({ "lan flower","flower" }) );
        set("long", "一堆烂掉的灵芝兰。\n");
        set("value", 0);
        set("no_get",1);
        message_vision("$N一脚把灵芝兰踩烂。\n", this_player());
        environment()->she_come(this_player());
        return 1;
}

