// purge.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() {	seteuid(getuid());}

int help(object me)
{
write(@HELP
指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>

清除一个使用者或清除超过一定天数不曾上线地使用者。
HELP
	);
	return 1;
}

private int do_purge_players(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;
	object player,npc;

	status = wizhood(me);
	if( me!=this_player(1)|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");
	if( !arg ) return help(me);

	if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return help(me);

	seteuid(getuid());
	if(SECURITY_D->get_status(name) == "(admin)")
		return notify_fail("你没有权利使用这个命令。\n");
	if((string)SECURITY_D->get_status(name)!="(player)")
		return notify_fail("你无法删除这个使用者的资料。\n");
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("没有这位使用者。\n");

/* 读取玩家资料档，读取玩家名字并从玩家名字数据库中删除。 by robert */

	player = new(LOGIN_OB);
	player->set("id", name);
	player->restore();
	PNAME_D->del_name(name,player->query("name"));
	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + SAVE_EXTENSION);

/* 删除资料档并清除临时呼叫的 LOGIN_OB 。 by robert */

/* 删除武林盟主和其他使者可用的记录。*/
	npc = find_living("wulin mengzhu");
	if(!npc) npc = load_object("/clone/npc/meng-zhu");
	if((string)npc->query("winner") == (string)player->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}
	npc = find_living("shangshan shizhe");
	if(!npc) npc = load_object("/clone/npc/shang-shan");	
	if((string)npc->query("winner") == (string)player->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}
	npc = find_living("fae shizhe");
	if(!npc) npc = load_object("/clone/npc/fa-e");
	if((string)npc->query("winner") == (string)player->query("id")){
		rm(npc->query_save_file() + __SAVE_EXTENSION__);
		destruct(npc);
	}
	destruct(player);

	message_system(sprintf("使用者 %s 被管理员%s删除了！",capitalize(name),me->name(2)));
	log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

private int do_purge_players(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	object who;

	if(day<30) return notify_fail("天数应该大于30。\n");
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
	if(who->query("regforever")) continue;
		if( (time()-who->query("last_on"))/86400 >= day ) {
			rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
			rm(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j]);
			PNAME_D->del_name(name,who->query("name"));
			write(" "+name);
			count ++;
	}
			destruct(who);
		}
			write(" 被清除掉了。\n");
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write( count + " 个超过 " + day + " 天未上线的使用者被清除掉了。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	log_file("static/PURGE",sprintf("[%s] %s 清理了 %d 个超越 %d 天没有登陆的玩家资料，剩余 %d 个玩家资料存在。\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));
	LOGIN_D->set_lock(0);
	return 1;
}

