                       // houting.c 后厅
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
        set("short", "后厅");
        set("long", @LONG
这里是古墓的后厅，密封得严严实实，没有一丝的缝隙。在昏暗的灯
光下，你发现墙上悬挂着一幅画 (picture)，似乎是一幅人物的肖像。在
厅的中央，摆放着几具棺材(coffin)，其中只有一具棺材的棺板没有合上
，棺材中好象空空如也。
LONG
);
        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));
        set("objects",([
                CLASS_D("gumu") +"/yang": 1,
        ]));
        set("item_desc", ([
                "picture": @TEXT
画中是一个中年道士的背影，看不出什么相貌，画中人一手指天，画角题
着‘$MAG$活死人像$NOR$’几个大字。
TEXT,
                "coffin": @TEXT
用厚厚的石板做成的棺材，棺板合上后，就没有一丝的缝隙了。
TEXT,
        ]) );
        set("getbook",1);
        setup();
}

void init()
{
        add_action("do_tang", "tang");
        add_action("do_niu", "niu");
}

int do_tang(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "coffin" ) 
                return notify_fail("你要躺在哪儿？\n");

        if(query("getbook")>0) {
        
message_vision("$N躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝了，\n",this_player());
        message_vision("摸索中$N似乎发觉棺板内壁题着有字，细细摸来，好象一头写着\n", 
this_player());
        
message_vision("‘"+HIW"玉女心经，技压全真；重阳一生，不输与人"NOR+"’这样十六个大字，\n",
 this_player());
        message_vision("另一头好象是一些图形之类的符号。$N不知所以，心想管他的先\n", 
this_player());
        message_vision("拓下来再说，于是脱下身上布衫，细细地将板上文字全部拓了下\n", 
this_player());
        message_vision("来。正在拓字之间，似乎摸到棺角上有一块凸起的机关(lock)。\n", 
this_player());

        if (random(21)>10)
                ob=new("/clone/book/jiuyin2");
        else
                ob=new("/clone/book/jiuyin1");
        ob->move(me);
        add("getbook",-1);
        }
        else {
        
message_vision("$N躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝，\n",this_player());
        message_vision("摸索中$N似乎发觉棺板内壁以前刻着有字，不过这字迹已经被人\n", 
this_player());
        message_vision("故意刮掉了。突然间，似乎摸到棺角上有一块凸起的机关(lock)。\n", 
this_player());
        }

        me->set_temp("tmarks/棺",1);
        return 1;
}

int do_niu(string arg)
{
        object me=this_player();

        if( !arg || arg != "lock" || me->query_temp("tmarks/棺",1)<1) {
                return notify_fail("你要扭动什么？\n");
        }

        
message_vision("$N手握机关，轻轻向下扭动，忽然间棺底吱吱作响，裂开了一个\n",this_player());
        message_vision("大洞，$N向洞中落了下去。\n", this_player());
        me->move(__DIR__"mishi2");

        me->set_temp("tmarks/棺",0);
        return 1;

}

