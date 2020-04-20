// main-06.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是富豪院的后院，后院里两旁种满了各式各样的鲜花，争鲜斗艳
，吐露芬芳。后院中有一座小假山，怪石嶙峋，十分逼真。两个小女孩正
在假山后捉迷藏呢。北边通往富豪院的厨房和杂货房，西面是提供给家丁
丫环们休息的地方。
LONG
);
        set("exits", ([
                "north": __DIR__"main-07",
                "south": __DIR__"main-01",
                "west":  __DIR__"main-08",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 1,
        ]));

        setup();
}
void init()
{
        add_action("do_sao","sao");
}

int do_sao(string arg)
{

        object me;
        int times;

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
