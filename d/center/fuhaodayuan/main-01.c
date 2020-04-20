// main-01.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "富豪大院");
        set("long", @LONG
推开大门，你来到了富豪大院当中。只见大院十分宽敞，大院两边种
满了各式各样的鲜花和青草，显得十分好看。大院右角有一棵大松树，枝
叶茂盛，十分粗壮，犹如一把大伞向四周散开，给大院里留下了一片绿荫
。大院中间有一条小石路，一直往西面的大厅延伸。北面的小路则通往后
院。
LONG
);
        set("exits", ([
                "west" : __DIR__"main-02",
                "east": "/d/center/furen",
                "north": __DIR__"main-06",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 1,
        ]));

        setup();
        create_door("east","朱漆大门","west",DOOR_CLOSED);
}
void init()
{
        add_action("do_sao","sao");
}

int do_sao(string arg)
{
        int times;
        object me;
        me = this_player();

        if(!arg || arg!="地")
                return notify_fail("你要干什么？\n");

        if (me->is_fighting())return notify_fail("边扫地边打架？你是神仙呀？！\n");
        if (!present("sao ba",me)) return notify_fail("没有扫把怎么扫地呀？\n");
        if (me->is_busy()) return notify_fail("你正忙着呢！！\n");
        if ( me->query("qi") < 20 || me->query("jing") <= 20) return notify_fail("你太累了，还是休息一下吧！\n");
        if (me->query_temp("working")) return notify_fail("你已经在扫地了！\n");
        if (me->query_temp("clean_finish") >= 1) return notify_fail("这里已经打扫完了，快去交差吧！\n");
        if (me->query_temp("clean_job")!= 1) return notify_fail("人家又没有请你，你喜欢白干呀？\n");

        times = 10 + random(5);

        if ((int)me->query_temp("job_times") > times ){
        tell_object(me,"这里已经打扫干净了，你终于完成了任务，人也累坏了。\n");
        me->set_temp("clean_finish",1);
        return 1;
        }

        me->set_temp("working",1);
        message_vision("$N拿着扫把，仔细的打扫着这里的每一个角落。\n",me);
        call_out( "compelete_sao", 1, me );
        me->start_busy(1);
        return 1;
}
private void compelete_sao(object me)
{
        if (random(50) == 25){
                message_vision("$N把一堆树叶扫成一堆，谁知一阵狂风吹来，落叶漫天飞舞.....\n",me);
                me->add("qi",- random(5));
                me->delete_temp("working");
                return;
        }
        if (random(100) > 60){
                message_vision("$N用力过猛，扫把头被$N给甩了出来，不偏不倚还打在$N的头上。\n",me);
                me->add("jing",- random(10));
                me->add("qi",- random(10));
                me->delete_temp("working");
                return;
        }

        if( present(me) ) {
                message_vision("只听见唰唰的声响，这里在$N的打扫下，显得干净了许多。\n", me);
                me->delete_temp("working");
                me->add("qi", - 10);
                me->add("jing",- 10);
                me->add_temp("job_times",1);
                me->add("all_job_times",1);
                return;
        }

        return;
}
