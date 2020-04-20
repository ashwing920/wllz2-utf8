// 福利彩票
// Design By Robert

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

#define SAVE_FILE        DATA_DIR +"lottery"

inherit F_SAVE;
inherit F_DBASE;

string *number=({
	"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
	"16","17","18","19","20","21","22","23","24","25","26","27","28",
	"29","30","31","32","33","34","35","36","37","38","39","40","41",
	"42","43","44","45","46","47",
});
string *all_num=({
	"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
	"16","17","18","19","20","21","22","23","24","25","26","27","28",
	"29","30","31","32","33","34","35","36","37","38","39","40","41",
	"42","43","44","45","46","47",
});

string *LastNum = ({}); // 最后一期的开奖结果
string *Tnum = ({});
string *status = ({});

static int time;  // 抽奖次数
static int totle; // 总计奖金
static int trun; // 开奖识别

void pay_player(object me,int level);

void create()
{
	seteuid(geteuid());
	set("channel_id","彩票");
	if(!restore())
	set("time",1);
	set("totle",500000000);
}
string query_save_file()
{
	return SAVE_FILE;
}
int clean_up()
{
	return 1;
}
void ready_start()
{
	restore();
	LastNum = 0; // 清空上次中奖号码
	Tnum = ({}); // 清空上次中奖号码
	time = 1; // 初始化抽奖次数为1
	number=0; // 清空上次抽选剩下的号码
	number = all_num; // 载入所有预设的号码
	
	// 如果上期发放奖励大于五万底金，自动分割十分之一做为累积奖金。
	if(query("pay_totle") >= 500000000) {
		add("totle",query("pay_totle") / 10);
	}
	
	// 如果上期奖金已经被完全发放，则回到初始化阶段，奖金底线为五万。
	else if(query("pay_totle") < 1) {
		set("totle",500000000);
	}
	
	// 如果累积奖金高达二十万，则回到初始化阶段，奖金底线五万。
	if(query("totle") >= 2000000000) set("totle",500000000);
	set("pay_totle",query("totle"));

	save(); // 完成存档后开始抽奖
	message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：第 %d 期福利彩票开始抽奖，请拿出您的彩票，仔细核对号码。\n"NOR,query("time")),users());
	call_out("start_select",5);

}
void start_select()
{
	string num; // 当前开奖结果
	int i;

	num = number[random(sizeof(number))];

	// 抽奖为七次，分别为六个普通号码，另外一个为特别号码
	trun = 1;
	if(time < 7 )
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：第%s个中奖号码为 %s \n"NOR,chinese_number(time),num),users());

	else
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：这一期特别号码为 "HIW"%s\n"NOR,num),users());

	Tnum += ({ num });	// 将抽出的号码加入到本期开奖号码中。
	number -= ({ num });  // 从预设的号码中删除已经开出的号码。
	time += 1;	// 增加抽奖次数一次

	// 如果抽奖次数未足七次，继续挑选号码，否则公布此次开奖结果
	if(time > 7){
		message("channel:chat",sprintf(HIY"【福利彩票】第 %d 期福利彩票开奖号码：%s、%s、%s、%s、%s、%s，特别号码：%s 。\n"NOR,
		query("time"),Tnum[0],Tnum[1],Tnum[2],Tnum[3],Tnum[4],Tnum[5],Tnum[6]),users());
		
		LastNum = Tnum;
		add("time",1);
		totle = query("totle");
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]："HIW"统计累积奖金，本期特奖为：%s。\n"NOR,MONEY_D->price_str(totle)),users());
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：请中奖者在下次开奖之前找我领奖，逾期作废，抽奖完毕。\n"NOR),users());
		trun = 0;
		save();
	} else {
		remove_call_out("start_select");
		call_out("start_select",10);
	}
}
int check_number(object me,string *my_num,object ob)
{
	int Ii,Il,Ti;

	Ti = query("totle");

	if((int)me->query("lottery_time")){ 
		if((int)me->query("lottery_time") > query("time")-1){
			tell_object(me,"你购买的彩票还没有开奖，无法对奖。\n");
			return 1;
		}
		if((int)me->query("lottery_time") != query("time")-1){
			tell_object(me,"你的彩票期数与当前彩票期数不符，已经作废了。\n");
			if(me->query("lottery_time")) me->delete("lottery_time");
			if(me->query("buy_number")) me->delete("buy_number");
			destruct(ob);
			return 1;
		}
		if(member_array(me->query("id"),status) == -1){
			tell_object(me,"你还没有登记，无法兑奖。\n");
			return 1;
		}
	}
	if(sizeof(LastNum) < 1){
		tell_object(me,"目前彩票还没开奖，无法兑奖。\n");
		return 1;
	}
// 核对第一个号码

	if(my_num[0] == LastNum[0]) Ii += 1;
	if(my_num[0] == LastNum[1]) Ii += 1;
	if(my_num[0] == LastNum[2]) Ii += 1;
	if(my_num[0] == LastNum[3]) Ii += 1;
	if(my_num[0] == LastNum[4]) Ii += 1;
	if(my_num[0] == LastNum[5]) Ii += 1;

// 核对第二个号码

	if(my_num[1] == LastNum[0]) Ii += 1;
	if(my_num[1] == LastNum[1]) Ii += 1;
	if(my_num[1] == LastNum[2]) Ii += 1;
	if(my_num[1] == LastNum[3]) Ii += 1;
	if(my_num[1] == LastNum[4]) Ii += 1;
	if(my_num[1] == LastNum[5]) Ii += 1;

// 核对第三个号码

	if(my_num[2] == LastNum[0]) Ii += 1;
	if(my_num[2] == LastNum[1]) Ii += 1;
	if(my_num[2] == LastNum[2]) Ii += 1;
	if(my_num[2] == LastNum[3]) Ii += 1;
	if(my_num[2] == LastNum[4]) Ii += 1;
	if(my_num[2] == LastNum[5]) Ii += 1;

// 核对第四个号码

	if(my_num[3] == LastNum[0]) Ii += 1;
	if(my_num[3] == LastNum[1]) Ii += 1;
	if(my_num[3] == LastNum[2]) Ii += 1;
	if(my_num[3] == LastNum[3]) Ii += 1;
	if(my_num[3] == LastNum[4]) Ii += 1;
	if(my_num[3] == LastNum[5]) Ii += 1;

// 核对第五个号码

	if(my_num[4] == LastNum[0]) Ii += 1;
	if(my_num[4] == LastNum[1]) Ii += 1;
	if(my_num[4] == LastNum[2]) Ii += 1;
	if(my_num[4] == LastNum[3]) Ii += 1;
	if(my_num[4] == LastNum[4]) Ii += 1;
	if(my_num[4] == LastNum[5]) Ii += 1;

// 核对第六个号码

	if(my_num[5] == LastNum[0]) Ii += 1;
	if(my_num[5] == LastNum[1]) Ii += 1;
	if(my_num[5] == LastNum[2]) Ii += 1;
	if(my_num[5] == LastNum[3]) Ii += 1;
	if(my_num[5] == LastNum[4]) Ii += 1;
	if(my_num[5] == LastNum[5]) Ii += 1;

// 核对第七个号码

	if(my_num[6] == LastNum[0]) Ii += 1;
	if(my_num[6] == LastNum[1]) Ii += 1;
	if(my_num[6] == LastNum[2]) Ii += 1;
	if(my_num[6] == LastNum[3]) Ii += 1;
	if(my_num[6] == LastNum[4]) Ii += 1;
	if(my_num[6] == LastNum[5]) Ii += 1;

// 核对预选号码中是否有特别号码

	if(my_num[0] == LastNum[6]) Il += 1;
	if(my_num[1] == LastNum[6]) Il += 1;
	if(my_num[2] == LastNum[6]) Il += 1;
	if(my_num[3] == LastNum[6]) Il += 1;
	if(my_num[4] == LastNum[6]) Il += 1;
	if(my_num[5] == LastNum[6]) Il += 1;
	if(my_num[6] == LastNum[6]) Il += 1;

	if(Ii > 5 && Il > 0) {
		tell_object(me,"恭喜，你中了本期福利彩票的特等奖。\n");
		me->delete("buy_number");		// 删除预选号码
		me->delete("lottery_time");		// 删除购买期数
		status -= ({ me->query("id") });
		pay_player(me,1);
		destruct(ob);
		return 1;
	}
	if(Ii > 4 && Il > 0 ){
		tell_object(me,"恭喜，你中了本期福利彩票的一等奖。\n");
		me->delete("buy_number");
		me->delete("lottery_time");
		status -= ({ me->query("id") });
		pay_player(me,2);
		destruct(ob);
		return 1;
	}
	else if(Ii > 3 && Il > 0){
		tell_object(me,"恭喜，你中了本期福利彩票的二等奖。\n");
		me->delete("buy_number");
		me->delete("lottery_time");
		status -= ({ me->query("id") });
		pay_player(me,3);
		destruct(ob);
		return 1;
	}
	else if(Ii > 2 && Il > 0){
		tell_object(me,"恭喜，你中了本期福利彩票的三等奖。\n");
		me->delete("buy_number");
		me->delete("lottery_time");
		status -= ({ me->query("id") });
		pay_player(me,4);
		destruct(ob);
		return 1;
	}
	tell_object(me,"你在这一期福利彩票并没中奖。\n");
	me->delete("buy_number");
	me->delete("lottery_time");
	status -= ({ me->query("id") });
	save();
	restore();
	destruct(ob);
	return 1;
}
int do_register(object me,int value)
{
	if(member_array(me->query("id"),status) != -1) {
		tell_object(me,"登记失败，你已经登记过了。\n");
		return 1;
	}
	if(trun){
		tell_object(me,"目前正开奖当中，不能登记。\n");
		return 1;
	}
	
	add("totle",value);
	status += ({ me->query("id") });
	me->set("lottery_time",query("time"));
	save();
	restore();
	tell_object(me,"登记成功，请保存好你的彩票，否则将无法领奖。\n");
	return 1;	
}
void pay_player(object me,int level)
{
	if(level == 1){
		MONEY_D->pay_player(me,query("totle"));
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：恭喜%s(%s)获得第 %d 期福利彩票特等奖 %s ！\n"NOR,
		me->name(1),me->query("id"),(query("time")-1),MONEY_D->price_str(query("totle"))),users());
		log_file("lottery",sprintf("[%s]%s(%s)赢得福利彩票特等奖%s 。\n",
		ctime(time()),me->name(1),me->query("id"),MONEY_D->price_str(query("totle"))));
		add("pay_totle",- query("totle"));
		save();
		restore();
		return;
	}
	else if(level == 2){
		MONEY_D->pay_player(me,query("totle")/3);
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：恭喜%s(%s)获得第 %d 期福利彩票一等奖 %s ！\n"NOR,
		me->name(1),me->query("id"),(query("time")-1),MONEY_D->price_str(query("totle")/3)),users());
		log_file("lottery",sprintf("[%s]%s(%s)赢得福利彩票一等奖%s 。\n",
		ctime(time()),me->name(1),me->query("id"),MONEY_D->price_str(query("totle")/3)));
		add("pay_totle",- query("totle") / 3);
		save();
		restore();
		return;
	}
	else if(level == 3){
		MONEY_D->pay_player(me,query("totle")/5);
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：恭喜%s(%s)获得第 %d 期福利彩票二等奖 %s ！\n"NOR,
		me->name(1),me->query("id"),(query("time")-1),MONEY_D->price_str(query("totle")/5)),users());
		log_file("lottery",sprintf("[%s]%s(%s)赢得福利彩票二等奖%s 。\n",
		ctime(time()),me->name(1),me->query("id"),MONEY_D->price_str(query("totle")/5)));
		add("pay_totle",- query("totle") / 5);
		save();
		restore();
		return;
	}
	else if(level == 4){
		MONEY_D->pay_player(me,query("totle")/100);
		message("channel:chat",sprintf(HIY"【福利彩票】票童[Lottery Boy]：恭喜%s(%s)获得第 %d 期福利彩票三等奖 %s ！\n"NOR,
		me->name(1),me->query("id"),(query("time")-1),MONEY_D->price_str(query("totle")/10)),users());
		log_file("lottery",sprintf("[%s]%s(%s)赢得福利彩票三等奖%s 。\n",
		ctime(time()),me->name(1),me->query("id"),MONEY_D->price_str(query("totle")/10)));
		add("pay_totle",- query("totle") / 100);
		save();
		restore();
		return;
	}
}
