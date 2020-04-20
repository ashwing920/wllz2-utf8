// arrest.c

#include <ansi.h>

void create(){ seteuid(getuid());}
int help(object me);

int main(object me, string arg)
{
	object ob;
	string type,place;

	if( me!=this_player(1) ) return 0;

	if(!arg) return help(me);

	if(sscanf(arg, "%s because %s",arg,type) == 2 ){
		if(!objectp(ob = find_player(arg)))
			return notify_fail("咦... 没有这个人？\n");

		if(!playerp(ob) || !ob->is_character() || ob==me )
			return notify_fail("你只能逮捕玩家。\n");
	
		if( wiz_level(ob) > wiz_level(me))
			return notify_fail("以下犯上？活得不耐烦了啊！\n");
	
		switch(type){
			case "flood":
			case "FLOOD":
				message_system("由于胡言乱语，"+ ob->name(2)+"被系统送到了厕所漱口。");
				ob->move("/adm/parsion/cesuo");
				ob->set("startroom","/adm/parsion/cesuo");
				ob->apply_condition("is_flood",200);
				ob->disable_player("<漱口中>");
				break;
			case "block":
			case "BLOCK":
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
	else if(sscanf(arg,"-u %s",arg) == 1){
		ob = LOGIN_D->find_body(arg);

		if(!ob)
			return notify_fail("咦... 没有这个人？\n");

		if(!playerp(ob) || !ob->is_character() || ob==me )
			return notify_fail("你只能释放玩家。\n");
		
		if( ob->query_condition("is_flood") < 1
		&&  ob->query_condition("is_block") < 1)
			return notify_fail("这个人目前不属于囚禁当中。\n");
		
		if(ob->query_condition("is_flood"))
			ob->apply_condition("is_flood",1);
		
		if(ob->query_condition("is_block"))
			ob->apply_condition("is_block",1);
		
		write(ob->name()+"已被批准释放，等候系统处理。\n");
		return 1;
	}
	else return help(me);		
			
}
int help(object me)
{
	write(@Help

指令格式：

逮捕玩家：arrest <某人> because <原因>
释放玩家：arrest -u <某人>

目前通常使用的原因有两种，一个是：FLOOD，另外一个是 BLOCK

FLOOD 主要是将那些喜欢造谣生事，辱骂玩家的人抓进厕所。
BLOCK 是把那些捣乱，破坏游戏秩序的人抓进暗房。

两者关闭时间不同，依据情节严重而定。

Help
	);
	return 1;
}
