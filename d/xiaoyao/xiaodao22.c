// xiaodao22.c 林间小道
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到
路的尽头。两旁百花争艳，令人留连忘返，北面有一片的足有一人高草丛
，十分茂密。南边好象有香味散发出来，西边是终年结冰的寒冰池。
LONG
);
	set("exits", ([ 
		"west" : __DIR__"hanbingchi",
		"southeast" : __DIR__"xiaodao21",
	]));
	set("item_desc",([
		"草丛":"一片茂密的草丛，地面上的青草已经枯萎了，好象是被人践踏所致。\n",
	]));
	set("outdoors", "xiaoyao");
	setup();
}
void init()
{
	add_action("do_bo","bo");
}
int do_bo(string arg)
{
	object me;
	me = this_player();
	
	if(!arg || arg =="") return 0;
	if(arg == "草丛" || arg =="caocong"){
		if(me->query("family/family_name") =="逍遥派"){
			message_vision("$N拨开草丛，往草丛中走了进去。\n",me);
			me->move("/d/xiangyang/eastgate2");
			tell_room(environment(me),me->name()+"从边上的草丛中钻了出来。\n",({me}));
		}
		else {
			message_vision("$N拨了拨草丛，却发现里面什么也没有。\n",me);
	
		}
		return 1;
	}
}
