// go.c

#include <ansi.h>

inherit F_CLEAN_UP;

#define DROP_CMD 	"/cmds/std/drop"

mapping default_dirs = ([
	"north":        "北边",
	"south":        "南边",
	"east":         "东边",
	"west":         "西边",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":     "东边",
	"westdown":     "西边",
	"northeast":    "东北面",
	"northwest":    "西北面",
	"southeast":    "东南面",
	"southwest":    "西南面",
	"up":           "上面",
	"down":         "下面",
	"enter":        "里面",
	"out":          "外面",
	"leitai":       "擂台上面",
]);

static mapping empty_mapping = ([ ]);

void create() { seteuid(getuid()); }

int drop_things(object me)
{
	int i,max;
	object *inv;
	object env;
	env = environment(me);
	max = me->query_max_encumbrance();
	inv = all_inventory(me);
	for( i = 0; i < sizeof(inv); i ++ ){
		if(inv[i]->query("equipped")
		|| inv[i]->query("no_drop")
		|| inv[i]->query("no_get_from")) continue;
		if(random(max) < inv[i]->weight()){
			tell_object(env,"慌乱之中，");
			DROP_CMD->main(me, inv[i]->query("id"));
		}
	}
}
int check_flee(object me, string arg)
{
	object *enemy;

	enemy = me->query_enemy();
	if( objectp(enemy[0]) && environment(enemy[0])== environment(me) && living(enemy[0]))
		if(2 + random((int)me->query_dex()) <=  random((int)enemy[0]->query_dex())){
			if(!me->is_busy()) me->start_busy(1);
			message_vision(YEL "$N向" + arg + "逃去！\n" NOR, me);
			message_vision(RED "$N身影一闪，挡在了$n的面前！\n" NOR, enemy[0], me);
			return 0;
	}
	return 1;
}
int main(object me, string arg)
{
	string dest, mout, min, dir,hname,thing_msg;
	object env,obj,thing;
	object *enemy,*ob;
	int result;
	int i, count = 0;
	mapping exit;
	mapping my;
	mapping my_env, my_armor,my_weapon;

	if( !arg )
		return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced())
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");

	if( me->query("jing") <= 10)
		return notify_fail("你太累了，休息一下再走吧。\n");

	env = environment(me);

	if(!env) 
		return notify_fail("你哪里也去不了。\n");

	result = env->valid_leave(me, arg);
	if ( result < 0 ) return 1;
	else if ( !result ) return 0;

	my = me->query_entire_dbase();

        my_env = my["env"];
        if(! my_env) my_env = empty_mapping;

	my_weapon = me->query_temp("weapon");
	if(!my_weapon) my_weapon = empty_mapping;

	my_armor = me->query_temp("armor");
	if(!my_armor) my_armor = empty_mapping;

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb() == "go"){
			if(my["age"] > 18){
				me->receive_damage("jing",10);
			}
				return notify_fail("你硬生生的往墙上撞去，这才发现这个方向并没有出路。\n");
		}
		else {
			return 0;
		}
	}
	dest = exit[ arg ];
	if(!(obj = find_object(dest)))
		if(!objectp(obj=load_object(dest))){
			log_file("go_error",sprintf("无法在[%s]找到[%s]，方向为[%s]。\n",
				base_name(environment(me)),dest,arg));
			CHANNEL_D->do_channel(find_object(SEC_OB),"debug",
				sprintf("无法在[%s]找到[%s]，方向为[%s]。\n",base_name(environment(me)),dest,arg));
			return notify_fail(WHT"发现错误连接而无法移动，请转告巫师。\n"NOR);
	}
	if(!wizardp(me) && userp(me) && me->query_temp("is_riding") &&
		(arg=="up" || arg=="down" || arg=="leitai" || arg=="enter" || arg=="out"))
		return notify_fail("这个方向没法骑在座骑上过去。\n");
	
// 移动前方是否太挤? 擂台上不超出2人
	if((int)dest->query("fight_room")
	|| (int)dest->query("force_room") ){
		ob = all_inventory(obj);
		for(i=0; i<sizeof(ob); i++)
			if( living(ob[i]) && userp(ob[i]) && ob[i] != me)
				count++;

	if((int)dest->query("force_room") && count >= 3  )
		return notify_fail("那里的人太多了，你怎么也挤不进去。\n");
	else if(count>2)
		return notify_fail("擂台上人太多了，你怎么也挤不上去。\n");
	}

	if((dest->query("no_fight") || dest->query("no_steal") 	|| dest->query("sleep_room")
	|| dest->query("playerhouse") || dest->query("fight_room"))
	&& !dest->query("parsion_room")	&& me->query_condition("killer"))
		return notify_fail("官府还在通缉你，"+ dest->short()+"可不是你的避难所。\n");

	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		if(check_flee(me, dir) == 0) {
			return notify_fail("你被挡了回来。\n");
		}
		enemy = me->query_enemy();
		if(objectp(enemy[0]) && environment(enemy[0]) == environment(me) && living(enemy[0]))
		{
			drop_things(me);
			mout = "往" + dir + "落荒而逃了。\n";
			min  = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
		}
	}
		if(objectp(thing = my_armor["cloth"]))
			thing_msg = "身着" + thing->name();
		else
		if(userp(me))
			thing_msg = "赤身裸体的";
		else
			thing_msg = "";

		if(objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->name();

		if(my["race"] == "禽兽")
		{
			mout = "呼地往" + dir + "一窜就消失了。\n";
			min = "呼地窜了出来，警惕地四周张望着。\n";
		}
		else if (my["race"] == "飞禽" || my["subrace"] == "飞虫")
		{
			mout = "啪嗒啪嗒的往" + dir + "飞走了。\n";
			min = "啪嗒啪嗒的飞了过来。\n";
		}
		else
		{
			if(stringp(hname =  me->query_temp("is_riding")))
			{
				mout = "骑着"+ hname +"朝" + dir + "疾驰而去。\n";
				min =  "骑着"+ hname +"一路疾驰而来。\n";
			}
			else
			if ( arg == "leitai")
			{
				mout = "双腿力蹬，纵起身形，轻轻跃上擂台。\n";
				min = "从擂台下一跃而起，稳稳地落在台上。\n";
			}
			else
			if(me->query_condition("killer"))
			{
				mout = "神色慌张的往"+ dir +"离开了。\n";
				min = "神色慌张的走了过来。\n";
			}
			else
			if (me->is_fighting()) {
				mout = "往" + dir + "落荒而逃。\n";
				min  = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
			}
			else
			{
				mout = "往" + dir + "离开了。\n";
				min =  thing_msg + "走了过来。\n";

			}
		}

	me->remove_all_enemy(1);
	me->delete_temp("pending");

	if(!my_env["invisibility"]  && !me->query_temp("apply/shade_vision"))
		message( "vision",me->name() + mout, environment(me), ({me}) );

	me->move(dest);

	if(!my_env["invisibility"]  && !me->query_temp("apply/shade_vision"))
		message( "vision", me->name() + min, environment(me), ({me}) );

	if(environment(me) != env)
		all_inventory(env)->follow_me(me, arg);
		return 1;

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
	);
	return 1;
}
