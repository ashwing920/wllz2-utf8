// tangmen.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "兵器库");
        set("long", @LONG
这里是唐门的兵器库，里面整整齐齐堆放着各种各样的暗器及刀剑，
唐门弟子可以在这儿取用。库里还有火炉和铁锤，可以自己升火打造(da)
钢镖。旁边还挂着一个牌子(sign)，好象写着什么。
LONG
);
        set("exits", ([
                "north" : __DIR__"changlang4",
                "west" : __DIR__"xingtang",
                "east" : __DIR__"xiaoxiao-lou",
        ]));
        set("item_desc",([
                "sign": @TEXT

打造(dazao biao)钢镖之前必须先行生火(sheng huo)。
打造飞镖与基本暗器[throwing]的等级有关，等级越高，打造出来的飞镖
杀伤力将是越大。

TEXT    ]));
        set("objects", ([
                "/d/tangmen/obj/gangbiao1": 15,
                
        ]));
        setup();
}
void init()
{
        add_action("do_da","dazao");
        add_action("do_sheng","sheng");
}
int do_da(string arg)
{
        object me;
        me = this_player();
        
        if(!arg || arg != "biao" )
                return notify_fail("你要打造什么？\n");

        if (me->query_temp("marks/镖")){
                if (me->query("jing")<10)
                        return notify_fail("你已经太累了，休息一会儿再打吧。\n");
                if( me->query("neili") <= me->query("str"))
                        return notify_fail("你的内力不够了。\n");
                if( me->query_temp("dazao"))
                        return notify_fail("你已经在打造钢镖了。\n");

                me->set_temp("dazao",1);
                me->receive_damage("jing", 5);
                me->add("neili",- me->query("str"));
                message_vision("$N挥起大铁锤，开始打造钢镖。\n", me);
                call_out("finish_dazao",3,me);
                me->start_busy(3);
                return 1;
        }
        write("火已经熄灭了，你还是把火生起来再说吧。\n");
        return 1;
}
void finish_dazao(object me)
{
        int skill;
        object ob;

        skill = me->query_skill("throwing",1);          
        if(!me) return;
        me->delete_temp("dazao");
        message_vision("随着“叮当叮当”的敲打声，$N手中的数枚钢镖已经打造好了。\n",me);
        ob=new("/d/tangmen/obj/gangbiao1");
        if(skill && me->query("family/family_name") == "唐门"){
                ob->set("weapon_prop/damage",skill);
        }
        ob->move(this_player());
        return;
}
int do_sheng(string arg)
{
        object me;

        me = this_player();

        if ( !arg || arg != "huo" )
                return notify_fail("你要干什么？\n");

        if (me->query_temp("marks/镖")){
                write("火已经生着了。\n");return 1;
        }
        message_vision("$N往炉中添了些木炭，拿起风箱开始升火。\n", me);
        message_vision(HIR"炉火熊熊燃了起来。\n"NOR,me);
        this_player()->set_temp("marks/镖",1);
        remove_call_out("fire");
        call_out("fire", 20, this_object());
        return 1;
}
void fire(object room)
{
        if(interactive(this_player()))
        message("vision",HIY"只见炉火扑闪了几下，熄了。\n"NOR, room);
        this_player()->delete_temp("marks/镖");
}
