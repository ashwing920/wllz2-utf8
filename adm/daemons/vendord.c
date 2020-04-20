// vendord.c
// 拍卖所

#include <ansi.h>

#define SAVE_FILE	DATA_DIR +"vendor"

inherit F_SAVE;
inherit F_DBASE;

mapping vendor;		// 所有拍卖物品记载

static int time=0;		// 当前叫价次数
static int now_value=0;		// 当前叫价
static int low_value=0;		// 物品底价
static int vendor_now;		// 当前是否正在拍卖
static string bid;		// 当前叫价者的 id
static string vid;		// 拍卖物品者的 id
static string good_desc;	// 当前正拍卖的物品一些信息
static string vmsg;		// 抽选出的拍卖信息

int valid_sell(object ob);
int check_vendor(string id);
int add_vendor(object me,object ob,int value);
int del_vendor(string name,string menu);
//void vendor_status();
void start_vendor();
void remove_vendor();
int sell_to_player(string id,string base_name);
int back_to_player(string id,string base_name);
int player_call_value(object me,int value);

string query_save_file(){ return SAVE_FILE;}
string query_bid(){ return bid;}
string query_vid(){ return vid;}
int query_now_value(){ return now_value;}
int query_low_value(){ return low_value;}
int query_times() { return time;}
int query_vendor_now() { return vendor_now;}
void create()
{
	seteuid(ROOT_UID);
	set("channel_id","拍卖师");
	if(file_size(SAVE_FILE) < 0){
		vendor=([ ]);
		save();
	}
	restore();
	remove_vendor();
//	vendor_status();
}
void remove()
{
	save();
	restore();
}

// 预先检测物品是否可转让
int valid_sell(object ob)
{
	if( ob->is_character() || ob->query("no_pawn")	
	|| ob->query("no_get") || ob->query("no_drop") 
	|| ob->query("ownermake") || ob->query("money_id")
	|| ob->query("no_steal") || ob->query("no_get_from") 
	|| ob->query("no_beg") || ob->is_food() || ob->is_liquid()
	|| !ob->query("value") || ob->query("consistence")) 
		return 0;

	return 1;
}

// 预先检测是否有物品已经委托拍卖
int check_vendor(string id)
{
	if(sizeof(vendor[id])) return 0;
	return 1;
}

