// questd.c
// TASK系统

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

string *quests;
string *roomlines;
mapping maps;
mapping maping_tasks;
object *target=({});

varargs void init_dynamic_quest(int hard);
varargs int spread_quest(string one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
int locate_quest(object me,string arg);
string dyn_quest_list();
string query_city(object loc);

void create()
{
	string file,dir,name;
	string* buf1;
	int i,size;
	maps=([]);

	file = read_file("/d/obj/quest/dynamic_location");
	roomlines = explode(file,"\n");
	file = read_file("/d/obj/quest/dynamic_quest");
	quests = explode(file,"\n");
	file = read_file("/adm/etc/map/place.map");
	buf1 = explode(file,"\n");
	size=sizeof(buf1);
	if(!size) return;

	for(i=0;i<size;i++) {
	if(sscanf(buf1[i],"%s %s",dir,name)==2) {
		name=replace_string(name," ","");
		if(strlen(dir)>1 && strlen(name)>1) {
		maps+=([dir:name]);
		//rite(sprintf("room:(%s) city:(%s)\n",dir,maps[dir]));
			}
		}
	}
	CRON_D->set_last_hard_dis();
	init_dynamic_quest(1);
	seteuid(getuid());
	set("channel_id", "使命精灵");
}

int quest_reward(object me, object who,object quest_item)
{
	int exp,pot,score;

	if(who->query("name")!= quest_item->query("owner_name")
	|| who->query("id")!= quest_item->query("owner_id")) return 0;
	exp = 200 + (random(me->query("kar")) * 5) + (random(me->query("int")) * 5);
	if(exp > 500) exp = 500;
	pot = exp/3*2;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	CHANNEL_D->do_channel(this_object(),"debug",sprintf("%s找到%s交还给%s，得到经验：%d，潜能：%d",
	me->name(),quest_item->query("name"),who->name(),exp,pot));
	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("听说%s帮%s找到了"HIM"%s"HIM"，得到了一些奖励。"NOR,
		me->name(),who->name(),quest_item->query("name")));

	message_vision("\n$N高兴的对$n连连点头：好，好！太感谢你了！\n",who,me);
	tell_object(me, sprintf(HIM"恭喜！你获得了%s的经验值，%s点潜能的奖励！\n"NOR, chinese_number(exp),chinese_number(pot)));
	score=me->query_temp("dynamic_find");
		if(score+1==15){
		me->delete_temp("dynamic_find");
		me->add("combat_exp",1000);
		me->add("weiwang",100);
		tell_object(me,HIW"┌──────────────────────────┐\n"+
				"│"HIY"由于你连续的完成了任务："HIW"                            │\n"+
				"│"HIY"你得到了一千点武学经验的附加奖励！                 "HIW" │\n"+
				"│"HIY"你的江湖威望增长了一百点！                    ^o^  "HIW" │\n"+
				 "└──────────────────────────┘\n\n"NOR);
	}
	else me->set_temp("dynamic_find",score+1);
	destruct(quest_item);
	return 1;
}

varargs void init_dynamic_quest(int hard)
{
	int i;
	for( i=0; i < sizeof(quests)/2; i++)
		spread_quest(quests[i*2],hard);
}

varargs int spread_quest(string quest, int hard)
{
	object obj0;
	object cur_obj;
	object tar;
	object *inv;
	object *target=({});
	int i;
	string location;
	if(already_spreaded(quest,hard)) return 0;
	reset_eval_cost();
	location = roomlines[random(sizeof(roomlines))];
	obj0=find_object(location);
	if(obj0)
		obj0->reset();
	else
		obj0=load_object(location);
		cur_obj =obj0;

	if(cur_obj){
		inv = all_inventory(cur_obj);
		for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->is_character() && !userp(inv[i]))
		target += ({ inv[i] });
		if(inv[i]->is_container()) target += ({ inv[i] });
		}
	}
	if(sizeof(target)) cur_obj = target[random(sizeof(target))];
	if(cur_obj){
		tar = new(quest);
		tar->set("value",0);
		tar->move(cur_obj);
	}
	return 1;
}
string dyn_quest_list()
{
	string output;
	object item;
	int i;

	output="";
	for( i=0; i < sizeof(quests)/2; i++){
	if(!objectp(item= find_object(quests[i*2])))
		item = load_object(quests[i*2]);
	if(already_spreaded(quests[i*2]))
		if(random(2))output += sprintf("%-6s%4s%-4s%-12s\n",item->query("owner_name"),"－","－",item->short(1));
		else output=sprintf("%-6s%4s%-4s%-12s\n",item->query("owner_name"),"－","－",item->short(1))+output;
	else
		if(random(2))output += sprintf("%-6s%4s%-4s%-12s（"HIW"已完成"NOR"）\n",item->query("owner_name"),"－","－",item->short(1));
		else output=sprintf("%-6s%4s%-4s%-12s（"HIW"已完成"NOR"）\n",item->query("owner_name"),"－","－",item->short(1))+output;
	}
	output ="───────────────────────────\n"+
		BBLU + HIW"※武林列传使命榜※                      　　　　　 　 \n"NOR+
		"───────────────────────────\n"+output+
		"───────────────────────────\n"+
		BBLU + HIW"　　　　　　　　　　　　　　　　　　　共有"+ chinese_number(i)+"个使命　\n"NOR+
		"───────────────────────────\n\n";

	return output;
}

varargs int already_spreaded(string str,int hard)
{
	object ob,*ob_list;
	int i;
	if(!str) return 0;
	if(hard)
	{
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
		ob=find_env(ob_list[i]);
		if(ob)
		{ ob_list[i]->move(VOID_OB);
		 destruct(ob_list[i]);
		}
	}
	return 0;
	}
	else
	{
	if(!str) return 0;
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
		ob=find_env(ob_list[i]);
		if(ob)
			return 1;
	}
	return 0;
	}
}

object find_env(object ob)
{
	while(ob)
	{
	if(ob->query("exits") ) return ob;
	else ob=environment(ob);
	}
	return ob;
}

int locate_quest(object me, string arg)
{
	object loc;
	string qloc,msg,quest;
	string* exlst;
	object* itemlist;
	mapping exits;
	int index,i;

	if(!arg)
		return notify_fail("zhao <物品id>\n");
	if(present(arg,me))
		return notify_fail("它不正在你的身上吗？\n");
	if((index=member_array(arg,quests,0))>0)quest=quests[index-1];
		else return 1;

	if(!already_spreaded(quest)){
		tell_object(me,"藏宝图上什么也没有显示，仿佛它根本不存在这个世界上。\n");
		return 0;
	}

	itemlist = children(quest);
	for(index=0;index<sizeof(itemlist);index++){
	if(objectp(loc=find_env(itemlist[index]))){
		qloc = query_city(loc);
		exits=loc->query("exits");
		exlst=keys(exits);
		msg=itemlist[index]->query("name")+"仿佛在「"HIG+qloc+NOR"」一处有";
	if(sizeof(exlst)){
		for(i=0;i<sizeof(exlst)-1;i++)
		msg+="「"HIG+ exlst[i]+NOR"」、";
		msg+="「"HIG+exlst[sizeof(exlst)-1]+NOR"」出口的地方。\n";
		tell_object(me,"藏宝图显示："+msg);
		return 1;
			}
		}
	}
	tell_object(me,"藏宝图上什么也没有显示。\n");
	return 1;
}

string query_city(object loc)
{
	string filename,filename1;
	int len;
	filename=file_name(loc);
	len=strlen(filename);
	if(len<2) return "???";

	len--;
	while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return "???";

	filename1=filename[1..(len-1)];
	return maps[filename1];
}

