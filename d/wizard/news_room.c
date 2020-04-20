// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
        set("short", "新闻发布室");
        set("long", @LONG
这里是武林列传新闻发布室。巫师组每当做了更新之后，都会把最新
的消息发布在这里的新闻留言板上。
LONG
);

        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"wizard_room",
        ]));
        set("no_fight",1);
        setup();

        call_other("/clone/board/news_b", "???");
        replace_program(ROOM);
}
void init()
{
        object me;
        
        if(interactive(me = this_player()) && !wizardp(me))
        if(userp(me)){
                me->move("/d/city/kedian");
                message_vision("$N被赶出了巫师休息房，因为不是巫师。\n",me);
        }
}
