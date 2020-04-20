// jingjichang

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "竞技场观摩室");
	set("long", @LONG
	
		$BWHT$$GRN$※※※※※※※※※※※※※※※※※$NOR$
		$BWHT$$GRN$※                              ※$NOR$
		$BWHT$$GRN$※  $BLK$打  遍  天  下  无  敌  手$GRN$  ※$NOR$
		$BWHT$$GRN$※                              ※$NOR$
		$BWHT$$GRN$※※※※※※※※※※※※※※※※※$NOR$

	$BWHT$$GRN$※※※※※$NOR$                              $BWHT$$GRN$※※※※※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$脚$GRN$  ※$NOR$                              $BWHT$$GRN$※  $BLK$拳$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$踢$GRN$  ※$NOR$  这里是桃源城的竞技场休息室。$BWHT$$GRN$※  $BLK$打$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$北$GRN$  ※$NOR$  从这里可以看到上面的大擂台。$BWHT$$GRN$※  $BLK$南$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$海$GRN$  ※$NOR$  擂台上面挂着一幅很大的对联。$BWHT$$GRN$※  $BLK$山$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$蛟$GRN$  ※$NOR$                              $BWHT$$GRN$※  $BLK$猛$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※  $BLK$龙$GRN$  ※$NOR$                              $BWHT$$GRN$※  $BLK$虎$GRN$  ※$NOR$
	$BWHT$$GRN$※      ※$NOR$                              $BWHT$$GRN$※      ※$NOR$
	$BWHT$$GRN$※※※※※$NOR$                              $BWHT$$GRN$※※※※※$NOR$
$NOR$
LONG
	);

	set("watch_fight_room", 1);

	set("exits", ([
		"north"      : __DIR__"roads7",
		"leitai":          __DIR__"leitai",
	]) );                   
	set("no_fight",1);
	set("no_beg",1);
	set("no_sleep_room",1);
	set("no_steal",1);
	setup();

	create_door("north", "红漆大门", "south", DOOR_CLOSED);
}
int valid_leave(object me,string dir)
{
	if(me->query("env/wimpy") && dir == "leitai"){
		me->delete("env/wimpy");
	}
	if(me->query_temp("last_damage_from") ){
		me->delete_temp("last_damage_from");
	}
	return ::valid_leave(me, dir);
}
