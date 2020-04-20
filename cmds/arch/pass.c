// ban.c

int help(object me);

void create(){ seteuid(getuid());}

int main(object me,string arg)
{
        object ob, body;
        string id;

	if(!arg) {
		BAN_D->print_pass_id();
		return 1;
	}
	else if(sscanf(arg,"+ %s",id) == 1){
        	if( objectp(body = find_player(id)) && geteuid(body)==id )
                	return notify_fail("你只能在玩家离线时才能进行操作。\n");

        	ob = new(LOGIN_OB);
        	ob->set("id", id);
        	if (!ob->restore()){
        		write("没有这个玩家。\n");
        		destruct(ob);
                	return 1;
		}
		else {
			if(ob->query("passed_ids")){
				write(ob->query("name") +"已经拥有了多重登陆权限。\n");
				destruct(ob);
				return 1;
			}
			write("你为" + ob->query("name") +"开放了多重登陆权限。\n");
			CHANNEL_D->do_channel(find_object(SEC_OB),"sys",
				sprintf("%s[%s]为%s开放了多重登陆权限。",me->name(1),geteuid(me),ob->query("name")));
			BAN_D->add_pass_id(id);
			ob->set("passed_ids",1);
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	else if(sscanf(arg,"- %s",id) == 1){
        	if( objectp(body = find_player(id)) && geteuid(body)==id )
                	return notify_fail("你只能在玩家离线时才能进行操作。\n");

        	ob = new(LOGIN_OB);
        	ob->set("id", id);
        	if (!ob->restore()){
        		write("没有这个玩家。\n");
        		destruct(ob);
                	return 1;
		}
		else {
			if( !ob->query("passed_ids")){
				write(ob->query("name") +"没有多重登陆权限。\n");
				destruct(ob);
				return 1;
			}

			write("你取消了" + ob->query("name") +"的多重登陆权限。\n");
			CHANNEL_D->do_channel(find_object(SEC_OB),"sys",
				sprintf("%s[%s]取消了%s的多重登陆权限。",me->name(1),geteuid(me),ob->query("name")));
			BAN_D->remove_pass_id(id);
			ob->delete("passed_ids");
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	else return help(me);
}

int help(object me)
{
        write(@HELP
指令格式：pass                  显示所有开放特殊ＩＰ地址的ID。
          pass + | - id		增加／移除开放特殊ＩＰ地址的ID。

开放特殊的ＩＰ地址给予网吧登陆的ID使用。

关联信息：ban
HELP
        );

        return 1;
}
