// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit ROOM;

private string *name = ({
        __DIR__"fish/fish",
        __DIR__"fish/fish1",
        __DIR__"fish/fish2",
        __DIR__"fish/fish3",
        __DIR__"fish/fish4",
        __DIR__"fish/fish5",
        __DIR__"fish/fish6",
        __DIR__"fish/fish7",
        __DIR__"fish/fish8",
        __DIR__"fish/fish9",
        __DIR__"fish/fish10",
        __DIR__"fish/fish11",
        __DIR__"fish/fish12",
});
private string *badname = ({
        HIC"一双破鞋"NOR,
        YEL"一件破烂不堪的衣服"NOR,
        YEL"一个扯烂了的鱼网"NOR,
        YEL"一顶破烂的斗笠"NOR,
        HIR"一件红色的肚兜"NOR,
        RED"一只螃蟹"NOR,
        WHT"一个已经进水的灯笼"NOR,
        YEL"一个破烂的睡袋"NOR,
        HIW+BLK"一只乌龟"NOR
}); 

void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
这里是汉水中下游，水流见缓。江边有一老翁身穿蓑衣，头带斗笠，
嘴含烟袋正悠闲自得的钓着鱼，哇！他身边已经掉了好几根大鱼了！还发
什么呆啊？你旁边还放着几根钓鱼杆，快点钓(fish)吧。
LONG
);
        set("outdoors", "center");
        set("exits", ([ 
                "west" : "/d/shaolin/hanshui1",
        ]));
        setup();
}

void init()
{
        add_action("do_fish", "fish");
}
int do_fish(string arg)
{        
        object me;

        me = this_player();
        if(me->query_temp("fishing") == 1) return notify_fail("钓鱼要耐心一点嘛！\n");
        if(me->query("qi") < 20|| me->query("jing") < 20) return notify_fail("身体要紧，还是赶紧休息吧！\n");
        message_vision("$N拿着一把钓鱼杆坐在大石头上钓起鱼来......\n",me);
        me->set_temp("fishing", 1);
        call_out( "compelete_fish", random(4) +3, me );
        return 1;
}

varargs protected void compelete_fish(object me)
{
        object ob;
        string badstr;

        badstr = badname[random(sizeof(badname))];
        
        me->delete_temp("fishing");
        
        if( random(10) > 6 ) {
                message_vision("$N猛的一提杆，仔细一看，钓到了"+ badstr+"。\n",me);
                tell_object(me,"你心里不禁骂道：%!#@$!#@，怎么今天那么背？！\n");
                me->add("qi",-10);
                me->add("jing",-10);
                return;
        }

        if( random(3) < 1) {
                message_vision("鱼漂晃动，$N心里一急，猛的一提杆，鱼饵被吃掉了，$N却什么也没钓到。\n",me);
                me->add("qi",-10);
                me->add("jing",-10);
                return;
        }

        if( present(me)){
                ob = new(name[random(sizeof(name))]);
                if( ob->query("name") == HIY"娃娃鱼"NOR ) {
                        message_vision("$N猛的一提杆，钓到了一条活蹦乱跳的"HIY"娃娃鱼"NOR"。\n",me);
                        message_vision("$N得意的提起那条"HIY"娃娃鱼"NOR"，得意的说道：又是一个丰收的日子！\n",me);
                        ob->move(me);
                        me->add("qi",- 20);
                        me->add("jing", - 20);
                        me->add("combat_exp",30);
                        me->add("potential",30);
                        tell_object(me,HIC"你的经验增加了三十点。\n"NOR);
                        tell_object(me,HIC"你的潜能增加了三十点。\n"NOR);
        }
        
                else {
                        message_vision("$N一提杆，钓到了一条"+ ob->name(1)+"。\n", me);
                        ob->move(me);
                        me->add("qi", -10);
                        me->add("jing", -10);
                }
        }
        
        return;
}
