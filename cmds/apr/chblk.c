// chblk.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;
	string who,ch_name;
	mapping channel;

	channel = CHANNEL_D->query_channels();
	if(!arg ) return help(me);
	if(sscanf(arg,"%s %s",who,ch_name) == 2){
		ob = LOGIN_D->find_body(who);
		if(!ob)
			return notify_fail("现在没有这个人。\n");

		if(wizardp(ob))
			return notify_fail("不能关闭巫师的频道。\n");

		if(undefinedp(channel[ch_name]) && ch_name != "all")
			return notify_fail("没有 "+ ch_name +" 这个频道。\n");

		if(!wizardp(ob) && channel[ch_name] && channel[ch_name]["wiz_only"] && ch_name != "all")
			return notify_fail("由于"+ (string)ob->query("name")+"不是巫师，不必关闭其巫师专用频道。\n");

		if( ob->query("chblk/all"))
				return notify_fail((string)ob->query("name") + "的所有频道已经都被关闭了。\n");

		if((int)ob->query("chblk/"+ ch_name))
			return notify_fail((string)ob->query("name") +"的"+ channel[ch_name]["name"] +"频道已经是关闭的了。\n");

		if(ch_name == "all"){
			ob->set("chblk/all",1);
			ob->set("chblk/by_wiz",1);
			write((string)ob->query("name") +"的所有频道被关闭了。\n");
			message_system("由于胡言乱语，"+ ob->name(2) +"被系统关闭了所有的聊天频道。");
		}
		else {
			ob->set("chblk/"+ ch_name,1);
			ob->set("chblk/by_wiz",1);
			write((string)ob->query("name") +"的"+ channel[ch_name]["name"] +"频道被关闭了。\n");
			message_system("由于胡言乱语，"+ ob->name(2) +"被系统关闭了聊天频道。");
		}
		ob->apply_condition("be_chblk",600);
		return 1;
	}
	else if(sscanf(arg,"%s",who) == 1){
		if(undefinedp(channel[who]))
			return notify_fail("没有 "+ who +" 这个频道存在。\n");
		if(channel[who]["wiz_only"])
			return notify_fail("你不能关闭巫师专用频道。\n");
		if(channel[who]["block"])
			return notify_fail(channel[who]["name"]+"频道已经是关闭的了。\n");

		CHANNEL_D->set_block(who,1);
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",channel[who]["name"] +"频道被"+ me->name(1) +"["+ geteuid(me)+"]关闭了。");
		write("你将"+ channel[who]["name"] +"频道关闭了。\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式：
	  chblk <某人> <频道名>         关闭某人的某个频道
	  chblk <频道名>                关闭全体人员的某个频道

<频道名>：可以是rumor、chat、wllz或者all。

HELP
);
	return 1;
}
