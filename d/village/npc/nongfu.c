// poorman.c

inherit NPC;

void create()
{
	set_name("农夫", ({ "nong fu","nong ming" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long",@LONG
一个老实巴交的农夫，黑皱皱的脸上，充满了哀愁。
LONG);
	set("attitude", "friendly");
	set("combat_exp", 250);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	set("chat_chance",5);
	set("chat_msg", ({
		"农夫叹了口气：孩子他娘，你在究竟哪里呀？\n",
		"农夫再也忍不住，眼泪哗啦啦的流了下来。\n",
	}));
	set("inquiry",([
		"伤心事":"我家媳妇，从前天早上出去，到现在就一直没回来，要是她有个三长两短的....",
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
