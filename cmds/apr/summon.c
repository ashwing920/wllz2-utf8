// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;

	if (!str) 
		return notify_fail("指令格式：summon <player id>\n");

	ob = LOGIN_D->find_body(str);
	if (!ob) ob=find_player(str);
	if (!ob) ob=find_living(str);

	if (!ob|| !me->visible(ob)) 
		return notify_fail("咦... 有这个人吗？\n");
	if (ob==me) 
		return notify_fail("哈哈哈... 你能把自己提起来吗？\n");
	if (environment(ob)==environment(me)) 
		return notify_fail(ob->name(1)+"已经在你身边了。\n");

	tell_room(environment(ob),"天空中伸出一只肥肥的大手把"+
	(string)ob->query("name")+"抓了起来，然後不见了。\n", ob);
	tell_object(ob,"一只贼手把你抓了起来, 你眼前一阵黑....\n");
	ob->move(environment(me));
	tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前。\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+"把你弄过来的。\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现在你眼前\n",({me,ob}));

	if(userp(ob) && !wizardp(ob)){
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s[%s]将%s[%s] SUMMON %s[%O]。",
			me->query("name"),geteuid(me),ob->query("name"),ob->query("id"),
			environment(ob)->query("short"),environment(ob)));

		log_file("static/SUMMON",sprintf("[%s]%s将%s SUMMON 到了 %s。\n",
			ctime(time()),me->name(2),ob->name(2),base_name(environment(ob))));
	}
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : summon <某人>
此指令可让你将某人抓到你面前。
HELP
	);
	return 1;
}
