// logind.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

string *place = ({
	"/d/city/kedian",
	"/d/center/inn",
	"/d/city/wumiao",
	"/d/center/guandimiao",
});
static int wiz_lock_level = WIZ_LOCK_LEVEL;
static int mud_lock = 0;
string Rname;
private void get_id(string arg, object ob);
private void get_new_id(string arg, object ob);
private void confirm_id(string yn, object ob);
private void get_oicq(string oicq, object ob,object user);
private void newbie_help(string select,object ob,object user);
object make_body(object ob);
private void init_new_player(object user);
private void get_resp(string arg, object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int check_legal_password(object ob, string pass);
private void random_gift(mapping my)
{
	int i;
	int tmpstr, tmpint, tmpcon, tmpdex, tmpper, tmpkar,tmpcor,tmpspi;
	tmpstr = 10 + random(13);
	tmpint = 10 + random(13);
	tmpcon = 10 + random(13);
	tmpdex = 10 + random(13);
	tmpper = 10 + random(13);
	tmpkar = 10 + random(13);
	tmpcor = 10 + random(13);
	tmpspi = 10 + random(13);

	for (i = 0; i < 35; i++) {
		switch (random(8)) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpkar++; break;
		case 5: tmpper++; break;
		case 6: tmpcor++; break;
		case 7: tmpspi++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	if (tmpper <= 30) my["per"] = tmpper; else my["per"] = 30;
	if (tmpkar <= 30) my["kar"] = tmpkar; else my["kar"] = 30;
	if (tmpcor <= 30) my["cor"] = tmpcor; else my["cor"] = 30;
	if (tmpspi <= 30) my["spi"] = tmpspi; else my["spi"] = 30;

}
private void create()
{
	seteuid(getuid());
	set("channel_id", "连线精灵");
}
void logon(object ob)
{
	object *usr;
	int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
	int iplimit;
	int i_user,totle;
	string user_num,totle_user;

/*
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	login_cnt = 0;
	while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
	if (login_cnt > 3) {
		destruct(ob);
		return;
	}
*/
	if (BAN_D->is_banned(query_ip_number(ob)) == 1) {
		write(CLR);
		write(HIR"\n\n你的地址在本游戏不受欢迎，请与巫师联系。\n"NOR);
		write(HIW"联系邮箱：robert_st@sina.com 或：robert_st@163.net 蝴蝶君。\n"NOR);
		destruct(ob);
		return;
	}

	usr = filter_array(objects(), (: userp :));
	wiz_cnt = 0;
	inv_wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	iplimit = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( interactive(usr[i]) && query_ip_number(usr[i])==query_ip_number(ob)) iplimit ++;
		if( !environment(usr[i]) || (!interactive(usr[i]) && !usr[i]->query_temp("biguan"))) login_cnt++;
		else if( wizardp(usr[i]) && usr[i]->query("env/invisibility") ) inv_wiz_cnt++;
		else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") ) wiz_cnt++;
		else ppl_cnt++;
	}
	if(!BAN_D->is_pass_id(query_ip_number(ob))){
		if(iplimit > 30){
write(@TEXT

	对不起，你这个ＩＰ的使用者已经太多了，请退出其他帐号再试！
	如果您是从网吧登录，请到本游戏的网页注册网吧登陆权限。
	联系邮箱：robert_st@sina.com 或：robert_st@163.net 蝴蝶君。

TEXT);
			destruct(ob);
			return;
		}
	}else if( iplimit > 30 ) {
			write("这个地址已经有太多帐号正在使用了。\n");
			destruct(ob);
			return ;
	}
#ifdef DB_SAVE
	i_user = DATABASE_D->db_count_user(); 
#else
	user_num=read_file(CONFIG_DIR "iduser",1);
	i_user=atoi(user_num);
	i_user=i_user+1;
	user_num=sprintf("%d", i_user);
	write_file(CONFIG_DIR "iduser",user_num,1);
	user_num=read_file(CONFIG_DIR "iduser",1);
	i_user=atoi(user_num);
#endif
	totle_user=read_file(CONFIG_DIR "totle_user",1);
	totle=atoi(totle_user);
	if(ppl_cnt + login_cnt+inv_wiz_cnt > totle)
	totle_user=sprintf("%d",ppl_cnt + login_cnt+inv_wiz_cnt);
	write_file(CONFIG_DIR "totle_user",totle_user,1);
	totle=atoi(totle_user);
	write(read_file(WELCOME));
	MUDLIST_CMD->main(this_object(),"");
	write(sprintf("\n本站当前访问量为 "HIY"%d"NOR" 人次，最高有 "HIY"%d／600"NOR" 位玩家同时进行游戏。\n"NOR,i_user,totle));
	write(sprintf("目前共有"HIW" %d "NOR"位巫师，"HIY"%d "NOR"位江湖儿女正在游戏，以及"HIG" %d "NOR"位使用者正尝试连线。\n",wiz_cnt,
	ppl_cnt, (login_cnt+inv_wiz_cnt)));
	write(sprintf("您的网路连线地址为："HIW"%s"NOR"，该地址目前还有%s位玩家正在连线中。\n", query_ip_number(ob), CHINESE_D->chinese_number(iplimit -1)));
	write("请输入您的英文名字["HIW"新玩家请使用 new 注册"NOR"]：");
	input_to( "get_id", ob );
}
private void get_id(string arg, object ob)
{
	object *usr,ppl;
	int i,wiz_cnt,flag;
	mixed res;
	arg = lower_case(arg);

	if( BAN_D->is_ban_id(arg)) {
		write("对不起，这个ID已经被禁止登陆，请联系巫师。\n");
		write("请输入您的英文名字["HIW"新玩家请使用 new 注册"NOR"]：");
		input_to("get_id", ob);
		return;
	}

	if( !check_legal_id(arg)) {
		write("请输入您的英文名字["HIW"新玩家请使用 new 注册"NOR"]：");
		input_to("get_id", ob);
		return;
	}

	usr = users();
	wiz_cnt = 0;
	for(i=0; i<sizeof(usr); i++)
	{
		if( wizardp(usr[i]) )
			wiz_cnt++;
	}
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& (sizeof(users()) - wiz_cnt) >= 350) {
		ppl = find_body(arg);
		if( !ppl || !interactive(ppl) ) {
			write("对不起，本游戏的使用者已经太多了，请待会再来。\n");
			destruct(ob);
			return;
		}
	}
	if( wiz_level(arg) < wiz_lock_level ) {
		write("对不起，本游戏目前限制巫师等级 " + WIZ_LOCK_LEVEL
			+ " 以上的人才能连线。\n");
		destruct(ob);
		return;
	}
	if( mud_lock ) {
		write("系统正在整理玩家资料档，请稍后再尝试连线。\n");
		destruct(ob);
		return;
	}
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
	if( file_size(DATA_DIR + "login/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__) > 0
	&&file_size(DATA_DIR + "user/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__) < 0 ) {
		if( file_size(DATA_DIR + "login/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__) > 0 )
			SECURITY_D->rm_user(DATA_DIR + "login/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__);
		if( file_size(DATA_DIR + "user/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__) > 0 )
				SECURITY_D->rm_user(DATA_DIR + "user/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__);
		if( file_size(DATA_DIR + "mail/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__) > 0 )
				SECURITY_D->rm_user(DATA_DIR + "mail/" + sprintf("%c", arg[0]) + "/" + arg + __SAVE_EXTENSION__);
	}

	if (arg=="new") { // new player login
		write("你好，新玩家！请给自己取一个英文名字：");
		input_to("get_new_id",ob);
		return;

	}
#ifdef DB_SAVE
    res = DATABASE_D->do_sql("select online, on_time from users where id = '" + arg + "'");
    flag = arrayp(res);
    if( flag ) 
		{
           ob->set_temp("res", res);
#else
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
#endif
			if( ob->restore() ) {
				write("该帐号已被注册，请输入密码：");
				input_to("get_passwd", 1, ob);
				return;
		}

		write("您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
		destruct(ob);
		return;
	}

	write("没有这个玩家．．．\n");
	write("请输入您的英文名字["HIW"新玩家请使用 new 注册"NOR"]：");
	input_to("get_id", ob);
	return;
}

private void get_new_id(string arg, object ob)
{
	object *usr;
	int i,flag;
	mixed res;

	if(!ob) return;
	if(!arg) {
		write("请您给自己取一个英文名字：");
		input_to("get_new_id", ob);
		return;
	}

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write("请您给自己取一个英文名字：");
		input_to("get_new_id", ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	//ppl = find_body(arg);
	if(arg=="guest" || arg=="new") {
		write("抱歉！这个名字已经被别的玩家使用了．．．");
		write("\n请您给自己取一个英文名字：");
		input_to("get_new_id",ob);
		return;
	}
#ifdef DB_SAVE
    res = DATABASE_D->do_sql("select online, on_time from users where id = '" + arg + "'");
    flag = arrayp(res);
    if( flag ) 
		{
           ob->set_temp("res", res);
#else
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
#endif
		write("抱歉！这个名字已经被别的玩家使用了．．．");
		write("\n请您给自己取一个英文名字：");
		input_to("get_new_id",ob);
		return;
	}

	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("有其他玩家正在使用这个英文名字，请重新选择输入。");
		write("\n请您给自己取一个英文名字：");
		input_to("get_new_id",ob);
		return;
	}

	confirm_id("Yes", ob);
	return;
}

private void get_passwd(string pass, object ob)
{
	string my_pass;
	object user;
	int quit_time;

	my_pass = ob->query("password");

	if( crypt(pass, my_pass) != my_pass ){
		if(file_size("/log/password/"+ ob->query("id")) < 1024 )
			log_file("password/"+ ob->query("id"),sprintf("USER：%s  TIME：%s  IP：%s。\n",
				capitalize(ob->query("id")),ctime(time()),query_ip_number(ob)));
		switch(ob->query_temp("pass_error")){
			case 1:
				write(HIR"密码错误！\n"NOR);
				write("再给你最后一次机会，请再次输入你的密码：");
				ob->set_temp("pass_error",2);
				input_to("get_passwd", 1, ob);
				return;
			case 2:
				write(HIR"\n密码错误！如果你确实忘记了密码，请和巫师联系！再见！\n"NOR);
				destruct(ob);
				return;
			default:
				write(HIR"密码错误！\n"NOR);
				write("再给你一次机会，请再次输入你的密码：");
				ob->set_temp("pass_error",1);
				input_to("get_passwd", 1, ob);
				return;
		}
	}
	
	if(BAN_D->is_ban_id(ob->query("id")) == 1) {
		write("对不起，这个ID已被禁止在本游戏登陆，请联系巫师。\n");
		destruct(ob);
		return ;
	}
/*
	if((int)ob->query("last_on") && (time() - (int)ob->query("last_on")) < 30
	&& wiz_level(ob->query("id")) < 2 ){
		quit_time = time() - (int)ob->query("last_on");
		write("对不起，为了降低系统负荷，请稍等"+ chinese_number(30 - quit_time)+"秒后再进入。\n");
		destruct(ob);
		return;
	}
*/
	if(time() - (int)ob->query("kickout_time") < 3600 ){
		write(HIR"你现在没有进入游戏的权利，请一小时后再连线。\n"NOR);
		destruct(ob);
		return;
	}

	user = find_body(ob->query("id"));

	if(user && !environment(user)) destruct(user);
	if (user){
		if( user->query_temp("netdead")){
			reconnect(ob, user);
			return;
		}
		else if( user->query_temp("biguan")){
			write("\n目前该人物正在闭关中，重新连线将会提前破关而出，确定吗(y/n)？");
			input_to("confirm_relogin2", ob, user);
			return;
		}
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}
	if( objectp(user = make_body(ob))) {
	if( user->restore()) {
			log_file("USAGE",sprintf("[%s] %s[%s]连线来自[%s]\n",
			ctime(time()),user->query("name"),user->query("id"),query_ip_number(ob)));
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("请您重新创造这个人物。\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}


	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "有人从别处[" HIR + query_ip_number(ob)+ NOR"]连线取代你所控制的人物。\n");
		log_file( "login/RELOGIN", sprintf("[%s] %s[%s]重新连线来自[%s]。\n",
			ctime(time()),user->query("name"),geteuid(user),query_ip_number(ob)));
	}
	if( objectp(old_link = user->query_temp("link_ob"))) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}
private void confirm_relogin2(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("目前该人物正在闭关中，重新连线将会提前破关而出，确定吗(y/n)？");
		input_to("confirm_relogin2", ob, user);
		return;
	}
	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "有人从别处[" HIR + query_ip_number(ob)+ NOR"]连线取代你所控制的人物。\n");
		log_file( "login/RELOGIN", sprintf("[%s] %s[%s]重新连线来自[%s]。\n",
			ctime(time()),user->query("name"),geteuid(user),query_ip_number(ob)));
	}
	if( objectp(old_link = user->query_temp("link_ob"))) {
		exec(old_link, user);
		destruct(old_link);
	}
	reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write("您确定要创造一个新人物了吗(y/n)？");
		input_to("confirm_id", ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("好吧，那么请重新输入您的英文名字：");
		input_to("get_id", ob);
		return;

	}
	write( @TEXT

[1;37m请输入您的高姓大名，由于这个名字将代表你本人的性格，作风，请慎重择[0m
[1;37m名。请不要起不雅观的名字，也请尽量不要和别人同名。本游戏巫师工作组[0m
[1;37m将保留随时修改你的中文名字的权利。[0m

[1;34m如果您不方便输入中文，按「ＥＮＴＥＲ」系统将会为您产生一个中文名字[0m

TEXT
	);
	write("请输入您的中文名字：");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
	mapping name;

	if(arg == ""){
		write("系统正在产生一个随机的中文名字．．\n");
		Rname = npc_name(random(3)?"男性":"女性");
		write(sprintf("中文名字：「"HIW"%s"NOR"」\n",Rname));
		write("您喜欢这个中文名字吗「y/n」？输入「r」则改为自己输入。");
		input_to("get_resp", ob);
	}
	else {
	if( !check_legal_name(arg) ) {
		write("请输入您的中文名字：");
		input_to("get_name", ob);
		return;
	}

	if(!PNAME_D->check_name(arg)){
		write("请输入您的中文名字：");
		input_to("get_name",ob);
		return;
	}
	ob->set("name", arg);
	write("请设定您的密码：");
	input_to("new_password", 1, ob);
	}
}
private void get_resp(string arg, object ob)
{
	if( arg=="" ) {
		write("您喜欢这个中文名字吗「y/n」？输入「r」则改为自己输入。");
		input_to("get_resp", ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' ){
//		printf("%O\n", ob);
		ob->set("name",Rname);
		write("请设定您的密码：");
		input_to("new_password", 1, ob);
		return;
	}
	if( arg[0]=='r' || arg[0]=='R' ){
		write("请输入您的中文名字：");
		input_to("get_name",ob);
		return;
	}
	else
	if( arg[0]=='n' || arg[0]=='N'){
		Rname = npc_name(random(3)?"男性":"女性");
		write(sprintf("中文名字：「"HIW"%s"NOR"」\n",Rname));
		write("您喜欢这个中文名字吗「y/n」？输入「r」则改为自己输入。");
		input_to("get_resp", ob);
	return;
	}
	else {
		write("您喜欢这个中文名字吗「y/n」？\n");
		input_to("get_resp", ob);
		return;
	}
}
private void new_password(string pass, object ob)
{

	if(!check_legal_password(ob,pass)){
		write("请设定您的密码：");
		input_to("new_password", 1, ob);
		return;
	}

	ob->set("password", crypt(pass, sprintf("$1$%d", random(99999999))));

	write("请再输入一次您的密码，以确认您没记错：\n");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("\n您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("new_password", 1, ob);
		return;
	}
	write(@TEXT
									
[35m一个人物的天赋对于他或她所修习的武艺息息相关。游戏中的人物大多[0m
[35m具有以下八项天赋：[0m

	[36m膂力：影响攻击能力及负荷量的大小。[0m
	[36m悟性：影响学习武功秘籍的速度及理解师傅的能力。[0m
	[36m根骨：影响体力恢复的速度及升级后所增加的体力。[0m
	[36m身法：影响防御及躲避的能力。[0m
	[36m容貌：影响游戏中的拜师以及迷题等。[0m
	[36m运气：影响游戏中的任务，迷题，赚钱交易等。[0m
	[36m灵性：决定着你在游戏中对于武学方面的最高上限。[0m
	[36m定力：决定着你在游戏中人物的性格类型等。[0m

TEXT
);
	my = ([]);
	random_gift(my);
	write(sprintf(HIY"\n膂力[%d]　　　悟性[%d]　　　根骨[%d]　　　身法[%d]　　　\n容貌[%d]　　　运气[%d]　　　定力[%d]　　　灵性[%d]\n\n"NOR,
		my["str"], my["int"], my["con"], my["dex"],my["per"],my["kar"],my["cor"],my["spi"]));
	write("您接受这一组天赋吗？");
	input_to("get_gift", ob, my);
}

private void get_gift(string yn, object ob, mapping my)
{
	int totle;

	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my);
	write(sprintf(HIY"\n膂力[%d]　　　悟性[%d]　　　根骨[%d]　　　身法[%d]　　　\n容貌[%d]　　　运气[%d]　　　定力[%d]　　　灵性[%d]\n\n"NOR,
		my["str"], my["int"], my["con"], my["dex"],my["per"],my["kar"],my["cor"],my["spi"]));
		write("您同意这一组天赋吗？");
		input_to("get_gift", ob, my);
	}
	totle = my["str"]+my["int"]+my["con"]+ my["dex"]+my["per"]+my["kar"]+my["cor"]+my["spi"];
	if (yn[0] == 'y' || yn[0] == 'Y') {
		write("您的天赋总值是："HIY + totle+"\n"NOR);
		write("您的电子邮件地址：");
		input_to("get_email", ob, my);
	}
}

private void get_email(string email, object ob, mapping my)
{
	object user;
	string id,address;
	if (email == "" || strsrch(email, "@") == -1||
		sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1){
		write("电子邮件地址需要是 id@address 的格式。\n");
		write(@TEXT
[1;31m注意：填写你的信箱时，请输入您的真实电子邮件地址，以方便我们与您联系。
当您忘记密码的时候，这是您取回密码的唯一方式。  [0m

TEXT);
		write("请重新输入您的电子邮件地址：");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob))) return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("per", my["per"]);
	user->set("kar", my["kar"]);
	user->set("spi", my["spi"]);
	user->set("cor", my["cor"]);
	user->set("registered", 1);
	write("你的电子邮箱是：["HIC + email +NOR"]\n");
	write("请输入您的 Oicq 号码：");
	input_to("get_oicq",ob,user);
}
private void get_oicq(string oicq,object ob,object user)
{
	if(oicq && oicq != ""){
		if( (strlen(oicq) < 4 ) || (strlen(oicq) > 10) ){
			write("请输入 4 至 10 位数的号码，否则请按回车直接跳过。\n");
			write("请输入您的 Oicq 号码：");
			input_to("get_oicq",ob,user);
			return;
		}
		write("您的 Oicq 号码是：["HIC + oicq +NOR"]\n");
		ob->set("oicq",oicq);
	}
	else {
		write("您的 Oicq 号码是：[ 没有 ]\n");
		ob->set("oicq","没有");
	}
	write("你希望在游戏中使用新手精灵给你提示吗？[y/n]");
	input_to("newbie_help",ob,user);
}
private void newbie_help(string select,object ob,object user)
{
	write("\n");
	if(select ==""){
		write("你希望在游戏中使用新手精灵给你提示吗？[y/n]");
		input_to("newbie_help",ob,user);
		return;
	}
	if( select[0]=='y' || select[0]=='Y' )
		user->set("env/newbie_wizard",60);
	else if( select[0]=='n' || select[0]=='N' )
		user->set("env/show_news",1);
	else {
		write("你希望在游戏中使用新手精灵给你提示吗？[y/n]");
		input_to("newbie_help", ob, user);
		return;
	}

	write("您要扮演男性["HIG"m"NOR"]的角色或女性["HIM"f"NOR"]的角色？");
	input_to("get_gender",ob,user);
}
private void get_gender(string gender, object ob, object user)
{
	write("\n");
	if( gender=="" ) {
		write("您要扮演男性["HIC"m"NOR"]的角色或女性["HIM"f"NOR"]的角色？");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "男性");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "女性" );
	else {
		write("对不起，您只能选择男性["HIC"m"NOR"]或女性["HIM"f"NOR"]的角色：");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "NEW_PLAYER", sprintf("[%s]新玩家 %s[%s]来自[%s]\n",ctime(time()),user->name(1),user->query("id"),query_ip_number(ob)));
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}
object make_body(object ob)
{
	string err;
	object user;

	seteuid(getuid());
	user = new(USER_OB);
	if(!user) {
		write("现在可能有巫师正在修改使用者物件的程式，请稍候再试。\n");
		destruct(ob);
	}

	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{

	user->set("title","平民百姓");
	user->set("birthday", time());
	user->set("combat_exp",0);
	user->set("potential",100);
	user->set("food", user->max_food_capacity());
	user->set("water",user->max_water_capacity());
	user->set_temp("newplayer",1);
	user->set("channels",({ "chat","rumor","music","dealer","party","master","banghui","wllz","frds","tt"}) );
	user->set("env/prompt","time");
	user->set("env/wimpy",60);
	if((string)user->query("gender") == "男性") {
		message("channel:chat", HIW"【江湖消息】"+HIG + NATURE_D->game_time()+"，一代侠客"+ user->name(2) +"横空出世啦！！\n"NOR,users());
	}else {
		message("channel:chat", HIW"【江湖消息】"+HIM+ NATURE_D->game_time()+"，一代女侠"+ user->name(2) +"横空出世啦！！\n"NOR,users());
	}

}
varargs void enter_world(object ob, object user, int silent)
{
	object login_ob;
	string startroom,file;
	write("1\n");
	if(user->query("name") != ob->query("name") ) {
		PNAME_D->del_name(ob->query("id"),ob->query("name"));
		PNAME_D->add_name(user->query("id"),user->query("name"));
		ob->set("name",user->query("name"));
	}
	user->set_temp("link_ob", ob);
	if( ob->query_temp("webclient"))
	{
		user->set_temp("webclient", 1);
	} else {
		user->delete_temp("webclient");
	}
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);
	PNAME_D->add_name(user->query("id"),user->query("name"));
	write("\n目前权限：" + wizhood(user) +"\n");
	if(!user->query("login_online")){
	user->set("register_time",time());
	write(@TEXT
─────────────────────────────────
新手须知：

您好，新玩家！请先阅读相关游戏规则。使用 [1;37mhelp[0m 查阅帮助信息！
请访问我们的游戏主页『[1;37mhttp://www.cnmud.com[0m』，从中得到帮助。
─────────────────────────────────
TEXT);
		write(read_file(MOTD));
		input_to("come_in",user);
	 }
	 else {
		write(read_file("/adm/etc/motd2"));
		login_ob=new(LOGIN_OB);
		login_ob->set("id",user->query("id"));
		login_ob->restore();
		write("\n您上次光临本站是在 "HIR + ctime(login_ob->query("last_on")) + NOR" 从 "HIG + login_ob->query("last_from") + NOR" 连接。\n");
		write("您在本站的游戏时间总计为："+ CHINESE_D->chinese_time((int)user->query("mud_age"))+"。\n\n"NOR);
		if(login_ob->query("passed_ids")){
			BAN_D->add_passed(query_ip_number(user));
			tell_object(user,HIW"【系统提示】恭喜！你的多重登陆权限已经开启了，请慎重使用，多谢合作！\n"NOR);
			user->set_temp("my_ip",query_ip_number(user));
		}
		destruct(login_ob);
	}
	user->setup();
#ifdef DB_SAVE
        if( user->query_temp("newplayer") ) {
				write("newpalyer insert in db\n");
                DATABASE_D->db_new_player(ob, user);
        }
#endif
	user->save();
	ob->save();
	file = "/log/password/"+ user->query("id");
	if( file_size(file) > 0 ){
		tell_object(user,"─────────────────────────────────\n");
		tell_object(user,HIG"系统：以下是你连线密码错误的记录，请注意妥善保管你的密码！\n\n"NOR);
		user->start_more(read_file(file));
		if(!wizardp(user)) {  // 如果不是巫师的记录，则自动删除。
		tell_object(user,HIG"\n系统自动将你的错误记录删除了！\n"NOR);
		rm(file);
		}
		tell_object(user,"─────────────────────────────────\n");
	}
	if( !silent ){
		if( user->is_ghost() ) {
			startroom = DEATH_ROOM;
			user->move(DEATH_ROOM);
		}
		else if( user->query_condition("parsion")) {
			startroom = "/d/xingbu/qiushi1";
			user->move("/d/xingbu/qiushi1");
		}
		else if( !stringp(startroom = user->query("startroom")) ) {
			startroom = place[random(sizeof(place))];
			user->move(startroom);
		}
		else if( wizardp(user) && (geteuid(user) != "robert" && geteuid(user) != "bmw"))
			user->move("/d/wizard/wizard_room");
		else if(file_size(startroom+".c") > 0
		&& !catch(load_object(startroom)))
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}

	}

	if(wizardp(user)) {
		CHANNEL_D->do_channel( this_object(), "arch",
			sprintf("%s由[%s:%d]连线进入。",user->name(2),query_ip_name(user),query_ip_port(user)) );
			log_file("login/"+ geteuid(user),sprintf("%s[%s]由[%s]连线进入游戏。[%s]\n",user->name(1),geteuid(user),query_ip_number(user),ctime(time())));
	}
	else	{
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s由[%s:%d]连线进入。",user->name(2),query_ip_name(user),query_ip_port(user)));
	}
#ifdef DB_SAVE
        DATABASE_D->db_set_player(query("id", user),"online",1);
#endif
	user->add("login_online",1);
	user->set_temp("temp_exp",user->query("combat_exp"));
	user->set_temp("temp_time",time());
	user->set_temp("temp_pot",(int)user->query("potential") - (int)user->query("learned_points"));
	if(user->query("friends")) user->delete("friends");
	NEWS_CMD->main(user,"check");
	UPDATE_D->check_user(user);
	TOPTEN_D->topten_checkplayer(user);
	if(user->query("env/newbie_wizard")) "/adm/daemons/newbied"->start_help(user);
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	if( ob->query_temp("webclient"))
	{
		user->set_temp("webclient", 1);
	} else {
		user->delete_temp("webclient");
	}
	exec(user, ob);
	user->reconnect();
	if( !silent ) {
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s由[%s:%d]重新连线进入。", user->query("name"), query_ip_name(user),query_ip_port(user)));
}
int check_legal_id(string id)
{
	int i;
	string *banned_id;

	i = strlen(id);
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
		write("对不起，你的英文名字必须是 3 到 10 个英文字母。\n");
		return 0;
	}
	while(i--)
	if( id[i]<'a' || id[i]>'z' ){
		write("对不起，你的英文名字只能用英文字母。\n");
		return 0;
	}
	if ( file_size(CONFIG_DIR + "banned_ids") >=0 )
	{
		banned_id = explode(read_file(CONFIG_DIR + "banned_ids"), "\n");
	}
	else
	{
		i = sizeof(banned_id);
		while(i--)
		{
			write_file(CONFIG_DIR + "banned_ids",banned_id[i] + "\n", 0);
		}
	}
	for(i=0; i<sizeof(banned_id); i++) {
		if( strsrch(id, banned_id[i]) == -1) continue;
		write("对不起，这种英文名字会造成其他人的困扰。\n");
		return 0;
	}
	return 1;
}
int check_legal_name(string name)
{
	int i;
	string *banned_name;

	i = strlen(name);
	//write(sprintf("your input name len:(%d)",i));
	if( (strlen(name) < 1) || (strlen(name) > 4 ) )
	{
		write("对不起，你的中文名字必须是 1 到 4 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("对不起，你的中文名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}

	if ( file_size(CONFIG_DIR + "banned_name") >=0 )
	{
		banned_name = explode(read_file(CONFIG_DIR + "banned_name"), "\n");
	}
	else
	{
		i = sizeof(banned_name);
		while(i--)
		{
			write_file(CONFIG_DIR + "banned_name", banned_name[i] + "\n", 0);
		}
	}

	for(i=0; i<sizeof(banned_name); i++) {
		if( strsrch(name, banned_name[i]) == -1) continue;
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	if (name=="唐" || name=="段" || name=="欧阳" || name=="慕容" || name=="本")
	{
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	return 1;

}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&getuid(body[i]) == name ) return body[i];


	return 0;
}
int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level ) return 0;
	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	wiz_lock_level = level;
	return 1;
}
int set_lock(int i)
{
	mud_lock = i;
	return 1;
}
int check_legal_password(object ob,string pass)
{
	int i;
	int bigletter=0;
	int smlletter=0;
	string id;

	i = strlen(pass);
	if( strlen(pass) <= 6)   {
		write("对不起，你的密码必须最少六个字符。\n");
		return 0;
	}

	id = ob->query("id");
	if ( strsrch(id, pass) != -1 || strsrch(pass, id) != -1)
	{
		write("对不起，你的密码和你的英文名字太象了。\n");
		return 0;
	}

	while( i-- ) {
		if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

	}
	if( bigletter == 0 || smlletter == 0 || bigletter + smlletter == strlen(pass) )
	{
		write("您的密码必须包含" HIR "大写" NOR "和" + HIR "小写英文字母" NOR
			"以及" HIR "其它字符" NOR "，例如：Mud-123。\n");
		return 0;
	}

	return 1;
}
