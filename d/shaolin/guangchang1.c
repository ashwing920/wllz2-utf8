// Room: /d/shaolin/guangchang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;
string look_gate();
void create()
{
        set("short", "广场");
        set("long",@LONG
这里是少林寺前的广场，整个广场由大块的青石铺成，极为平坦。但
因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场周围
都是密密的松树林，四角上各放了几块石碑，字迹都甚为模糊。正前方黄
墙碧瓦，飞檐翘檩，在正中有一道二丈来宽，三丈来高的朱红杉木包铜大
门(gate)。上方一块大匾，龙飞凤舞地书着$HIY$少林寺$NOR$三个大字。寺前三三两
两的站着几个僧人。
LONG
);

        set("exits", ([
                "east" : __DIR__"guangchang1e",
                "south" : __DIR__"shijie11",
                "west" : __DIR__"guangchang1w",
        ]));

        set("outdoors", "shaolin");
        set("item_desc",([
                "gate"  :       (: look_gate :),
        ]));
        set("objects",([
                CLASS_D("shaolin") + "/qing-fa" : 1,
                CLASS_D("shaolin") + "/master_shaolin" : 1,
        ]));
        setup();
        "/clone/board/shaolin_b"->foo();
}

void init()
{
        add_action("do_knock", "knock");
}
int close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"smdian")) )
        room = load_object(__DIR__"smdian");
        if(objectp(room)){
        delete("exits/north");
        message("vision", "乒地一声，里面有人把大门关上了。\n",this_object());
        room->delete("exits/south");
        if (objectp(present("qingguan", room)))
                message("vision", "清观上前把大门关了起来。\n", room);
        else
                message("vision", "壮年僧人上前把大门关了起来。\n", room);
        }
        else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
        object room;

        if (query("exits/north"))
        return notify_fail("大门已经是开着了。\n");

        if (!arg || (arg != "gate" && arg != "north"))
        return notify_fail("你要敲什么？\n");

        if(!( room = find_object(__DIR__"smdian")) )
        room = load_object(__DIR__"smdian");
        if(objectp(room))
        {
        set("exits/north", __DIR__"smdian");
        message_vision("$N轻轻地敲了敲门，只听吱地一声，一位壮年僧人应声打开大门，\n"
                "他用锐利的目光上上下下打量着$N。\n",this_player());
        room->set("exits/south", __FILE__);
        message("vision", "外面传来一阵敲门声，壮年僧人应声上前把大门开。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
        }

        return 1;
}

int valid_leave(object me, string dir)
{
        if ( dir != "north" ){
        return ::valid_leave(me, dir);
        }

        if (!::valid_leave(me, dir)) return 0;

        if ( (me->query("family/family_name") == "少林派")){
        if (me->query("class") != "bonze"){
                return notify_fail("壮年僧人说道：对不起，俗家弟子不得入寺修行。\n");
        }
        if (((int)me->query("guilty") == 0) && ((int)me->query("K_record") ==
                ((int)me->query("PKS")))){
                write("壮年僧人侧身让开，说道：师兄辛苦了，请进。\n");
                return 1;
        }
        else {
                if((int)me->query("guilty") == 0) {
                if((int)me->query("shen_record") > (int)me->query("shen"))
                        me->set("guilty", 1);
                else
                        me->set("guilty", 2);
                me->set("K_record", me->query("PKS"));
                me->set("shen_record", me->query("shen"));
        }

                me->move(__DIR__"smdian");
                return notify_fail("壮年僧人沉下脸来，说道：戒律院主持玄痛大师请师兄\n"
                "火速去戒律院陈述此行过犯。\n");
        }
        }
        else if( present("yingxiong ling", me) )
        {
                write("壮年僧人合十为礼，侧身让开，说道：原来是贵客驾到，请进请进！\n");
        return 1;
        }
        
else if (me->query("luohan_winner")) 
{
        message_vision(HIY "壮年僧人对$N合十为礼，侧身让开，说道：原来是闯过罗汉阵的大英雄驾到，请进请进！\n" NOR, me);
        return 1;
}
        if (me->query("shen") >= 0){
        if (me->query("gender") == "女性"){
                return notify_fail("壮年僧人说道：这位女施主还是请回罢，本寺从不接待女客。\n");
        }
        else
        {
                return notify_fail("壮年僧人说道：这位施主请回罢，本寺不接待俗人。\n");
        }
}

        return notify_fail("壮年僧人立时从身畔挚出一把雪亮的戒刀来，把明晃晃的\n"
                "刀尖对准你的胸口，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n"
                "以后再敢走近少林一步，我立时就斩断你们的狗腿！\n");

}

string look_gate()
{
        return "一道三丈来高的朱红杉木包铜大门。\n";
}
