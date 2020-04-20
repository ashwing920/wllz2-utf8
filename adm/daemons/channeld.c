// channeld.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_DBASE;

string remove_addresses(string, int all);

mapping channels = ([
	"sys":	([
		"name":"系统频道","msg_speak": HIR "【系统】%s：%s\n" NOR,
		"msg_emote": HIR "【系统】%s" NOR,"wiz_only": 1,
		"msg_color": NOR+HIR,
	]),

	"chat": ([
		"name":"论道江湖","msg_speak": HIC "【论道江湖】%s：%s\n" NOR,
		"msg_emote": HIC "【论道江湖】%s" NOR,"msg_color": NOR+HIC,
	]),

	"rumor":([
		"name":"武林传奇","msg_speak": HIM "【武林传奇】%s：%s \n" NOR,
		"msg_emote": HIM "【武林传奇】%s" NOR,"anonymous": "某人","msg_color": NOR+HIR,
	]),

	"music":([
		"name":"轻歌妙韵","msg_speak": HIG "【轻歌妙韵】"NOR+WHT"%s唱著：%s\n" NOR,
		"msg_emote": HIG "【轻歌妙韵】"NOR+WHT"%s" NOR,"msg_color": NOR+WHT,
	]),

	"master":([
		"name":"武林宗师","msg_speak": WHT"【武林宗师】"WHT"%s：%s\n" NOR,
		"msg_emote": WHT "【武林宗师】"WHT"%s" NOR,"msg_color": NOR+WHT,
	]),

	"wiz":	([
		"name":"巫师频道","msg_speak": HIY"【巫师闲聊】%s：%s\n" NOR,
		"msg_emote": HIY"【巫师闲聊】%s" NOR,"msg_color": NOR+HIY,"wiz_only": 1,
	]),

	"arch": ([
		"name":"天神频道","msg_speak": HIW "【"HIG"天神议事"HIW"】%s：%s\n" NOR,
		"msg_emote": HIW "【"HIG"天神议事"HIW"】%s" NOR,"msg_color": NOR+HIW,"arch_only":1,"wiz_only":1,
	]),

	"debug":([
		"name":"调试频道",
		"msg_speak": HIW "【系统调试】%s：%s\n" NOR,"msg_emote": HIW "【系统调试】%s" NOR,
		"msg_color": NOR+HIW,"wiz_only": 1,
	]),

	"gwiz": ([
		"name":"网际巫师频道","msg_speak": HIG "【网际巫师】"+HIG+"%s：%s\n" NOR,
		"msg_emote": HIG "【网际巫师】"HIG"%s" NOR,"wiz_only": 1,"intermud": GCHANNEL,"intermud_emote": 1,
		"channel": "gwiz","filter": 1,"omit_address": 0, "msg_color": NOR+HIG,
	]),

	"party":([
		"name":"门派频道",
		"msg_speak": HIG "【%s】%s：%s\n" NOR,"msg_emote": HIG "【%s】%s" NOR,"msg_color": NOR+HIG,
	]),

	"es":	([
		"name":"网际聊天","msg_speak": HIG "【网际闲聊】%s：%s\n" NOR,
		"msg_emote": HIG "【网际闲聊】%s" NOR,"intermud": GCHANNEL,"intermud_emote": 1,"channel": "es",
		"filter": 1,"omit_address": 0, "msg_color": NOR+HIG,"wiz_only": 1,
	]),
/*
	"wllz":	([
		"name":"武林列传","msg_speak": HIW"【武林列传】"NOR + WHT"%s：%s\n" NOR,
		"msg_emote": HIW "【武林列传】"NOR + WHT"%s" NOR,"intermud": GCHANNEL,"intermud_emote": 1,"channel": "wllz",
		"filter": 1,"omit_address": 0, "msg_color": NOR+WHT,
	]),
*/
	"tt"  :([
		"name":"队伍","msg_speak": WHT "【队伍】%s：%s\n"NOR,
		"msg_emote": WHT "【队伍】%s"NOR,"msg_color": NOR+WHT,
	]),

	"banghui":([
		"name":"帮会","msg_speak": WHT"【%s"NOR + WHT"】%s：%s\n" NOR,"msg_emote": WHT "【%s"NOR + WHT"】%s"NOR,
		"msg_color": NOR+WHT,
	]),

	"frds":	([
		"name":"江湖好友","msg_speak": WHT "【江湖好友】%s：%s\n"NOR,
		"msg_emote": WHT "【江湖好友】%s"NOR,"msg_color": NOR+WHT,
	]),

	"dealer":([
		"name":"商贸交易",
		"msg_speak": HIY"【商贸交易】%s：%s\n"NOR,"msg_color": NOR+HIY,
	]),

]);
void create()
{
	seteuid(getuid());
	set("channel_id", "频道精灵");
}
varargs int do_channel(object me, string verb, string arg, int emote,int remote)
{
	object *ob;
	string *tuned_ch, who;
	object *team;
	string arg_bk,self_emote,last_arg;
	self_emote=arg;

// 先检测是否使用频道 emote

	if( verb[sizeof(verb)-1] == '*') {
		emote = 1;
		verb = verb[0..<2];
	}
// 确定存在这个频道

	if(channels[verb] && !wizardp(me) && userp(me)){
		if((int)me->query("chblk/all"))
			return notify_fail("你的所有频道都被关闭了。\n");
		if((int)me->query("chblk/"+ verb))
			return notify_fail("你的"+ channels[verb]["name"] +"频道被系统关闭了！\n");
		if(channels[verb]["block"])
			return notify_fail(channels[verb]["name"]+"频道被系统完全关闭了！\n");
		if(channels[verb]["anonymous"]){
			if( me->query("jing") < 50)
				return notify_fail("你已经没有精力散布谣言了。\n");
			me->receive_damage("jing",50);
		}
	}

	if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

// Check if this channel support emote message.
	if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
		write("对不起，这个频道不支持 emote 。\n");
		return 1;
	}
