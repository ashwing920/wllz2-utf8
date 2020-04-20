//square.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大院");
        set("long", @LONG
你走进了明教总舵广场，却发现这里人声鼎沸，五散人群聚于此，看
来有要事发生了。来往教众匆匆忙忙。广场左首是教众饭堂；右首就是教
众闻之变色的刑堂。向上走就是光明顶明教总舵了。
LONG
);
        set("exits", ([
                "west"  : __DIR__"fangtang",
                "northup" : __DIR__"qiandian",
                "east"  : __DIR__"xingtang",
                "south"   : __DIR__"tianweitang",
        ]));
        set("objects",([
                 __DIR__"npc/shuobude":1,
                 __DIR__"npc/zhangzhong":1,
                 __DIR__"npc/pengyingyu":1,
                 __DIR__"npc/zhoudian":1,
                 CLASS_D("mingjiao") +"/master_mingjiao": 1,
        ]));
        set("valid_startroom",1);
        set("outdoors", "mingjiao");
        setup();
        "/clone/board/mingjiao_b"->foo();
}

int valid_leave(object me, string dir)
{
        me = this_player();
        if((string)me->query("party/party_name") != HIG"明教"NOR
        && (dir!="south")
        && (objectp(present("peng yinyu", environment(me)))))
                return notify_fail("彭莹玉拦住你说：此处乃明教重地，请止步。\n");
        return ::valid_leave(me, dir);
}
