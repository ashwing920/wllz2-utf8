//made.c 制作

#include <ansi.h>
inherit F_CLEAN_UP;

private string *what_obj=({
	"木剑",
	"棺材",
	"木刀",
	"木棍",
	"木人",
});
int main(object me, string arg)
{
	object wood;
	int skill,i;
	string what;

	skill = (int)me->query_skill("wooder",1);

	if( skill < 50)
		return notify_fail("你的木匠之技还不够娴熟，做不出什么木具。\n");

	if(environment(me)->query("restrict_action")
	|| environment(me)->query("fight_room"))
		return notify_fail("这里不能做这件事情。\n");

	if( me->query("qi") < 50 || me->query("jing")< 50)
		return notify_fail("你太累了，还是休息一阵再说吧！\n");

	if( me->query_temp("made_wood"))
		return notify_fail("你已经在做木具了！\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting())
		return notify_fail("你正在战斗中！\n");

	if( !arg || sscanf(arg, "%s",what)!=1 )
		return notify_fail("指令格式：made <木具名称>\n");

	if( member_array(what,what_obj) == -1 ){
		for(i=0; i<sizeof(what_obj); i++)
			write(what_obj[i]+" ");
			return notify_fail("\n\n目前你只能做以上那些东西。\n");
		}

	if(!present("xuemu dao",me))
		return notify_fail("你身上没有削木刀，怎么做木具呢？\n");

	wood = present("mu liao",me);
	if( !objectp(wood))
		return notify_fail("你身上没有木料，做什么做？\n");

	if(wood->query_amount() < 2 )
		return notify_fail("你身上的木料不够了！\n");

	message_vision("$N拿起削刀，开始制作"+ what +"！\n",me);
	me->add_temp("mading/"+ what,1);
	me->set_temp("made_wood",1);
	call_out( "compelete_wood",2, me,wood,what);
	return 1;
}

private void compelete_wood(object me,object wood,string what)
{
	int skill,times;
	object obj;

	if(!me) return;
	skill = (int)me->query_skill("wooder",1);

	if(what == "木人") times = 150 - skill;
	else if(what == "棺材") times = 140 - skill;
	else if(what == "木刀") times = 115 - skill;
	else if(what == "木剑") times = 110 - skill;
	else if(what == "木棍") times = 105 - skill;

	if( me->query_temp("mading/"+ what) >= times) {
		message_vision("$N费了九牛二虎之力，终于把"+ what+"给做好了。\n",me);
		switch(what){
			case "木人":
				obj = new("/d/shaolin/npc/mu-ren");
				obj->set_name(me->name()+"做的木人",({ me->query("id")+" muren","mu ren"}));
				obj->set("make_time",time());
				obj->move(me);
				break;
			case "木刀":
				obj = new("/clone/weapon/wood_blade");
				obj->set("name",me->name()+"做的木刀");
				obj->move(me);
				break;
			case "木剑":
				obj = new("/clone/weapon/wood_sword");
				obj->set("name",me->name()+"做的木剑");
				obj->move(me);
				break;
			case "木棍":
				obj = new("/clone/weapon/wood_stick");
				obj->set("name",me->name()+"做的木棍");
				obj->move(me);
				break;
			case "棺材":
				obj = new("/clone/misc/guancai");
				obj->set("name",me->name()+"做的棺材");
				obj->move(me);
				break;
		}
		me->delete_temp("mading");
		me->delete_temp("made_wood");
		me->receive_damage("qi",50);
		me->receive_damage("jing",50);
		return;
	}
	else {
		message_vision("$N小心翼翼的用刀将木料削成型，继续制作"+ what+"。\n",me);
		me->receive_damage("qi",50);
		me->receive_damage("jing",50);
		me->delete_temp("made_wood");
		wood->add_amount(-1);
		return;
	}
	me->delete_temp("made_wood");
	return;
}

int help(object me)
{
write(@HELP

指令格式 : made <木具名称>

如：made 木剑

HELP
	);
	return 1;
}
