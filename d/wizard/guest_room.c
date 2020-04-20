// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "巫师会客室");
        set("long", @LONG
这里是巫师和玩家交流的地方，如果你有什么问题需要向巫师请教，
可以在这里留言(post)。不过如果问题牵涉到解谜或者已经在帮助文件里
有详细说明，巫师们就不一定会回答。
LONG
);

        set("exits", ([
                "southeast": "/d/city/wumiao"
        ]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
        setup();
        call_other("/clone/board/towiz_b", "???");
}

