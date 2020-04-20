//ymh_b.c 桃源城留言版

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("桃源城留言板", ({ "board" }) );
        set("location", "/d/center/yingxionglou");
        set("board_id", "taoyuan");
        set("long",@LONG
这里是提供给桃源城百姓们留言使用的留言版。
LONG
);
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

