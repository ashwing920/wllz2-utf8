
// /clone/board/xuedao_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("血刀门弟子留言板", ({ "board" }) );
	set("location", "/d/xuedao/dadian");
	set("board_id", "xuedao_b");
	set("long", "这是一个供血刀门弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

