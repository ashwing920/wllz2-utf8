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

		if(undefinedp(channel[ch_name]) && ch_name != "all")
			return notify_fail("没有 "+ ch_name +" 这个频道。\n");

		if(ch_name == "all" && !ob->query("chblk/all"))
			return notify_fail((string)ob->query("name") + "的没有被关闭所有频道。\n");
		
		if(!(int)ob->query("chblk/"+ ch_name))
			return notify_fail((string)ob->query("name") +"的"+ channel[ch_name]["name"] +"频道已经是打开的。\n");
		
		if(ch_name == "all"){
			ob->set("chblk/all",0);
			write((string)ob->query("name") +"的所有频道被打开了。\n");
			message_system("由于表现良好，系统将"+ ob->name(2) +"的所有聊天频道打开了。");
		}
		else {
			ob->set("chblk/"+ ch_name,0);
			write((string)ob->query("name") +"的"+ channel[ch_name]["name"] +"频道被打开了。\n");
			message_system("由于表现良好，系统将"+ ob->name(2) +"的聊天频道打开了。");
		}
		ob->apply_condition("be_chblk",0);
		return 1;
	}
	else if(sscanf(arg,"%s",who) == 1){
		if(undefinedp(channel[who]))
			return notify_fail("没有 "+ who +" 这个频道存在。\n");
		if(!channel[who]["block"])
			return notify_fail(channel[who]["name"]+"频道是打开着的。\n");
		if(CHANNEL_D->set_block(who,0)){
			CHANNEL_D->do_channel(find_object(SEC_OB),"sys",channel[who]["name"] +"频道被"+ me->name(1) +"["+ geteuid(me)+"]打开了。");
			return 1;
		}
	}
}

int help(object me)
{
	write(@HELP
指令格式：
	  unchblk <某人> <频道名>	开启某人的某个频道
	  unchblk <频道名>		开启全体人员的某个频道
	  
<频道名>：可以是rumor、chat、wllz或者all。

HELP
);
	return 1;
}
