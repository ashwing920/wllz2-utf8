//clone/board/murong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("慕容世家留言板",({ "board" }));
        set("location", "/d/yanziwu/dating");
        set("board_id", "murong_b");
        set("long","这是慕容世家弟子传递信息用的留言板\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
