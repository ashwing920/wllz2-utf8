// purge.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

private void create()
{
	seteuid(getuid());
	set("channel_id", "档案精灵[Data]");
}

int help(object me)
{
write(@HELP
指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>

清除一个使用者或清除超过一定天数不曾上线地使用者。
HELP
	);
	return 1;
}
int main(object me, string arg)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name,newname;
	mixed info;
	object who,ob;

	seteuid(getuid());
	LOGIN_D->set_lock(1);
	write("\n*** 整理玩家储存档中，请稍候.... ***\n");
	write("处理中：\n");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write("目录"+dir[i]+"：玩家\n");
		reset_eval_cost();
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s.o", name)==1 )
				// 如果使用者是巫师，不能删除。
				if( (string)SECURITY_D->get_status(name)!="(player)" ) continue;


	who = new(LOGIN_OB);
	who->set("id", name);
	if(!who->restore()) continue;
	// 如果使用者已经申请永久保留id，不能删除！
			newname = name +"kc";
			cp(DATA_DIR + "login/" + dir[i] + "/" + ppls[j],
			DATA_DIR + "login/" + dir[i] + "/" + newname + ".o");
			cp(DATA_DIR + "user/" + dir[i] + "/" + ppls[j],
			DATA_DIR + "user/" + dir[i] + "/" + newname + ".o");
			cp(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j],
			DATA_DIR + "mail/" + dir[i] + "/" + newname + ".o");
			rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
			rm(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j]);
			write(" "+name);
			count ++;
			destruct(who);
			who = new(LOGIN_OB);
			who->set("id",newname);
			if(!who->restore()) continue;
			if(who->query("id") != newname)
				who->set("id",newname);
				who->save();
			destruct(who);
			ob = UPDATE_D->load_player(newname);
			ob->set_temp("temp_loaded", 1);
			if(ob->query("id") != newname)
			ob->set("id",newname);
			if(ob->query("marry"))
			ob->set("marry",ob->query("marry") +"kc");
			UPDATE_D->global_destruct_player(ob, 1);
		}
			write(" 被清除掉了。\n");
			reset_eval_cost();
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	LOGIN_D->set_lock(0);
	return 1;
}
