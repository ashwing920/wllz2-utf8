 // /clone/board/wiz_b.c

inherit NEWS_BOARD;

void create()
{
	set_name("新闻公告板", ({ "board" }) );
	set("location", "/d/wizard/news_room");
	set("board_id", "news_b");
	set("long", "这是一个专供巫师发布新闻消息的留言板。\n" );
	set("wiz_only",1);
	setup();
	set("capacity", 10000);
	replace_program(NEWS_BOARD);
}
