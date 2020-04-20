// arrest.c

#include <ansi.h>

void create(){ seteuid(getuid());}

int main(object me, string arg)
{
	object ob;
	string type,place;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s because %s",arg,type) != 2 )
		return notify_fail("指令格式 : arrest <某人> because <原因>\n");

	ob = LOGIN_D->find_body(arg);

	if(!ob)
		return notify_fail("咦... 没有这个人？\n");

	if(!living(ob) || !ob->is_character() || ob==me )
		return notify_fail("搞错了吧，这个怎么能逮捕呢？\n");

	if( wiz_level(ob) > wiz_level(me))
		return notify_fail("以下犯上？活得不耐烦了啊！\n");

	seteuid(getuid());

	switch(type){
		case "flood":
			message_system("由于胡言乱语，"+ ob->name(2)+"被系统送到了厕所漱口。");
			ob->move("/adm/parsion/cesuo");
			ob->set("startroom","/adm/parsion/cesuo");
			ob->apply_condition("is_flood",200);
			ob->disable_player("<漱口中>");
			break;
		case "block":
			message_system("由于行为不检，"+ ob->name(2)+"被系统送到了暗房面壁思过。");
			ob->move("/adm/parsion/jianyu");
			ob->set("startroom","/adm/parsion/jianyu");
			ob->apply_condition("is_block",300);
			ob->disable_player("<面壁中>");
			break;
		default:
			write("没有这样的原因。\n");
			break;
	}
	return 1;
}
int help(object me)
{
	write(@Help
指令格式 : arrest <某人> because <原因>

Help
	);
	return 1;
}
