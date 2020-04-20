// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,twine,ob;
	int total,bad;
	
	if(!arg || arg == "")
		return notify_fail("指令格式：mend <衣物>\n");
	
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if((int)me->query_skill("tailor",1) < 50)
		return notify_fail("你的缝纫之技还不够娴熟，别把人家的衣服搞坏了。\n");
	
	if(!present("xiuhua zhen",me) || !objectp(twine = present("twine",me)))
		return notify_fail("你手里没有针线，总是觉得不够顺手。\n");

	if((int)me->query("jing") < 100 || (int)me->query("qi") < 100)
		return notify_fail("你现在的精神太差了，不适合做修补。\n");

	if(!objectp(obj = present(arg,me)))
		return notify_fail("你要修补什么？\n");

	if(!obj->query("armor_prop"))
		return notify_fail(obj->name()+"怎么能用针线修补呢？\n");
/*
	if(!obj->query("ownermake"))
		return notify_fail(obj->name()+"不需要进行修补。\n");
*/
	bad = (int)obj->query("armor_prop/bad");

	if(bad <= 0)
		return notify_fail(obj->name()+"完好无损，看起来不需要进行修补。\n");

	if((string)obj->query("armor_master") == (string)me->query("marry"))
		total = (int)me->query_skill("tailor",1);
	else
		total = (int)me->query_skill("tailor",1) /2;
		
	me->add("qi",-100);
	me->add("jing",-100);
	message_vision("$N一手捧着"+ obj->name()+"，一手拿着针线，仔细的缝补着"+ obj->name()+"上的创口。\n",me);

	obj->add("armor_prop/bad",- total);
	if(ob = find_player(obj->query("armor_master")))
	ob->add("armor/bad",- total);

	if(obj->query("armor_prop/bad") < 0){
		obj->delete("consistence");
		obj->set("armor_prop/bad",0);
		if(ob = find_player(obj->query("armor_master")))
		ob->set("armor/bad",0);
		message_vision(obj->name()+"看起来好像已经完美如初了。\n",me);
	}

	twine->add("use_time",- total/10);
	if(twine->query("use_time") <= 0){
		tell_object(me,"线已经用完了。\n");
		destruct(twine);
	}
	me->start_busy(2);
	return 1;
}

int help(object me)
{
     write(@HELP

指令格式：mend

这是配合技能“缝纫之技”所使用的缝补指令，女玩家可以使用这个指令来帮助其
他玩家修补防具，修补防具的速度与缝纫之技和是否为夫妻的有一定的关系。

配合使用物品：绣花针、线。

HELP
	);

	return 1;
}
