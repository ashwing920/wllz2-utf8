// up-01e.c - 千金楼（厢房）

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "龙凤厢房");
        set("long", @LONG
这里是千金楼的龙风厢房，房间里布置得十分景致。一张龙凤大床陈
列在房间的右角。一个衣架放在大床的旁边，上面还挂着几件衣服。你往
床边一看，床帘(lian)垂下，露出一条细小的缝子，你隐约看到.......
LONG
);

        set("exits", ([
                "west"  : __DIR__"up-01",
        ]));
        set("item_desc",([
                "lian": @TEXT
床帘低垂，露出一条小缝，你真想拨(bo)开看个清楚。
TEXT
        ]));

        set("objects", ([
                __DIR__"npc/luonan": 1,
                __DIR__"npc/luonu": 1,
        ]) );

        setup();
        create_door("west","小木门","east",DOOR_CLOSED);
}

void init()
{
        add_action("do_bo","bo");
}

int do_bo(string arg)
{
        object me;
        me = this_player();
        
        if(!arg || arg == "")
                return notify_fail("你要拨什么？\n");
        
        if(arg == "lian" || arg == "床帘")  {   
        message_vision("$N轻轻的拨开床帘，仔细一看，只见床上，一对刺身裸体的男女正在.....\n",me);
        message_vision("忽然，里面传来一个女子的尖叫声：啊！！快来人啊，有色狼呀！！！！\n",me);
        remove_call_out("drop");
        call_out("drop",0,me);
        return 1;
        }
}

void drop()
{
        object me;
        me = this_player();
        
        message_vision("几个凶神恶煞模样的壮汉破门而如，喝道：$N，你是他妈的活得不耐烦了是吗？\n",me);
        message_vision("说完，把$N一把抓起，往门外冲了出去。\n",me);
        me->move("/d/qianjinlou/up-01");
        message_vision("$N被几个恶汉抓起，一直往楼下冲了下去。\n",me);
        me->move("/d/qianjinlou/main-01");
        message_vision("$N被几个恶汉抓起，从楼上抓了下来，一直往千金楼门口冲了出去。\n",me);
        me->move("/d/center/jiyuan");
        me->move("/d/center/roadn2");
        message_vision("$N被几个恶汉从千金楼里丢了出来，重重的摔到了地上。\n",me);
        message_vision("恶汉怒骂道：他妈的，没钱学人家来千金楼寻什么乐子？哼！说完，大大咧咧的走了。\n",me);
        if( me->query("qi") >= 10 )
        me->add("qi",-10);
        return;
}
