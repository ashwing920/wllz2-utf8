// kantou.c

#include <ansi.h>
inherit F_CLEAN_UP;

int do_kan(object me, object ob, object weapon);

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, weapon;

	if( !arg ) return notify_fail("你要砍谁的头？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你还不会空手入白刃，无法挥手如刀！\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你只能砍尸体的头。\n");

	if(userp(obj) || living(obj) )
		return notify_fail("那还是活的！先杀了才能砍头！\n");
	
	if( me->is_fighting() ) 
		return notify_fail("你还在战斗中！还想砍人家的头？\n");

                if(obj->query("killer") != me->query("name"))
		return notify_fail("不是你杀的！还想砍什么头？\n");

	if(obj->query("kantou"))
		return notify_fail(obj->name()+"的头早已被砍断了。\n");
	
	if(obj->query("bone"))
		return notify_fail(obj->name()+"的颈骨早已经被打断了。\n");
	
	if(weapon->query("skill_type") != "sword"
	&& weapon->query("skill_type") != "blade"){
		message_vision( "$N挥起"+weapon->query("name")+"朝$n的颈部打去，只听见“啪嗒”的一声骨碎，$n的颈骨被打断了。\n", me, obj );
		obj->set("bone",1);
		return 1;
	}

	return do_kan(me, obj, weapon);
}

int do_kan(object me, object obj, object weapon)
{
	object newob;
	string newname;

	if( !obj ) return 0;
	if (obj->query("kantou") == 1)
	{
		message_vision( "$N是个无头尸。\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if(strsrch(newname, "腐烂的尸体") >= 0)
	{
		message_vision( "腐尸还砍个啥劲呀。\n", obj );
		return 1;
	}
	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "头颅");
	else
	{
		message_vision(obj->query("name")+"有什么头可砍的。\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob->set("name",HIR+newname+NOR);
	newob->move(me);
	if( me->is_fighting()) me->start_busy(1);

	if(weapon->query("skill_type") == "blade")
	message_vision("$N挥起"+weapon->query("name")+"，手起刀落，将$n的脑袋砍了下来，鲜血流了满地。\n", me, obj );
	else if(weapon->query("skill_type") == "sword")
	message_vision("$N舞了一个剑式，手中"+weapon->query("name")+"朝$n的颈部挥去，将$n的脑袋割了下来。\n", me, obj );

	if(obj->query("killer") == me->query("name")){
		newob->set("last_damage_from",me);
	}
	obj->set("kantou", 1);
	newname = obj->query("name");
	if(strsrch(newname, "尸体") >= 0)
	//newname = replace_string(newname,"尸体","无头尸体");
	switch(obj->query("gender"))
	{
	case "男性":
		newname="无头男尸";
		break;
	case "女性":
		newname="无头女尸";
		break;
	default:
		newname="性别不明的尸体";
		break;
	}
	obj->set("name", newname);
	obj->set("id","corpse");
	obj->set("long","这是一具"+ newname +"，死状恐怖，脖子还淌着鲜血。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kantou <尸体名称>

这个指令可以让你砍下地上死者的头颅.

HELP
    );
    return 1;
}
