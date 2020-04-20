// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "小石屋");
	set("long", @LONG
石屋内空无一物，除了四面墙之外，连一件家具都没有，但室内到十
分干净，一尘不染，显然经常有人来打扫的。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"houhuayen",
	]));
	setup();
}
void init()
{
	object book, me;
	me = this_player();
	
	add_action("do_break", "break");
	if ((objectp(book=present("kuihua baodian",me)))) {
		remove_call_out("buqun_rob");
		call_out("buqun_rob", 1, me, book);
	}
}

int do_break(string arg)
{
	int n;
	n = this_player()->query("neili");
	if( !arg && arg!="壁" && arg!="wall") {
		write("你认为你可以打碎石壁吗？\n");
		return 1;
	}

	message_vision("$N拾起一块斗大石头，运力向石壁上砸去。\n", this_player());
	if (n>=500) {
	message_vision("忽然嘭的一声响，石头穿过石壁，石壁上破了一个大洞！\n", this_player());
	set("exits/down",  __DIR__"biguan");
	this_player()->set("neili",n-200);
	remove_call_out("close");
	call_out("close", 5, this_object());
	}
	else {
	message_vision("$N大吼一声，双拳猛打，但好象没用，看来$N的内力不够强。\n", this_player());
	this_player()->set("neili",0);
	}

	return 1;
}

void close(object room)
{
	message("vision","石壁上的碎石不住滚落下来，又堵住了大洞。\n", room);
	room->delete("exits/down");
}
