 //ymh_b.c 蝴蝶君的留言版

#include <ansi.h>
#include <login.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("蝴蝶君的留言板", ({ "board" }) );
        set("location", "/u/robert/workroom");
        set("board_id", "robert");
        set("long","这是蝴蝶君的留言板，如果你对"MUD_NAME"有什么不满意的地方，尽可以
在这里投诉！蝴蝶君会尽快给予答复的。\n");
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

