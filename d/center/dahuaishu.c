// dahuaishu.c - 大槐树
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "大槐树园");
	set("long", @LONG
这里是桃源城里最美而最宁静的大槐树园。槐树园里，种满了许多槐
树，园子中间一棵，可算是最粗壮的了。这棵大槐树已经有上千年的年龄
，树干上留下的皱纹和从树枝上垂下的须根就是以往岁月的见证。从董郎
和许仙时起，不知它见证了多少有情人结为良缘。绿油油的草地上，沾着
星点的露珠，显然是一个放牧(fangmu)的好地方。再往西面走是桃源城里
喜结良缘的好地方：红娘庄。
LONG
);
	set("exits", ([
		"east"  : __DIR__"roadn4",
		"west"  : __DIR__"hongniangzhuang",
	]) );
	set("outdoors","center");
	set("objects",([
		__DIR__"npc/bee": 2,
		__DIR__"npc/ant": 2,
		"/d/hangzhou/npc/maque": 2,
	]));
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
