//Cracked by Kafei
//Jay 5/10/97

#define SHIP "/d/quanzhou/ship"

inherit ROOM;

void check_trigger();
void on_ship();
void arrive();
void close_passage();
int  do_yell(string);

void create()
{
	set("short", "通吃岛");
	set("long", @LONG
这个小岛是一等通吃侯韦小宝命名的通吃岛，又叫钓鱼岛。本岛坐落
在台湾东北方，当年有五百水师曾在岛上驻扎，是中国的领土。
LONG
);

	set("exits", ([
		"north" : __DIR__"diaoyu1",
	]));
	set("objects", ([
		"/d/quanzhou/npc/shuishi" : 1,
                "/d/quanzhou/npc/langren" : 3,
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

	if (!arg || arg != "chuan") return 0;

	if(present("shuishi bing", environment(me))){
		message("vision","水师士兵说道：再不走施将军要着急了，你就上船吧。\n", this_object());
		check_trigger();
		return 1;
	}
	else return 0;
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
	if( !(room = find_object(SHIP)) )
		room = load_object(SHIP);
	if( room = find_object(SHIP) ) {
		if((int)room->query("yell_trigger")==0 ) {
		room->set("yell_trigger", 1);
		set("exits/enter", SHIP);
		room->set("exits/out", __FILE__);
		message("vision", "水师士兵把战船的风帆扯起，准备起航。\n", this_object());
		message_vision("水师士兵将一块踏脚板搭上沙滩，对$N说：“上来吧”\n", this_player());
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
		message("vision", "水师士兵说道：“快上来吧。”\n",this_object() );
}

void on_ship()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "水师士兵把船锚收起，顺风转动风帆。\n",this_object() );

	if( room = find_object(SHIP) ){
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
	if( room = find_object(SHIP) ){
		room->set("exits/out", "/d/quanzhou/houzhu");
		message("vision", "水师士兵说道：“报告，泉州到了！”\n",room );
	}

	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(SHIP) ) {
		room->delete("exits/out");
		message("vision","水师士兵把踏脚板收起来，战船驶向了茫茫的大海...\n", room);
		room->delete("yell_trigger");
	}
}

void reset()
{
	object room;
	::reset();
	if( room = find_object(SHIP) )
	room->delete("yell_trigger");
}

int valid_leave(object me, string dir)
{
	if ( dir == "north" && present("lang ren", environment(me)))
		return notify_fail("日本浪人喝道：你的，日本人的，不是。尖阁列岛的，不可以。\n");
	return ::valid_leave(me, dir);
}
