// animal.c 独门坐骑

#include <ansi.h>

inherit ITEM;

void set_up();

void create()
{
        set_name("我的坐骑", ({ "my horse","horse" }) );
        set("long", "一匹独门坐骑。\n");
        set("no_get",1);
        set("no_put",1);
        set("no_drop",1);
        set("horse_prop/max_life", 1);
        set("horse_prop/life", 1);
        set_max_encumbrance(10000);
        set("prep","on");
        set_weight(0);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹独门坐骑。\n");
                set("value", 0);
        };
                set_up();
}
void set_up()
{
        object me;
        int n;

        me = this_player();

        if( stringp(me->query("make_horse/name")) )
                set("name", me->query("make_horse/name"));
        if( stringp(me->query("animal/unit")) )
                set("unit", me->query("animal/unit"));
        if( n = me->query("make_horse/max_life")) {        // 重新设置最大生命值及当前生命值，要小心。
                set("horse_prop/max_life", n);
                set("horse_prop/life",6);
                set_max_encumbrance(10000 * n);
        }
        set( "long", "「" + this_object()->name() + "」。\n" );
}
int is_container() { return 1; }
int player_animal() { return 1;}
void owner_is_killed()
{
        delete("equipped");
        destruct(this_object());
}
