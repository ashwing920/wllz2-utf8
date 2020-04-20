//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//shuling.c 树林

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这里是城郊的树林，这里的树木葱茏茂密，一进来就给人一种放松的
感觉。有些树起码有百年以上的树龄。一棵数旁边竖着一块牌子(sign)，
上面好象写了些什么。 
LONG
);
        set("item_desc", ([
                "sign" : "为了保持生态平衡，请不要乱砍乱伐！\n",
        ]));
        set("exits", ([
                "east" : __DIR__"road14",
        ]));

        set("outdoors","foshan");
        setup();
}

void init()
{
        add_action("do_kan", "kan",);
}

int do_kan(string arg)
{
        object me;
        me = this_player();
        if(me->is_fighting())return notify_fail("一心不能二用！！\n");
        if(me->is_busy()) return notify_fail("你正忙着呢！！\n");
        if(me->query_temp("finish_famu"))return notify_fail("你的任务已经完成了，回去交差吧！\n");      
        
        if(!arg || arg !="树") 
        return notify_fail("你要砍什么？\n");
        
        
        if(me->query("qi") < 20 ||me->query("jing") < 20)  
        return notify_fail("你太累了，小心身体要紧！\n");
        
        if(me->query_temp("cutting")) 
        return notify_fail("你正在砍树呢！\n");
        
        if(!present("fu tou",me))
        return notify_fail("没有斧头怎么砍呀？\n");          
        
        if(me->query_temp("famu") <= 0)
        return notify_fail("你想干吗？这里不允许你砍树的。\n");
        
        me->set_temp("cutting",1);
        message_vision("$N挥起斧头，猛的往树干上砍去.....\n",me);
        call_out("cutting",1,me );
        return 1;

}
private void cutting(object me)
{
        if(!me) return;

        if( me->query("kar") < random(15) + 10) {
                message_vision(HIY"“啪”的一声，$N的斧头落在树干上，却被卡得紧紧的，拔不出来。\n"NOR,me);
                me->start_busy(1);
                me->add("qi",- random(5));
                me->delete_temp("cutting");
                return;
        }       
        if( me->query("int") < random(15) + 15)  {      
                message_vision(HIR"$N用力过猛，斧柄打到$N的手臂，一股酸痛.......\n"NOR,me);
                me->add("jing",- random(10));
                me->add("qi", - random(10));
                me->delete_temp("cutting");
                return;
        }       
        if( me->query_temp("cuttimes") > 8 + random(10)){
                me->set_temp("finish_famu",me->query_temp("cuttimes"));
                me->delete_temp("cutting");
                me->delete_temp("cuttimes");
                call_out("end_cutting",1,me); 
                return;
        }
        
        if(present(me)) { 
                message_vision(HIY"“啪”的一声，$N斧头落在树干上，留下一道深深的口子。\n"NOR,me);
                me->add("qi", - random(8));
                me->add("jing", - random(8));   
                me->add_temp("cuttimes", 1);
                me->delete_temp("cutting");
                return;
        }       

}

private void end_cutting(object me)
{
        object obj;

        if(!me) return;

        write(HIW"只听见啪嗒一声，一块木头掉了出来。\n"NOR);
        message_vision("$N花了九牛二虎之力，终于把树干砍了下来。\n",me);
        obj = new("/clone/misc/wood");
        obj->move(me);
        return;
}
