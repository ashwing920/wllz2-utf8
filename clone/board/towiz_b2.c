// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("玩家意见留言板", ({ "board" }) );
        set("location", "/d/wizard/towiz_room");
        set("board_id", "towiz_b2");
        set("long", "这是一个专供玩家提出建议使用的留言板。\n" );
        setup();
        set("capacity", 10000);
        replace_program(BULLETIN_BOARD);
}

