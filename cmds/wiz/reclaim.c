// reclaim.c

int main(object me, string arg)
{
	object *ob = filter_array(objects(), (: clonep :));
	int mem;

	write("整理结果，共清除 " + reclaim_objects() + " 个变数。\n");
	mem = sizeof(ob);
	while (mem--)
	if (!environment(ob[mem]) 
	&& !interactive(ob[mem]) 
	&& !ob[mem]->query_temp("body_ob")
	&& !ob[mem]->query_temp("link_ob")
	&& !ob[mem]->query("virtual_room")) {
		reset_eval_cost();
		write(sprintf("%O\n", ob[mem]));
		destruct(ob[mem]);
		ob -= ({ 0 });
		mem = sizeof(ob);
	}
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : reclaim

用处 : 将存在於记忆体里无用的变数清除掉, 以减少记忆体的使用。
HELP
     );
     return 1;
}
