// yue-bing.c 

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIY"月饼" NOR, ({ "yue bing", "bing" }) );
        set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_get_from",1);
        set("no_pawn",1);
        set("no_drop",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
一块香气逼人的月饼，香喷喷的月饼上还精雕细琢的写着四个大字：中秋快乐。
$HIY$
                       ----------
                ┏━┓┃中秋快乐┃┏━┓ 
                ┃逢┃┗━━━━┛┃迎┃ 
                ┃千┃　━　 ━━ ┃仲┃ 
                ┃禧┃━┳━┏━┓┃秋┃ 
                ┃举┃┃┃┃┗━┛┃普┃ 
                ┃世┃┃┃┃┏┳┓┃天┃ 
                ┃共┃　┃　┃╋┃┃同┃ 
                ┃欢┃　┛　┗┻┛┃庆┃ 
                ┗━┛　　　　　　┗━┛
$NOR$

TEXT
);
        }
        set("unit", "块");
        set("value", 0 );
        setup();
}
void init()
{
        if(environment()==this_player())
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}
int do_eat(string arg)
{
        object me;
        int increasement;
        me = this_player();

        if(!id(arg) || arg =="") return 0;
        
        message_vision("$N拿起一块"HIY"月饼"NOR"放到嘴里慢慢的品尝，不禁叫了一声“好香啊！”。\n",me);
        increasement = me->query("combat_exp") /100;
        if( increasement < 1000 )increasement = 1000;
        increasement = increasement/3+random(increasement/3*2);
        me->add("combat_exp", increasement);
        tell_object(me, "你的经验增加了" + chinese_number( increasement ) + "点！\n");
        increasement /= 50;
        me->add("potential", increasement);
        tell_object(me, "你的潜能增加了" + chinese_number( increasement ) + "点！\n");
        destruct(this_object());
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
