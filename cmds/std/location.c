// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *place_desc = ({
	"客店" ,
	"武庙" ,
	"中心广场" ,
	"青石大道" ,
	"山路" ,
	"大驿道"
});
int main(object me, string arg)
{
	object ob,where;
	mapping fam;
	int sp, dp;
	int cost;

	seteuid(getuid());

	if ( !arg )
		return notify_fail("你要打听谁的所在？\n");

	if ( me->query_skill("count",1) < 10 )
		return notify_fail("你的阴阳八卦尚未纯熟，无法了解别人的所在！\n");

	if((!(fam = me->query("family")) || fam["family_name"] != "桃花岛") )
		return notify_fail("你运用阴阳八卦掐指一算，冥冥中却总觉得缺了些什么。\n");

	if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，你有问题吧？\n");

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob) return notify_fail("你要打听谁的所在？\n");
	if(!wizardp(me) && wizardp(ob))
		return notify_fail("你要打听谁的所在？\n");

	if ( ob == me )
		return notify_fail("你没这麽笨吧，要别人告诉你自己的所在？\n");

	cost = me->query("max_jing")/(me->query_skill("count",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的所在。\n");

	message_vision("只见$N盘膝坐下，双手内握，口中念念有词，忽然脸露微笑：有了！\n\n",me);

	sp = me->query_skill("count",1)*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;

	if ( random(sp) < random(dp)/2 )
		return notify_fail( "你又颓然坐下，摇了摇头，说道：不对的！\n");

	if(cost < 0) cost = 10;

	me->receive_damage("jing", cost );
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在哪里耶...\n");
	if ( random(sp) < random(dp) )
	{
		if (strsrch(file_name(where), "city4") >= 0)
			return notify_fail( ob->name()+"现在在长安城！\n");
		if (strsrch(file_name(where), "city3") >= 0)
			return notify_fail( ob->name()+"现在在成都城！\n");
		if (strsrch(file_name(where), "city2") >= 0)
			return notify_fail( ob->name()+"现在在北京城！\n");
		if (strsrch(file_name(where), "city") >= 0)
			return notify_fail( ob->name()+"现在在扬州城！\n");
		if (strsrch(file_name(where), "dali") >= 0)
			return notify_fail( ob->name()+"现在在大理城！\n");
		if (strsrch(file_name(where), "death") >= 0)
			return notify_fail( ob->name()+"现在在地狱里！\n");
		if (strsrch(file_name(where), "emei") >= 0)
			return notify_fail( ob->name()+"现在在峨眉山上！\n");
		if (strsrch(file_name(where), "foshan") >= 0)
			return notify_fail( ob->name()+"现在在佛山镇！\n");
		if (strsrch(file_name(where), "fuzhou") >= 0)
			return notify_fail( ob->name()+"现在在福州城！\n");
		if (strsrch(file_name(where), "gaibang") >= 0)
			return notify_fail( ob->name()+"现在在丐帮里！\n");
		if (strsrch(file_name(where), "guanwai") >= 0)
			return notify_fail( ob->name()+"现在在关外！\n");
		if (strsrch(file_name(where), "hangzhou") >= 0)
			return notify_fail( ob->name()+"现在在杭州城！\n");
		if (strsrch(file_name(where), "heimuya") >= 0)
			return notify_fail( ob->name()+"现在在黑木崖上！\n");
		if (strsrch(file_name(where), "hengshan") >= 0)
			return notify_fail( ob->name()+"现在在恒山上！\n");
		if (strsrch(file_name(where), "henshan") >= 0)
			return notify_fail( ob->name()+"现在在衡山上！\n");
		if (strsrch(file_name(where), "henshan") >= 0)
			return notify_fail( ob->name()+"现在在衡山上！\n");
		if (strsrch(file_name(where), "huanggon") >= 0)
			return notify_fail( ob->name()+"现在在皇宫大内里！\n");
		if (strsrch(file_name(where), "huashan") >= 0)
			return notify_fail( ob->name()+"现在在华山上！\n");
		if (strsrch(file_name(where), "lingjiu") >= 0)
			return notify_fail( ob->name()+"现在在灵鹫峰上！\n");
		if (strsrch(file_name(where), "mingjiao") >= 0)
			return notify_fail( ob->name()+"现在在昆仑山上！\n");
		if (strsrch(file_name(where), "qingcheng") >= 0)
			return notify_fail( ob->name()+"现在在青城山上！\n");
		if (strsrch(file_name(where), "quanzhou") >= 0)
			return notify_fail( ob->name()+"现在在泉州城！\n");
		if (strsrch(file_name(where), "shaolin") >= 0)
			return notify_fail( ob->name()+"现在在少林寺里！\n");
		if (strsrch(file_name(where), "shenlong") >= 0)
			return notify_fail( ob->name()+"现在在神龙岛上！\n");
		if (strsrch(file_name(where), "songshan") >= 0)
			return notify_fail( ob->name()+"现在在嵩山上！\n");
		if (strsrch(file_name(where), "suzhou") >= 0)
			return notify_fail( ob->name()+"现在在苏州城！\n");
		if (strsrch(file_name(where), "taishan") >= 0)
			return notify_fail( ob->name()+"现在在泰山上！\n");
		if (strsrch(file_name(where), "taohua") >= 0)
			return notify_fail( ob->name()+"现在在桃花岛！\n");
		if (strsrch(file_name(where), "tianlongsi") >= 0)
			return notify_fail( ob->name()+"现在在天龙寺里！\n");
		if (strsrch(file_name(where), "village") >= 0)
			return notify_fail( ob->name()+"现在在华山村！\n");
		if (strsrch(file_name(where), "wudang") >= 0)
			return notify_fail( ob->name()+"现在在武当山上！\n");
		if (strsrch(file_name(where), "xiakedao") >= 0)
			return notify_fail( ob->name()+"现在在侠客岛上！\n");
		if (strsrch(file_name(where), "xiaoyao") >= 0)
			return notify_fail( ob->name()+"现在在逍遥派里！\n");
		if (strsrch(file_name(where), "xingxiu") >= 0)
			return notify_fail( ob->name()+"现在在星宿海！\n");
		if ((strsrch(file_name(where), "xuedao") >= 0) ||
		   (strsrch(file_name(where), "xueshan") >= 0))
			return notify_fail( ob->name()+"现在在大雪山上！\n");
		if (strsrch(file_name(where), "yanziwu") >= 0)
			return notify_fail( ob->name()+"现在在燕子坞！\n");
		if (strsrch(file_name(where), "gumu") >= 0)
			return notify_fail( ob->name()+"现在在终南山！\n");
		if (strsrch(file_name(where), "meizhuang") >= 0)
			return notify_fail( ob->name()+"现在在梅庄！\n");
		if (strsrch(file_name(where), "wanjiegu") >= 0)
			return notify_fail( ob->name()+"现在在万劫谷！\n");
		else return notify_fail( ob->name()+"现在在哪里呢？不知道啊！\n");
	}
	if (random(10)>7)
	{
		write(sprintf("%s现在在%s。\n",
			(string)ob->name(), place_desc[random(sizeof(place_desc))]));
		return 1;
	}
		write(sprintf("%s现在在%s。\n",
			(string)ob->name(),
			(string)where->query("short")));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: location <玩家的 ID>

这个指令是桃花岛弟子用来得知玩家目前所在的位置.

HELP
	);
	return 1;
}


