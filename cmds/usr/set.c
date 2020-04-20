//set.c

#define MAX_ENV_VARS    20

#include <ansi.h>

int help();

inherit F_CLEAN_UP;

string *all_settings = ({
	"brief","combat","no_accept","no_tell","wimpy","public","invisibility",
	"immortal","file_name","msg_home","msg_min","msg_mout","msg_clone","msg_dest",
	"trace_error","no_emote","no_whisper","no_color","no_other_msg","show_news",
	"auto_regenerate","prompt","drop_food","chat_color","idle","no_more","no_story",
	"msg_none",
});
string *wiz_only = ({
	"invisibility", "immortal","file_name","msg_home","msg_min","msg_mout",
	"msg_clone","msg_dest","trace_error","msg_none",
});
string *color = ({
	"HIW","HIC","HIB","HIM","HIG","HIY","HIR",
	"WHT","CYN","BLU","MAG","GRN","YEL","RED",
});
string *prompt_set =({
	"time","status","force","file_name","exp","pot","shen","shaqi",
});
int main(object me, string arg)
{
	int i;
	string term, *terms;
	mixed data;
	string data0;
	mapping env;


	if( me != this_player(1) ) return 0;

	env = me->query("env");
	if( !arg || arg=="" ) {
		write("你目前设定的环境变数有：\n");
		if( !mapp(env) || !sizeof(env) )
			write("\t没有设定任何环境变数。\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "1";
	}

	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");

	data0 = data;
	sscanf(data,"%d",data);

	if( member_array(term,all_settings) == -1 )
		return notify_fail("你只能使用系统所提供的设定，请使用 help settings 查阅！\n");

	if(!wizardp(me) && member_array(term, wiz_only) != -1)
		return notify_fail("只有巫师才能使用这个设定。\n");

		if(data == data0) {
			if(term == "prompt" && member_array(data,prompt_set) == -1)
				return notify_fail("prompt 没有这项参数，请查阅 help settings \n");
			if(term == "chat_color" && member_array(data,color) == -1)
				return notify_fail("目前不支持这种聊天颜色，请查阅 help nick。\n");
			if(data == "file_name" && !wizardp(me))
				return notify_fail("你不是巫师，不能使用这个变量。\n");
			if((term == "brief" || term == "wimpy" || term == "invisibility"
			|| term == "immortal") && !intp(data))
				return notify_fail("这个变量设置后必须是一个数值。\n");
			if(!wizardp(me) && strlen(data) > 80 )
				return notify_fail("你设置的信息太长了。\n");
			if(term == "prompt" || term == "chat_color")
				me->set("env/" + term,data);
			else
				me->set("env/" + term,data + NOR);
				
		}
			else  me->set("env/" + term, data);          /* is 数字 */
			printf("设定环境变数：%s = %O\n", term, data);
			return 1;
	}
	return help();
}

int help()
{
	write(@TEXT
指令格式：set <变数名> [<变数值>]

这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。

取消变数设定请用 unset 指令。

至於有哪些环境变数可以设定，请见 help settings。
TEXT
	);
	return 1;
}
