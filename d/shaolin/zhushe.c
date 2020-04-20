// Room: /d/shaolin/zhushe.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
string look_stone();

void create()
{
        set("short", "猪舍");
        set("long", @LONG
这是间破烂的农家猪舍。圈里养着几头瘦猪，泔槽已经干涸了，草料
也开始发霉腐烂。由于好多天没人清理牲口的粪便，满屋子弥漫着一股恶
臭。屋角堆了一大堆石块(stone)，足有半人高。
LONG
);
        set("exits", ([
                "southeast" : __DIR__"houshan",
        ]));
        set("item_desc",([
                "stone" : (: look_stone :),
        ]));
        set_temp("available",1);
        setup();
}

void init()
{
        add_action("do_move", "move");
}
int do_move(string arg)
{
        object me,ob;

        if( !arg || arg=="" || !query_temp("available") ) return 0;

        if( arg=="stone" && query_temp("available")) {
                write("你试著把石块一块块地搬开，突然发现下面埋着个奄奄一息的老人 !\n\n");
                delete_temp("available");
        }
        me = new(__DIR__"npc/lao-qiao",1);
        me->move(__DIR__"zhushe");

        ob = this_player();     

        message_vision("老人断断续续地说道: 我是乔三槐，快...，快往北山上走...，\n"
                        "进了松林...，往南...，往东...，往西...，往东...，再往北......\n\n", ob);
        message_vision("乔三槐嘴唇动了动，似乎还想说些什麽，却因伤重难支，昏死了过去。\n", ob);
        me->unconcious();
        remove_call_out("fainting");
        call_out("fainting", 25, me, ob);
        return 1;
}

void fainting(object me, object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if((int)me->query("qi") <= 50){
                message_vision("乔三槐缓缓苏醒了过来，说道: 谢...谢......。\n",ob);
                me->die();
        }
        else
        {
                message_vision("\n乔三槐醒了过来，说道: 再往北，往东，往西，南......出路在砖......\n\n",ob);
                message_vision("说罢脑袋便软软地垂了下去......",ob);
                me->die();
        }
        return;
}
string look_stone()
{
        return "这是一大堆石块，堆在墙脚边，不知是派什麽用场。\n";
}