// Now we can be sure it's indeed a channel message:
	if (!stringp(arg) || arg == "" || arg == " ") arg = "...";
	else arg_bk = arg;

	if(remote) arg_bk = arg;

	if(verb && living(me)) {
		if( me->ban_say()) return 0;
		if( channels[verb]["wiz_only"] && !wizardp(me)) return 0;
		if( channels[verb]["arch_only"] && wiz_level(me)<wiz_level("(arch)")) return 0;
		if(!wizardp(me)){
			if((time() - (int)me->query("register_time")) < 900)
				return notify_fail("你必须于注册十五分钟后才可以使用公聊频道进行聊天。\n在这个时间里，请先看["HIG"help"NOR"]系统帮助文件，了解本游戏的运作。\n");
			if(me->query_condition("no_speak"))
				return notify_fail("你支支吾吾的，半天也说不出句话来。\n");
			if( channels[verb]["intermud"]){
				if((int)me->query("combat_exp") < 500000)
					return notify_fail("以你现在的能力，还不足以使用这个频道。\n");
				if((int)me->query("jing") < 200)
					return notify_fail("你的精力不足，无法使用武林列传频道。\n");
				me->receive_damage("jing",100);
			}
			if( verb == "master" && !wizardp(me) && !(int)me->query("is_zongshi"))
				return notify_fail("以你现在的能力还不能使用宗师频道。\n");
			last_arg = (string)me->query_temp("last_channel_msg");
			if( verb && arg && last_arg
			&& (arg==last_arg  || strsrch(last_arg,arg)!=-1 || strsrch(arg,last_arg)!=-1))
				return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
			me->set_temp("last_channel_msg", arg);
		}

		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
		me->set("channels", tuned_ch + ({ verb }) );
	}

	if( emote  && me->is_character() && !remote) {
		string vb, emote_arg, id, mud;

	if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
		vb = arg;
		emote_arg = "";
	}

	if( channels[verb]["intermud_emote"] && sscanf(emote_arg, "%s@%s", id, mud)==2 ) {
		REMOTE_Q->send_remote_q(mud, verb, me->query("id"), id, vb);
		write("网路讯息已送出，请稍候。\n");
		return 1;
	}

	arg = EMOTE_D->do_emote(me, vb, emote_arg, 3);

	if( verb == "rumor")
		arg = EMOTE_D->do_emote(me, vb, emote_arg, 2,
		(random(100) > 10 || wizardp(me) || !userp(me))? channels[verb]["anonymous"]:me->name(2));
		else arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);

	if (!arg && emote == 2) {
		arg = (channels[verb]["anonymous"] ?
			channels[verb]["anonymous"] : me->name()) + vb + "\n";
		if( verb == "rumor")
				arg = sprintf("%s%s\n",(random(100) > 10 || wizardp(me) || !userp(me))?
				channels[verb]["anonymous"]:me->name(2),vb);
			else
				arg = sprintf("%s%s\n",channels[verb]["anonymous"],vb);
		}
	}

	// Make the identity of speaker.
	if( channels[verb]["anonymous"] ) {
		if(userp(me) && !wizardp(me)) {
			who = random(100) > 10 ? channels[verb]["anonymous"]:me->name(2);
			do_channel( this_object(), "sys", sprintf("%s正在造谣。",me->name(2)));
		}
		else    who = channels[verb]["anonymous"];
	}

	else if(me && (userp(me) || !stringp(who = me->query("channel_id")))) {
	if (me->name()!=me->name(1) && emote)
		do_channel( this_object(), "sys", sprintf("%s扮%s！", me->name(2),me->name()));
		who = me->name(2);
	}
	if(verb=="tt"){
		if (!arrayp(team = me->query_team()) && (verb == "tt" || verb == "tt*") )
			return notify_fail("你现在没有加入任何队伍！\n");
		ob = filter_array(children(USER_OB), "team_listener", this_object(),me->query_team());
	}
	else if (verb=="party"){
		if (!me->query("family"))
			return notify_fail("你还没有加入任何门派！\n");
		ob=filter_array(children(USER_OB),"family_listener", this_object(), me->query("family/family_name") );
	}
	else if( verb == "frds"){
		if(!pointerp(me->query("my_friends")) || !sizeof(me->query("my_friends")))
			return notify_fail("你目前还没有设置任何好友。\n");
		ob = filter_array(children(USER_OB), "friend_listener", this_object(),me,me->query("my_friends"));
	}
	else if( verb =="banghui") {
		if( !me->query("clan"))
			return notify_fail("你还没有加入任何帮会！\n");
		ob=filter_array(children(USER_OB),"banghui_listener", this_object(), me->query("clan/name") );
	}
	else
		ob = filter_array(children(USER_OB),"filter_listener", this_object(), channels[verb] );

	if( emote ) {
		string localmsg;
		string ecol=channels[verb]["msg_color"];
		if(remote) {
			arg=arg_bk;
		}

		if (!stringp(arg)) return 0;
		localmsg = arg;

	if ( channels[verb]["msg_emote"] )
		localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

	if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
	else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);

	if(!stringp(localmsg)) return 0;
	if(verb=="party")
	message( "channel:" + verb,sprintf( channels[verb]["msg_emote"],me->query("family/family_name"), replace_string(localmsg,NOR,ecol) ), ob );
	else if(verb=="banghui")
	message( "channel:" + verb,sprintf( channels[verb]["msg_emote"],me->query("clan/name"), replace_string(localmsg,NOR,ecol) ), ob );
	else
	message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob );
	}
	else
	if (verb=="party")
	message( "channel:" + verb,sprintf( channels[verb]["msg_speak"],me->query("family/family_name"),who,arg ), ob );
	else if (verb=="banghui")
	message( "channel:" + verb,sprintf( channels[verb]["msg_speak"],me->query("clan/name"),who,arg ), ob );
	else
	message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg ), ob );

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	if( !undefinedp(channels[verb]["intermud"]) && me->is_character()) {
		channels[verb]["intermud"]->send_msg(
		channels[verb]["channel"], me->query("id"), me->name(1),arg, emote,
		channels[verb]["filter"] );
	}

	return 1;
}

