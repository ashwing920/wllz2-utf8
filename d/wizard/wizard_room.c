// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
        set("short", "巫师休息室");
        set("long", @LONG
这里就是「武林列传」巫师的休息所在，刚粉刷过的四周墙壁上光秃
秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫师留言
簿(board)。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                "down" : "/d/center/chat_room",
                "east" : __DIR__"news_room",
        ]));
        set("no_fight",1);
        setup();
        call_other("/clone/board/wiz_b", "???");
        replace_program(ROOM);
}
void init()
{
        object me=this_player();
        if(!wizardp(me) && wizhood(me) != "(immortal)")
        if(userp(me)){
                me->move("/d/center/chat_room");
                message_vision("$N被赶出了巫师休息房，因为不是巫师。\n",me);
        }
}
