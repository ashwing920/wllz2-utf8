// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);
private void create() {seteuid(getuid());}
int main(object me, string arg)
{
	string target, msg, mud,msgg,*frd_list;
	object obj;

	if(!arg || sscanf(arg, "%s %s", target, msg)!=2) return help(me);
	if(sscanf(target, "%s@%s", target, mud)==2) {
		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);

	if(!wizardp(me) && me->query_condition("no_speak"))
		return notify_fail("你支支吾吾的，半天也说不出句话来。\n");

	if(me->ban_say()) return 0;
	if(!obj || !me->visible(obj))
		return notify_fail("没有这个人....。\n");

	if( obj == me)
		return notify_fail("告诉自己？你烦不烦呀？\n");

	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");


	if(!living(obj))
		return notify_fail(obj->name()+"现在无法听到你的话！\n");


	frd_list = obj->query("my_friends");

	if(obj->query("env/no_tell") && !wizardp(me)){
		if(pointerp(frd_list) && member_array(me->query("id"),frd_list) == -1)
			if( stringp(msgg = obj->query("env/no_tell")))
				return notify_fail(CYN+ obj->name() + msgg + NOR"\n");
			else
				return notify_fail("对方不想听你罗嗦，有事请用聊天频道。\n");
	}

	write(WHT"『私语』"+HIG "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
		tell_object(obj, sprintf(WHT"『私语』"+HIG "%s告诉你：%s\n" NOR,me->name(2),msg));

	obj->set_temp("reply", me->query("id"));
	if(obj->query_temp("netdead")) tell_object(me, HIW "对方现在是断线状态，可能不会回答你哦！\n" NOR);
	else if(interactive(obj) && query_idle(obj)>120) tell_object(me, sprintf(HIW + "对方现在已发呆了" + HIY + " %d " + HIW  + "分钟，可能不会回答你哦！\n" + NOR, query_idle(obj)/60));
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if(ob = find_player(to)) {
		if(cname) tell_object(ob, sprintf(WHT"『私语』"+HIG "%s「%s@%s」告诉你：%s\n" NOR,
			cname, capitalize(from), mud, msg));
		else tell_object(ob, sprintf(WHT"『私语』"+HIG "%s@%s 告诉你：%s\n" NOR,
			capitalize(from), mud, msg));
		ob->set_temp("reply", from + "@" + mud);
		return (string)ob->query("name");
	}
	else return 0;
}

int help(object me)
{
	write(@HELP

指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。如果你不将接受对方的信息
，可以用set no_tell来拒绝。

例如：  set no_tell 不在，有事写信联系。

	如有人tell robert，将会得到以下信息：

	蝴蝶君不在，有事写信联系。

其他相关指令：reply

HELP
	);
	return 1;
}