int filter_listener(object ppl, mapping ch)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;

	if( ch["arch_only"])
	if( userp(ppl) )
	if( wiz_level(ppl) < wiz_level("(arch)") )
	return 0;

	if( ch["wiz_only"] )
	if( userp(ppl) )
	return wizardp(ppl);

	return 1;
}
void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
string remove_addresses(string msg, int all)
{
	int i;
	mixed tmp;
	string pattern;
	if(!stringp(msg)) return msg;
	if( all )
	pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
	else
	pattern = "[(][A-Za-z]+@"+Mud_name()+"[)]";

	tmp = reg_assoc(msg, ({pattern}), ({1}));

	if(!arrayp(tmp)) return msg;
	msg = "";
	for(i=0; i< sizeof(tmp[0]); i++)
	if( tmp[1][i] == 0 ) msg += tmp[0][i];
	return msg;
}
int family_listener(object ppl, string str)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl)) return 0;
	if(wizardp(ppl) || ppl->query("family/family_name")==str ) return 1;
	else return 0;
}
int banghui_listener(object ppl, string str)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl)) return 0;
	if(wizardp(ppl) || ppl->query("clan/name")==str ) return 1;
	else return 0;
}
int team_listener(object ppl,object *team_ob)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl)) return 0;
	if(wizardp(ppl) || member_array(ppl,team_ob) != -1 ) return 1;
	else return 0;
}
int friend_listener(object ppl,object my,string *friend_list)
{
	if( !environment(ppl)) return 0;
	if(wizardp(ppl) || (member_array(ppl->query("id"),friend_list) != -1
	&& ppl->query("my_friends") && member_array(my->query("id"),ppl->query("my_friends"))!= -1) || ppl == my) return 1;
	else return 0;
}
// 设置rumor、chat频道开关
int set_block(string channel, int d)
{
	if(channel) channels[channel] += ([ "block": d ]);
	return 1;
}
mapping query_channels()
{
	return channels;
}