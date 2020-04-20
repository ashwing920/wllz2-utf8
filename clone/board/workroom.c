// workroom.c 逍遥的房间
// Design By BMW add from 1999.11.6

#include <ansi.h>
inherit CHAT_ROOM;

void create()
{
        set("short","逍遥居");
        set("long",@LONG 
一间收拾得十分整齐的房间，房间门口挂着一个牌子(sign)，
上面写着一些字。步入房间当中，举目四望，房间里收拾得十分干
净而整洁。大理石铺设的地板上，隐约倒映着你的影子。房间正中
有张八仙桌，上面还放着一些水果(shuiguo)和一些鲜花(flowers)
，这些都是来访的客人送的。身为天神，当然进贡的人不少啦！
LONG
);

        set("outdoors","city");
        set("chat_room", 1);
        set("no_fight",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_magic",1);
        
        set("item_desc",([
                "sign": HIM"
                
                逍
                
                遥
                
                居
                
\n"NOR,

                "shuiguo":"一些极为新鲜而罕见的水果，喊不出什么名字。\n",
                "flowers":"一束带着露珠的玫瑰花，正静静的躺在桌面上。\n",
]));

        set("exits",([
                "out": "/d/player/zoulang",
                "enter": __DIR__"woshi",
                "down":  "/d/wizard/wizard_room.c",
        ]));

        setup();
        
        call_other("/clone/board/bmw_b","??");
        
}
