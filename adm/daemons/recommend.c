// voted.c
// 投票系统

//#pragma optimize
//#pragma save_binary

#define SAVE_FILE	DATA_DIR +"voted"

inherit F_SAVE;
inherit F_DBASE;

mapping vote=([ ]);

void create()
{
	seteuid(ROOT_UID);
	restore();
}
void reset(){ save();}

void mud_shutdown(){ save();}

string query_save_file(){ return SAVE_FILE;}

int add_vote(string victim_id,string me_id)
{
	if(stringp(victim_id) && stringp(me_id)){
		if(!vote[victim_id]) vote[victim_id] = 1;
		else vote[victim_id] += 1;
		write("投票完成。\n");
	}
	save();
	restore();
	return 1;
}
int query_vote(string id,string type)
{

	if(!vote[id]) {
		write("目前没有人投你的票。\n");
		return 0;
	}
	if(!type){
		write("你目前已经获得推荐票数："+ vote[id] +" 票。\n");
		return 1;
	} else return vote[id];
}
