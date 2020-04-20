// tune.c

inherit F_CLEAN_UP;

#include <ansi.h>

object find_body(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	string *tuned_ch;
	object ob;

	tuned_ch = me->query("channels");
	if( !arg ) {
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("你现在并没有收听任何频道。\n");
		else
			write("你现在收听的频道：" + implode(tuned_ch, ", ") + "。\n");
		return 1;
	}
	if(arg == "tell"){
	if( wizardp(me))
		ob = find_body(me->query_temp("reply"));
		if(me->query_temp("reply") && ob && ob->query_temp("reply") == me->query("id")){
			tell_object(me,HIG"你关闭了和"+ ob->name() + "「"+ ob->query("id") +"」的通话。\n"NOR);
			tell_object(ob,HIG + me->name()+ "「"+ me->query("id") +"」关闭和你的通话。\n"NOR);
			me->delete_temp("reply");
			ob->delete_temp("reply");
			return 1;
		}
			else {
				tell_object(me,"你没有和任何人说过话。\n");
				return 1;
			}

	}
	if(arg == "all"){
		if( !me->query("channels"))
			return notify_fail("你的所有频道已经关闭了！\n");
		write("你关闭了所有频道的信息，恢复所有频道请用"HIG"tune cancel \n"NOR);
		me->delete("channels");
		return 1;
	}
	if(arg == "cancel"){
		if( me->query("channels"))
			return notify_fail("你的所有频道已经打开了！\n");
		write("你开始收听所有频道的信息了。\n");
		if( wizardp(me))
			me->set("channels",({ "chat","rumor","music","news","party","wllz","banghui","wiz","gwiz","sys","debug","es","master","frds","tt","dealer"}) );
		else
			me->set("channels",({ "chat","rumor","music","news","party","wllz","master","frds","tt","dealer"}) );
		return 1;
	}
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("关闭 " + arg + " 频道。\n");
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		return 1;
	} else {
		write("要打开某个频道只要用该频道说话即可。\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式：tune [<频道名称>]

这个指令让你选择是否要收听某一频道的讯息，如果没有指定频道名称，就会列出
你目前收听中的频道，如果指定了频道，原来收听中的就会关掉，反之打开。

如果你对一个没有收听中的频道讲话，会自动将它打开。
要对一个频道讲话，只要用：

<频道名称> <讯息> ....

例子：
  chat hello everyone!

你可以用 help channels 查询目前有哪些频道可以收听。

例子：

  tune all

你可以用这个参数不收来自于任何频道的信息！

例子：

  tune cancel

你可以用这个参数，来打开所以频道的信息！

HELP
	);
	return 1;
}

