// femote.c
// 查询 emote 功能。

#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	mapping emote;
	string *e, *loop;
	string result="", msg;
	int i,count=0;

	loop = ({ "others_target", "others_self", "others" });
	if( !arg )
		return help(me);

	e = sort_array( EMOTE_D->query_all_emote(), 1);

	for(i=0; i<sizeof(e); i++) {
		emote = EMOTE_D->query_emote(e[i]);
		for( int j=0; j<sizeof(loop); j++ ) {
			msg = emote[ loop[j] ];
			if( msg && strsrch(msg, arg) >=0 ) {
				result += sprintf("emote 名："WHT"%s"NOR"\n动作：%s\n", e[i],msg);
				count ++;
			}
		}
	}
	if( count > 10)
		return notify_fail("查找到的符合条件的 emote 太多，请重新指定关键字进行搜索。\n");

	if(  result == "" )
		return notify_fail(code_name() + "中无符合该查询条件的 emote。\n");
	else
		result = "\n查询结果如下：\n────────────────────────────────────\n"
				+ result;
	result = replace_string(result, "$n", "(对方)");
	result = replace_string(result, "$N", me->name(1));
	result = replace_string(result, "$P", "你");
	result = replace_string(result, "$p", "(他/她)");
	result = replace_string(result, "$S", RANK_D->query_self(me));
	result = replace_string(result, "$s", RANK_D->query_self_rude(me));
	result = replace_string(result, "$R", "(对方的尊称)");
	result = replace_string(result, "$r", "(对方的辱称)");
	result = replace_string(result, "$C", "(自己的呢称)");
	result = replace_string(result, "$c", "(对方的呢称)");

	result += "────────────────────────────────────\n";
	result += sprintf("在%s中，包含“%s”的 emote 共有 %d 个。\n",code_name(),arg,count);
	me->start_more(result);
	return 1;
}

int help(object me)
{
  write(@HELP

指令格式：femote <字符串>。

这个指令可以在所有 emote 中寻找含有所指定的字符串的emote。

HELP
    );
    return 1;
}
