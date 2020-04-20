// user.c

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

static int user_say = 0;                // 一定时间以内玩家做的say-action
static int user_command = 0;            // 一定时间以内玩家发送的命令
static int at_time = 0;                 // 在什么时间计算的
static int ban_to = 0;                  // 在什么时间解禁玩家
static int attach_flag = 0;             // 是否正在和系统联络
static int idtime = 0;

#define MAX_COMMAND_ONE_SECTION         40
#define MAX_SAY_ONE_SECTION             5
#define BAN_SAY_PERIOD                  60

static int last_age_set;

int is_player()	{ return clonep(); }

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	if((int)query("potential") - (int)query("learned_points") < 100)
		add("potential",1);

	if((int)query("thief") > 0)
		add("thief", -1 );
}
// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	save_autoload();
	res = ::save();
	clean_up_autoload();            // To save memory
	return res;
}

// This function updates player's age, called by heart_beat()

void update_age()
{
	object ob;
	ob = this_object();

	if(!environment()) return;

	if(interactive(ob) && ob->query("env/idle") 
	&& query_idle(ob) > 300 ){
	int skill = (int)ob->query_skill("idle-force",1);
		if(idtime > (skill+1) * (skill+1)) {
			set_skill("idle-force",skill + 1);
			tell_object(ob,HIY"你的「发呆神功」进步了！\n"NOR);
			idtime = 0;
		}
		else idtime += 1;
	}

	if(environment(ob)->query("chat_room") ) {
		last_age_set = time();
		return;
	}
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));

}
void breakup()
{
	if(userp(this_object()) && query_temp("breakup")){
		if((query("potential") - query("learned_points")) > 1){
			add("learned_points",1);
			add_temp("breakup_time",1);
		}else command("quit");
		if( random(300) == (query("con") + query("spi")) && query_temp("breakup_time") > 86400){
			set("breakup",1);
			log_file("breakup",sprintf("[%s]%s(%s)打通任督二脉，破关而出。\n",ctime(time()),query("name"),query("id")));
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
				sprintf("%s，%s终于打通任督二脉，破关而出！",NATURE_D->game_time(),name(2)));
			save();
			command("quit");
		}
	}
}
void closed()
{
	string *c_skill,skill;
	int lvl,i;

	if(sizeof(c_skill) < 1)  //如果闭关武功设置为空的数据，重新载入闭关武功
		c_skill = query("close_skill");

	if(sizeof(query("close_skill")) < 1) { // 如果无法载入闭关武功，则离开游戏。
		save();
		command("quit");
	}
	
	if(!skill){		// 开始检测所有武功，抽出当中一种
		for(i=0;i<sizeof(c_skill);i++)
			skill = c_skill[i];
	}
	
	lvl = query_skill(skill,1); // 将要修炼的武功当前级别
	
	if((query("potential") - query("learned_points")) > 40 - query("int")){
		if((lvl * lvl * lvl) / 10 < query("combat_exp")){
			improve_skill(skill,random(query_int()));
			add("learned_points",1 + (int)SKILL_D(skill)->learn_hard());
		}
		else {
			set("close_skill",c_skill - ({ skill }));
			c_skill = ({  });
			skill = "";
		}
	}
	else {
		save();		
		command("quit");
	}
}
void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}
private void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
			command("quit");
			break;
		case DUMP_IDLE:
			if(environment(this_object()) && !this_object()->in_input() &&
				( wizardp(this_object()) || environment()->query("chat_room"))) return;
			tell_object( this_object(), "对不起，您已经发呆超过 " + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
			tell_room( environment(), query("name") + "似乎明白了些什么，恍然大悟：哦，原来是这样子。\n", ({this_object()}));
			command("quit");
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	if(query_temp("breakup") || query_temp("closed")){
		set_temp("biguan",1);
		return;
	}
	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )  {
		if(!link_ob->is_character()) {
			link_ob->set("last_on", time());
			link_ob->set("last_from", query_ip_name(this_object()));
			link_ob->save();
		}
		destruct(link_ob);
	}

	if (!environment()) {
		destruct(this_object());
		return;
	}

	remove_all_enemy(1);
	set_temp("netdead", 1);
	if( userp(this_object())) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
		tell_room(environment(), query("name") + "断线了。\n", this_object());
	} else {
		command("quit");
	}
}
// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	if(query_temp("netdead")){
		set_heart_beat(1);
		set_temp("netdead",0);
		remove_call_out("user_dump");
		tell_object(this_object(), "重新连线完毕。\n");
	}
	else if(query_temp("biguan")){
		if(query_temp("breakup")){
			delete_temp("breakup");
			delete("breakup");
			tell_object(this_object(),"你终于忍耐不住，破关而出，先前的修行也荒废了。\n");
		}
		else if(query_temp("closed")){
			save();
			delete_temp("closed");
			tell_object(this_object(),"你修行完毕，气力回收，缓缓的站了起来。\n");
		}
		delete_temp("biguan");
	}
}
int reject_command()
{
	int t;

	if(!this_object()) return 0;
	if (wizardp(this_object())) return 0;

	t = time() & 0xFFFFFFFE;
	if (at_time != t)
	{
		at_time = t;
		user_command = 1;
		user_say = 0;
	} else
		user_command++;

	if (user_command > MAX_COMMAND_ONE_SECTION)
		return 1;

	return 0;
}
int ban_say()
{
	int t;

	if(!this_object()) return 0;
	if(wizardp(this_object())) return 0;

	t = time() & 0xFFFFFFFE;
	if( query_temp("ban_times") > 4)
	{
		write("由于你一再的滥用指令，系统不再接受你任何指令了。\n");
		command("quit");
	}
	if (ban_to > t)
	{
		notify_fail("系统禁止你送出信息，请于" +chinese_number(ban_to - t) + "秒钟以后再尝试。\n");
		return 1;
	}
	if (at_time != t)
	{
		at_time = t;
		user_say = 1;
		user_command  = 0;
	} else
		user_say++;

	if (user_say > MAX_SAY_ONE_SECTION)
	{
		add_temp("ban_times",1);
		ban_to = t + BAN_SAY_PERIOD * query_temp("ban_times");
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "因为太罗嗦，被人堵住了嘴。");
		notify_fail("由于你发布的信息太多，因此系统暂时禁止你发出信息。\n");
		return 1;
	}

	return 0;
}
int is_attach_system()
{
	return attach_flag;
}
// start attaching
int attach_system()
{
	attach_flag = 1;
}

