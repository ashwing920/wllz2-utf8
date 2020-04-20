// far-vision.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
	object newsheet;
	int t;

	if((int)me->query_skill("blackart") < 50 )
		return notify_fail("你的符之术不够高！\n");

	if( sheet->name() != "桃符纸" ) 
		return notify_fail("天通眼符要画在桃符纸上！\n");

	if( (int)me->query("jingli") < 5 ) 
		return notify_fail("你的法力不够了！\n");

	t = (int)sheet->query_amount();
	if( t == 1 ) destruct(sheet);
	else sheet->set_amount(t - 1);
	me->save();
	seteuid( geteuid(me));
	newsheet = new("/clone/misc/magic_seal");
	newsheet->set_name(YEL "天通眼符" NOR, ({ "far-vision sheet", "sheet"}));      
	newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
	newsheet->move(me);
	me->add("jingli", -5);
	me->receive_damage("jing",5);
	me->save();
	message_vision("$N写了一道天通眼符。\n" NOR, me);
	return 1;
}

int do_burn(object sheet)
{ 
	string target;
	object obj;

	if( !(sheet->query("targetname")) )
		return notify_fail("你想用这道符" NOR "看哪里？\n");
	message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() +
		"着了起来！\n", this_player());
	this_player()->receive_damage("jing", 5);
	target = sheet->query("targetname");
	obj = find_player(target);
	if(!obj) obj = find_living(target);
	if(!obj) {
		message("vision", "你感到眼睛酸酸的，却什么也没看到！\n", this_player());
	} else
	{
		message("vision", "在闪烁的火光中，你看到：\n", this_player());
		"/cmds/std/look"->look_room(this_player(), environment(obj));
		message("vision", "\n\n你感到脖子发凉，黑暗处好像有双眼睛盯着你！\n\n", obj);
		message("vision", "你仔细地看了一下四周，却什么也没有！\n", obj);
	}
	return 1;
}
