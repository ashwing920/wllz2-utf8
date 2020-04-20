// nboard.c 新闻板

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_news","news");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何留言 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf(HIC + "%s" + NOR + " [ %d 张留言，" + HIY + "%d" + NOR + " 张" + HIR + "未读" + NOR + "]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read;
	string msg;

	notes = query("notes");
	msg = query("long");
	msg = msg + "留言版的使用方法请见 help board。\n";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++)
		msg += sprintf("%s[%2d]" NOR +HIW" %-40s "NOR"%-18s[%10s]\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1, notes[i]["title"][0..38],notes[i]["author"], ctime(notes[i]["time"])[0..15] );

	this_player()->start_more(msg);
	return "\n";
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	mapping *notes;

	if(wizardp(me))
	note["msg"] = convert_color(text);
	else
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	if(this_player()->query("ink"))
	this_player()->set("inkdone",1);
	tell_object(me, "留言完毕。\n");
	save();
	return;
}

int do_post(string arg)
{
	mapping note;
	if(!arg) return notify_fail("留言请指定一个标题。\n");
	if(!wizardp(this_player()) && this_player()->query_skill("literate",1) < 10)
		return notify_fail("你还是个文盲，先去学点「读书识字」吧！\n");
	if(!wizardp(this_player()) && this_player()->query("mud_age") < 86400)
		return notify_fail("小孩子家，留言板不是你涂鸦的地方！\n");
	if(query("wiz_only") && !wizardp(this_player()))
		return notify_fail("这个留言板只有巫师才能够发布信息。\n");
	note = allocate_mapping(5);
	note["title"] = arg;
	note["author"] = this_player()->name(1)+"["+capitalize(this_player()->query("id"))+"]";
	note["time"] = time();
	(this_player()->query("ink") ? note["author_discribe"] = this_player()->query("ink"): "");
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}
int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;

	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	this_player()->start_more(
	sprintf("编号："HIY"%d"NOR"　作者："HIW"%-18s"NOR" 时间：[%s]\n标题："HIW"%s"NOR"\n────────────────────────────────────\n",
		num + 1, notes[num]["author"],ctime(notes[num]["time"]),notes[num]["title"][0..65])
		+ notes[num]["msg"] + (notes[num]["author_discribe"] ? "\n\n--------------------------\n"+notes[num]["author_discribe"]: ""));

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["author"] != (string)this_player()->name(1)+"["+capitalize(this_player()->query("id"))+"]"
	&&        (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
	&&        (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
		return notify_fail("这个留言不是你写的。\n");

	if(num == 0)
		notes = notes[num+1..sizeof(notes)-1];
	else
		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	return 1;
}
void show_news(object ob,int amount)
{
	int i,n,unread,reaed;
	mapping *notes,last_read_time;
	string myid;

	if( !ob || !environment(ob)) return;

	last_read_time = ob->query("board_last_read");
	notes = query("notes");
	myid = query("board_id");

	if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			n = 1;
		else
			for(n = 1; n<=sizeof(notes); n++)
				if( notes[n-1]["time"] > last_read_time[myid]) break;

	if( n < 1 || n > sizeof(notes) ){
		tell_object(ob,HIM"\n新闻精灵说道：嗯 . .最新消息已经为您发布完毕，祝您玩得愉快！\n\n"NOR);
		return;
	}
	n--;
	ob->start_more(
	sprintf(HIM"\n新闻精灵从怀里掏出一张新闻纸，朗声念道：嗯. . 这个最新消息是：\n\n"NOR"编号："HIY"%d"NOR"　作者："HIW"%-18s"NOR" 时间：[%s]\n标题："HIW"%-30s"NOR"\n────────────────────────────────────\n",
		n+1, notes[n]["author"], ctime(notes[n]["time"]),notes[n]["title"][0..30])
		+ notes[n]["msg"] + (notes[n]["author_discribe"] ? "\n\n--------------------------\n"+notes[n]["author_discribe"]: ""));

	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[n]["time"] ]) );
	else
		if( undefinedp(last_read_time[myid]) || notes[n]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[n]["time"];

	reaed = (int)ob->query("board_last_read/" + query("board_id"));
	for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= reaed ) break;

	call_out("show_news",15,ob,unread);
}
int do_news(string arg)
{
	int num,reaed,i,unread,flag =0;
	mapping *notes, last_read_time;
	string myid,msg,news="";

	msg = "目前泥潭中的新闻有：\n";
	msg += WHT"────────────────────────────────────\n"NOR;
	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes =query("notes");

	reaed = this_player()->query("board_last_read/" + myid);

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("目前没有任何未读过的新闻。\n");

	if( arg == "check"){
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
				if( notes[i]["time"] <= reaed ) break;
		if( unread ){
			tell_object(this_player(),sprintf(WHT"你目前共有 "HIY"%d"NOR + WHT" 条新闻尚未阅读，请使用 "HIY"news"NOR + WHT" 指令查阅。\n"NOR,unread));
			if(this_player()->query("env/show_news"))
			call_out("show_news",5,this_player(),unread);
		}
		else
			{
			tell_object(this_player(),sprintf("目前没有任何未读过的新闻。\n"));
		}
		return 1;
	}
	if(!arg || arg == "" ){
		i = sizeof(notes);
		while(i--){
			if(notes[i]["time"] <= reaed ) continue;
			if(notes[i]) flag = 1;
			news += sprintf(HIY"[%2d]"NOR" %-30s %12s [%s]\n",
				i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15]);
		}
		if(flag){
			msg = sprintf("%s%s",msg,news);
			msg += WHT"────────────────────────────────────\n"NOR;
			this_player()->start_more(msg);
		}
		else {
			write("目前没有任何未读过的新闻。\n");
		}
		return 1;
	}
	if( arg == "all") {
		for(i=0; i<sizeof(notes); i++)
			msg += sprintf("%s[%2d]"NOR" %-30s %12s [%s]\n",
				( notes[i]["time"] > reaed ? HIY: ""),
				i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
			msg += WHT"────────────────────────────────────\n"NOR;
			this_player()->start_more(msg);
			return 1;
	}
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;

	} else if(!sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张新闻？\n");

	if( num < 1 || num > sizeof(notes) ){
		write("没有这条新闻。\n");
		return 1;
	}

	num--;

	this_player()->start_more(
	sprintf("编号："HIY"%d"NOR"　作者：%-18s 时间：[%s]\n标题："HIW"%-30s"NOR"\n────────────────────────────────────\n",
		num + 1, notes[num]["author"], ctime(notes[num]["time"]),notes[num]["title"][0..40])
		+ notes[num]["msg"] + (notes[num]["author_discribe"] ? "\n\n--------------------------\n"+notes[num]["author_discribe"]: ""));

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}