// stop, deatched
int detach_system()
{
	attach_flag = 0;
}

int max_neili() 
{
	int spi;
	spi = this_object()->query("spi");
	if(spi > 30) spi = 30;
	if(spi < 15) spi = 16;
	if(this_object()->query("breakup")) 
		return this_object()->query_skill("force") * spi;
	else
		return this_object()->query_skill("force") * 15;
}
int max_jingli()
{
	
	mapping my;
	object ob;
	int max_jingli;

	ob = this_object();
	my = ob->query_entire_dbase();

	if( mapp(my["family"])
	&& ((my["family"]["family_name"] == "逍遥派" && (int)ob->query_skill("beiming-shengong",1) >= 120)
	|| (my["family"]["family_name"] == "日月神教" && (int)ob->query_skill("xixing-force",1) >= 120)
	|| (my["family"]["family_name"] == "星宿派" && (int)ob->query_skill("huagong-dafa",1) >= 120 ))){
		max_jingli = ((int)ob->query_spi()+(int)ob->query_con()) * 100;
	}
	else {
		if((int)ob->query_skill("buddhism",1)) max_jingli = (int)ob->query_skill("buddhism",1) * 10;
		else if((int)ob->query_skill("taoism",1)) max_jingli = (int)ob->query_skill("taoism",1) * 10;
		else if((int)ob->query_skill("lamaism",1)) max_jingli = (int)ob->query_skill("lamaism",1) * 10;
		else if((int)ob->query_skill("mahayana",1)) max_jingli = (int)ob->query_skill("mahayana",1) * 10;
		else if((int)ob->query_skill("poison",1)) max_jingli = (int)ob->query_skill("poison",1) * 10;
		else max_jingli = 0;
	}
	if(query("breakup")) max_jingli += (int)ob->query("spi") * 100;
	return max_jingli;
}
