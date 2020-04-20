// jiaowai8.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁人
心脾。呼朋唤友开怀欢乐正其时。绿油油的草地上，沾着星点的露珠，显
然是一个放牧(fangmu)的好地方。
LONG );
	set("exits", ([
		"east" : __DIR__"nanmen",
		"west" : __DIR__"jiaowai9",
	]));
	set("outdoors", "city");
	setup();
}
void init()
{
	add_action("do_fangmu", "fangmu");
}
int do_fangmu(string arg)
{
	object me, horse;

	me = this_player();

	if(me->query_temp("fangmu"))
		return notify_fail("你正在放牧！\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法放牧！\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(!objectp(horse = me->query_temp("ride_ob"))
	|| !present(horse,me))
		return notify_fail("你要牧什么？\n");

	message_vision("$N开始放牧“" + horse->name() + "”....\n", me);
	me->set_temp("fangmu",1);
	call_out( "compelete_fangmu", 5, me, horse );
	return 1;
}

private void compelete_fangmu(object me, object horse)
{

	if(!me || environment(me) != this_object()) return;
	
	me->delete_temp("fangmu");

	if( objectp(horse) ) {
		if( horse->query("horse_prop/life") >= horse->query("horse_prop/max_life") )
			tell_object(me, "你的“" + horse->name() + "”已经精神百倍了！\n" );
		else {
			horse->add("horse_prop/life", horse->query("horse_prop/max_life") / 10 + 1);
			tell_object(me, "你的“" + horse->name() + "”精神好多了！\n" );
		}
		tell_object(me, "“" + horse->name() + "”的最大能力是："
			+ chinese_number( horse->query("horse_prop/max_life") ) + "。\n" );
		tell_object(me, "“" + horse->name() + "”的当前能力是："
			+ chinese_number( horse->query("horse_prop/life") ) + "。\n" );
	}

	return;
}
int valid_leave(object me,string dir)
{
	if ( me->query_temp("fangmu") ) 
		return notify_fail( "你还没有放牧完呢！\n" );

	return ::valid_leave(me, dir);
}
