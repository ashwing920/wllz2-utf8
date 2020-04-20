// houzhu.c 后渚港
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void check_trigger();
void on_ship();
void arrive();
void close_passage();
int  do_yell(string);

void create()
{
	set("short", "后渚港");
	set("long", @LONG
后渚港是泉州三大港口之首。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。由于海外贸易的
广泛发展，泉州因而成为「海上丝绸之路」的起点。在众多的船只中间，
还有一只大战船(chuan)。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"gangkou4",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/shuishi" : 1,
	]));
	set("item_desc", ([
		"chuan" : "这是一艘大战船，刚刚从台湾回来。水师们乘(cheng)战船打仗。\n",
	]));
	set("outdoors", "quanzhou");
	setup();
}
void init()
{
	add_action("do_yell", "cheng");
}
int do_yell(string arg)
{

	object me = this_player();
	object ob;

	if (!arg || arg != "chuan") return 0;

	if(present("shuishi bing", environment(me))){
		if (!(ob = present("shi lingpai",me))) {
		message_vision("水师士兵对$N说道：你以为这是你自家的船吗？\n",me);
		return 1;
	}
	message("vision","水师士兵接过令牌，点点头，说道：既然施将军有令，你就上船吧。\n", this_object());
		destruct(ob);
		check_trigger();
		return 1;
	}
	else return 0;
}

void check_trigger()
{
    object room;

	if(!query("exits/enter") ) {
	if( !(room = find_object(__DIR__"ship")) )
	    room = load_object(__DIR__"ship");
	if( room = find_object(__DIR__"ship") ) {
	    if((int)room->query("yell_trigger")==0 ) {
		room->set("yell_trigger", 1);
		set("exits/enter", __DIR__"ship");
		room->set("exits/out", __FILE__);
		message("vision", "水师士兵把战船的风帆扯起，准备起航。\n", this_object());
		message_vision("水师士兵将一块踏脚板搭上码头，对$N说：“上来吧”\n", this_player());
		remove_call_out("on_ship");
		call_out("on_ship", 20);
	    }
	    else
		message("vision", "真遗憾！船刚开走。\n", this_object() );
	}
	else
	    message("vision", "ERROR: boat not found\n", this_object() );
    }

    else
	message("vision", "水师士兵说道：“快上来吧。”\n",
	    this_object() );
}

void on_ship()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "水师士兵把船锚收起，顺风转动风帆。\n",
	this_object() );

    if( room = find_object(__DIR__"ship") )
    {
	room->delete("exits/out");
	message("vision", "战船驶向了茫茫的大海...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 120);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"ship") ){

	room->set("exits/out", "/d/island/diaoyu");
	message("vision", "水师士兵说道：“报告，前方发现海岛！”\n",room );

	}

	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"ship") ) {
	room->delete("exits/out");
	message("vision","水师士兵把踏脚板收起来，战船驶向了茫茫的大海...\n", room);
	room->delete("yell_trigger");
	}
}

void reset()
{
	object room;

	::reset();
	if( room = find_object(__DIR__"ship") )
	room->delete("yell_trigger");
}

