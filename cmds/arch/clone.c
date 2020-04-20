// clone.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string err,msg,str,file;
	string filegold,filesilver,filecoin;
	int times;
	filegold="/clone/money/gold.c";
	filesilver="/clone/money/silver.c";
	filecoin="/clone/money/coin.c";

	if( !arg )
		return notify_fail("指令格式: clone <事物> <个数> \n");

	if((string)SECURITY_D->get_status(me) != "(admin)" 
	&& (string)SECURITY_D->get_status(me) != "(arch)")
		return notify_fail("你没有足够的权利使用这个指令。\n");

	if (sscanf(arg, "%s %d", file, times) != 2){
		file = arg;
		times = 1;
	}
	seteuid( geteuid(me) );
	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要复制什麽物件？\n");

	file = resolve_path(me->query("cwd"), file);
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	me->set("cwf", file);

	if( file_size(file) < 0 ||  !(int)SECURITY_D->valid_read(file,me))
		return notify_fail("没有这个档案(" + file + ")。\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("载入失败：" + err + "\n");
			return 1;
		}
	}

	err = catch(obj = new(file));
	if (err) {
		write("复制失败：" + err + "\n");
		return 1;
	}
	
	 if ((!(file==filegold) && !(file==filesilver) &&
		 !(file==filecoin)) && (times>10))
	{
		return notify_fail("STOP！STOP！最多只能复制10个单位！\n");
	}
	else
		if (times>100)
		{
			return notify_fail("你真是财迷心窍，金钱最多只能复制100个单位！\n");
		}         
	
	if( !stringp(msg = me->query("env/msg_clone")) )
		msg = "只见$N伸手凌空一指，变出了$n。\n";
		str = me->name(2)+"复制了" + times + "个" + obj->name(2) + ctime(time())+ "。\n";
		write_file("/log/static/CLONE", str);  
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",me->name(2)+"复制了" + 
			times + "个" + obj->name(2));


	if (!obj->is_character()){
		for (int i = times;i>0;i--) {
		obj = new(file);
		obj->move(me,1);
	}
		write(times + "个" +obj->query("name") + "复制成功，放在你的物品栏。\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	for(int j = times; j>0; j--) {
		obj=new(file);
		obj->move(environment(me));
	}
		write(times + "个" + obj->query("name") + "复制成功，放在这个房间。\n");
		message_vision(msg + "\n", me, obj);
		return 1;

	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : clone <档名> <数量>

利用此指令可复制任何能移动之物件（含怪物），不能超过10个单位，
金钱不能超过100个单位。
HELP
	);
	return 1;
}

string short_help()
{
	return "复制物件";
}
