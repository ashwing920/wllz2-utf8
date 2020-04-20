                  // /clone/board/wiz_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW"游戏新闻公告板"NOR, ({ "board" }) );
        set("location", "/d/center/chat_room");
        set("board_id", "wiz2_b");
        set("wiz_only",1);
        set("long",@LONG
这是一个专供巫师做更新通告的留言板。
LONG
);
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
