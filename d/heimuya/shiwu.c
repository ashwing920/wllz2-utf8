// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
石屋当中安放着一巨大的绞索绞盘，绞盘吊着一只大竹篓(lou)，看来
是上下黑木崖的主要工具。
LONG
);
	set("exits",([
		"east" : __DIR__"pailou",
	]));
	set("objects",([
		__DIR__"npc/youxun" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
		if( !(room = find_object(__DIR__"zhulou")) )
			room = load_object(__DIR__"zhulou");
		if( room = find_object(__DIR__"zhulou") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/enter", __DIR__"zhulou");
				room->set("exits/out", __FILE__);
				message("vision", "一个大竹篓缓缓地升了上来，停在你的面前。\n", this_object() );
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "只听得崖下隐隐传来：“别急嘛，"
					"这儿正忙着呐……”\n",this_object() );
		}
		else
			message("vision", "ERROR: boat not found\n", this_object() );
	}
	else
		message("vision", "竹篓就停在你的面前,又何必喊呢？\n",
			this_object() );
}


void on_board()
{
	object room;
	if( !query("exits/enter") ) return;
		message("vision", "崖顶的绞盘开始转动，竹篓向下降了下去。\n",this_object() );

	if( room = find_object(__DIR__"zhulou") ){
		room->delete("exits/out");
		message("vision", "崖顶的绞盘开始转动，竹篓向下降了下去。\n",room);
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"zhulou") ){
		room->set("exits/out", __DIR__"ryping");
		message("vision", "竹篓晃了几下，在靠在坪上停了下来。\n",room);
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"zhulou") ) {
		room->delete("exits/out");
		message("vision","竹篓晃了几下，又从坪下驶向崖上。\n", room);
		room->delete("yell_trigger");
	}
}

int do_yell(string arg)
{

	if( !arg || arg=="" ) return 0;
	if( arg=="下崖" ) arg = "下崖";
	if( (int)this_player()->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",this_player());
	else if( (int)this_player()->query("neili") > 500 )
	message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", this_player());
	else
	message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",this_player());
	if( arg=="下崖"){
		check_trigger();
		return 1;
	}
	else
	message_vision("崖下远远传来一阵回声：“" + arg +"～～～”\n", this_player());
	return 1;
}