//将物品增加到拍卖列表
int add_vendor(object me,object ob,int value)
{
	string name,id,unit;
	string ob_name,desc;

	name = me->query("name");
	id = me->query("id");
	unit = ob->query("unit");
	ob_name = ob->short(1);
	desc = ob->long();

	vendor[id] = sprintf("~%s~%s~%s~%s~%s~%d~%s",
		name,id,unit,ob_name,base_name(ob),value,desc);

	save();
	restore();
	write("你的"+ ob->name()+"稍后将在"HIY"【商贸交易】"NOR"频道进行拍卖。\n");
	destruct(ob);
	while(find_call_out("start_vendor") == -1 && vendor_now < 1)
	call_out("start_vendor",5);
	return 1;
}
int del_vendor(string name,string menu)
{
	if(stringp(vendor[name]) && stringp(menu)){
		map_delete(vendor,name);
		save();
		restore();
		return 1;
	}
	
}
// 检查是否在拍卖状态
/*
void vendor_status()
{
	string *goods = keys(vendor);

	if(sizeof(goods) > 0 
		&& !find_call_out("start_vendor")) 

	call_out("start_vendor",5);
	call_out("vendor_status",random(20) + 12);
}
*/
void start_vendor()
{
	string msg,base_name,id;
	string unit,ob_name,s_name,desc;
	string *goods = keys(vendor);
	int i,value;

	if(sizeof(goods) <= 0) return;

	
	if(!vmsg) vmsg = vendor[goods[random(sizeof(goods))]];
	if(!good_desc) good_desc = vmsg;
	vendor_now = 1;

	sscanf(vmsg,"~%s~%s~%s~%s~%s~%d~%s",s_name,id,unit,ob_name,base_name,value,desc);

	if(now_value < 1) now_value = value;
	if(low_value < 1) low_value = value;
	vid = id;

	if( time < 1 ){
		msg = sprintf("现在开始拍卖%s的%s一%s，底价为：%s。",
			s_name,ob_name + HIY,unit,
			MONEY_D->price_str(now_value));
		call_out("start_vendor",15);
		time +=1;
	}
	else if( time <= 3 ){
		msg = sprintf("拍卖%s的一%s%s，%s第%s次！",
			s_name,unit,ob_name + HIY,MONEY_D->price_str(now_value),
			chinese_number(time));
		call_out("start_vendor",15);
		time +=1;

	}
	else {
		if(find_player(bid)){
			sell_to_player(bid,base_name);
			msg = HIC"本次交易拍卖成功，收取十分之一的手续费。"NOR;
		} 
		else{
			msg = sprintf("由于无人出价，%s的%s拍卖失败。",s_name,ob_name + HIY);
			back_to_player(id,base_name);
		}
		del_vendor(id,sprintf("~%s~%s~%s~%s~%s~%d~%s",s_name,id,unit,ob_name,base_name,value,desc));
		remove_vendor();
		if(sizeof(goods) > 0)
		call_out("start_vendor",5);
	}

	CHANNEL_D->do_channel(this_object(),"dealer",msg);
	return;
}
void remove_vendor()
{
	time = 0;		// 拍卖次数回 0
	bid = 0;  		// 购买者信息为空
	vid = 0;  		// 拍卖者信息为空
	now_value = 0; 		// 当前叫价为0
	good_desc=0; 		// 当前拍卖物品系统清空
	low_value = 0;		// 底价初始化
	vendor_now = 0;		// 拍卖判断初始化
	vmsg =0;		// 拍卖信息初始化
	save();
	restore();
}
int sell_to_player(string id,string base_name)
{
	object me,obj,ob;
	string unit;
	int balance;
	
	if(stringp(id) && objectp(me = find_player(id))){
		obj = new(base_name);
		unit = obj->query("unit");
		CHANNEL_D->do_channel(this_object(),"dealer",sprintf("%s以%s的价钱买下了一%s%s！",
			me->name(),MONEY_D->price_str(now_value),unit,obj->short() + HIY));
			obj->move(me,1);
			tell_object(me,HIC + clean_color("\n你成功的买到了一"+ unit + obj->short() +"。\n\n")+NOR);
		if(stringp(vid) && objectp(ob = find_player(vid)))
			tell_object(ob,HIC + clean_color("\n你的"+ obj->short()+"交易拍卖成功！\n\n")+NOR);
			now_value -= now_value/10;
			balance = ob->query("balance") + now_value;			
			if( balance > 2100000000) balance = 2100000000;
			ob->set("balance",balance);
	}
	remove_vendor();
	return 1;
}
int back_to_player(string id,string base_name)
{
	object me,obj;
	
	me = find_player(id);

	if(environment(me)){
		obj=new(base_name);
		if(obj->move(me,1))
			tell_object(me,HIC + clean_color("\n你的"+ obj->short() +"拍卖失败，被退了回来。\n\n") + NOR);
		else
			destruct(obj);
	}
	remove_vendor();
	return 1;
}
int player_call_value(object me,int value)
{
	object ob;

	if(value > now_value){
		if( stringp(bid) && objectp(ob = find_player(bid))){
			ob->add("balance",now_value);
			tell_object(ob,HIC "\n"+ me->name(1)+"的叫价比你高，你的叫价被否决了。\n\n"NOR);
		}
		now_value = value;
		bid = me->query("id");
		me->add("balance",-value);
		CHANNEL_D->do_channel(this_object(),"dealer",
			sprintf("%s(%s)出价%s。",me->name(1),bid,MONEY_D->price_str(value)));
	}
	time = 1;
	return 1;
}
int query_desc()
{
	string s_name,id,unit,ob_name,base_name,value,desc;

	if(!good_desc){
		write("目前还没有物品正在拍卖，无法查阅更详细的信息。\n");
		return 1;
	}
	
	sscanf(good_desc,"~%s~%s~%s~%s~%s~%d~%s",s_name,id,unit,ob_name,base_name,value,desc);
	write(sprintf("当前正拍卖的物品是%s，以下是关于%s的信息：\n\n"
	"物主：%s(%s)\n介绍：%s底价：%s\n每次叫价：至少一两白银\n\n\t\t"HIC"以上信息来自"+ code_name() +"拍卖所。\n"NOR,
		ob_name,ob_name,s_name,capitalize(id),desc,MONEY_D->price_str(value)));
		return 1;
}
