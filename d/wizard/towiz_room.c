 // wizard.c

inherit CHAT_ROOM;

void create()
{
        set("short","玩家接待室");
        set("long",@LONG
这里是武林列传的巫师们用来接待玩家，让玩家反映问题的专用房间
。只见房间墙壁上挂着一块留言板，那是提供给武林列传的玩家们反映问
题所使用的。如果你对武林列传有什么看法或者建议，请发布在这个留言
板上，巫师们会经常来到这里看的。
LONG
);
        set("exits",([
                "west":  "/d/center/chat_room",
        ]));
        set("objects",([
        ]));
        call_other("/clone/board/towiz_b2","??");
        set("restrict_action",1);
        ::create();
}  
