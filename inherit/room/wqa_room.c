// wqa_room.c

#include <ansi.h>

inherit ROOM;

string *levels = ({
	"九等村干部",
	"八等乡干部",
	"七等芝麻官",
	"六等绿豆官",
	"五等番薯官",
	"四等冬瓜官",
	"三等万户猴",
	"二等大官僚",
	"一等封建王",
});

string *good_msg = ({
	"德行圆满", "为民请命", "为民父母", "执法不阿", "不徇私情",
	"不畏权贵", "正直无私", "犯颜进谏", "持法公允", "执法严明",
	"同情人民疾苦", "锐意改革弊政", "政绩颇多", "口碑极佳", "造福于民",
	"减租减息", "兴修水利", "反对豪强兼并土地", "增加国家财政收入", "减轻民众负担",
	"鼓励科学研究", "促进文化交流", "抵抗强敌入侵", "开发矿产资源", "参加人民起义",
});

string *bad_msg = ({
	"徇私舞弊", "贪污受贿", "贪赃枉法", "横征暴敛", "残忍无情",
	"独断专行", "乱玩女人", "搞同性恋", "鱼肉百姓", "逼良为娼",
	"放荡淫佚", "穷奢极欲", "贪污腐败", "强占土地", "违法乱纪",
	"乱兴土木", "蛀空国库", "政绩很坏", "名声很臭", "兼并土地",
	"打击科学研究", "打击文化交流", "作了卖国汉奸", "盗卖矿产资源", "起兵造反",
});

void use_start_card( object ob );
void use_go_card( object ob, int i );
void use_back_card( object ob, int i );
void use_luck_card( object ob );
void use_whammy_card( object ob );

void setup()
{
	::setup();
}

void create()
{
	seteuid(getuid());
	set("name", "青史");
	set("id","^_^");
	set("channel_id","青史");
	set("restrict_enter_room", 1);
	set("restrict_action", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("no_steal", 1);
	setup();
}

// 获取当地的位置号码值
int query_posi_number() 
{
	string str;
	int num;

	str = base_name(this_object());
	sscanf( str[<2..<1], "%d", num );
	return num;

}

// 移动到指定号码的位置
int moveto_spec_position( object ob, int num )
{
	string str;

	str = base_name(this_object());

	if( num <= 0 ) num += 80;
	if( num > 80 ) num %= 80;
	ob->move( str[0..<3] +sprintf("%c%c", '0' + num / 10, 
		'0' + num % 10) );

	return num;
}

string something_good(object ob)
{
	return good_msg[ random( sizeof( good_msg ) ) ];
}

string something_bad(object ob)
{

	return bad_msg[ random( sizeof( bad_msg ) ) ];
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_go", "go");
	add_action("do_quit", "quit");
	add_action("do_nothing", "summon");
}

void greeting(object ob)
{
	object card;
	string str, national;
	int new_point, i, n, lucky;
	if( !ob || environment(ob) != this_object() ) return;

	new_point = 0;

	// 每次加入社会声望值
	new_point += random(4) + 1;
/*
	set("name","青史");
	set("id","^_^");
*/
	// 得到卡片：均望卡，平望卡，
	if( random(50) == 0 ) {
		card = new("/d/wqa/obj/go_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(50) == 0 ) {
		card = new("/d/wqa/obj/back_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}

	else if( random(100) == 0 ) {
		card = new("/d/wqa/obj/start_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(100) == 0 ) {
		card = new("/d/wqa/obj/luck_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(100) == 0 ) {
		card = new("/d/wqa/obj/whammy_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(200) == 0 ) {
		card = new("/d/wqa/obj/all_average_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(200) == 0 ) {
		card = new("/d/wqa/obj/average_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}
	else if( random(200) == 0 ) {
		card = new("/d/wqa/obj/get_card");
		card->move(ob);
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ "得到" + card->query("name") + "！\n" NOR, ob);
	}

		// 运气的判断
		lucky = 0;
		if( ob->query_temp("wqa's room/luck") > 0 ) {
			// 运气好时
			lucky = 1;
		}
		else if( ob->query_temp("wqa's room/luck") < 0 ) {
			// 运气坏时
			lucky = -1;
		}


	// 增加或者减少（这里受到运气影响）
	if( random(20 - lucky * 10 ) == 0 ) {
		message_vision( HIY "$N在" + this_object()->query("short") 
			+ something_good(ob) + "....\n" NOR, ob);
		new_point += random(20);
	}
	else if( random(30 + lucky * 15 ) == 0 ) {
		message_vision( HIR "$N在" + this_object()->query("short") 
			+ something_bad(ob) + "....\n" NOR, ob);
		new_point -= random(30);
	}

	ob->add_temp("wqa's room/point", new_point);
	if(ob->query_temp("wqa's room/point") < 0) ob->set_temp("wqa's room/point", 0);

	if( new_point > 0 )
		tell_object( ob, HIC "\n由于你的努力，你的社会声望增加了" 
			+ chinese_number(new_point) + "点。\n" NOR );
	else
		tell_object( ob, HIC "\n由于你的失败，你的社会声望降低了" 
			+ chinese_number(-new_point) + "点。\n" NOR );

	// 升官或者降职，这里可以显示给大家看到
	if( random(40) == 0 ) {
		new_point = ob->query_temp("wqa's room/point");
		for( i = 0, n = 100; i < 9; i ++ ) {    // 最初是 150 :)
			if( new_point < n ) break;
			n *= 2;
		}
		if( i > 0 ) {
			national = ob->query("national");
			str = this_object()->query("short") + levels[i-1];
			CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_good(ob)
				+ "，" + ob->name() + "获得“" + str + "”的职位！" );
			ob->set("title",str);
		}
	}

	// 运气
	if( random(80) == 0 ) {
		CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_good(ob)
			+ "，" + ob->name() + "被福神附身！" );
		use_luck_card( ob );
	}
	else if( random(80) == 0 ) {
		CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_bad(ob)
			+ "，" + ob->name() + "被衰神附身！" );
		use_whammy_card( ob );
	}

	// 重新开始
	if( random(80) == 0 ) {
		use_start_card( ob );
		CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_bad(ob)
			+ "，" + ob->name() + "被梦幻时空一脚踢回起点！" );
	}
	// 前进
	else if( random(40) == 0 ) {
		i = random(10) + 1;
		use_go_card( ob, i );
		CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_good(ob)
			+ "，" + ob->name() + "在梦幻时空中前进" 
			+ chinese_number(i) + "步！" );
	}
	// 后退
	else if( random(40) == 0 ) {
		i = random(10) + 1;
		use_back_card( ob, i );
		CHANNEL_D->do_channel(this_object(), "chat", "由于" + something_bad(ob)
			+ "，" + ob->name() + "在梦幻时空中后退" 
			+ chinese_number(i) + "步！" );
	}
}

int do_go(string arg)
{
	object me;
	string tempstr;
	
	me = this_player();

	if(me->query_temp("dream") == 1) {
		write("你现在正忙着呢！\n");
		return 1;
	}

		if(me->query_temp("sleeping") ==1){
				write("你还没醒过来，不能移动！\n");
				return 1;
		}

	me->set_temp("wqa's room/flag", 1);

	tempstr = CYN "\n$N把一粒时空骷子向空中一抛：“起！”\n" NOR;
	message_vision(tempstr, me);

	me->set_temp("dream", 1);
	call_out( "compelete_dream", 3, me );

	return 1;
}

private void compelete_dream(object me)
{
	object env;
	string tempstr;
	int now_num, go_num, i;

	if( !me || environment(me) != this_object() ) return;
	me->delete_temp("dream");

	if( present(me) ) {                     // 如果玩家还在原地

		env = environment(me);

		// str = base_name(env);
		// sscanf( str[<2..<1], "%d", now_num );

		now_num = query_posi_number();

		i = random(6) + 1;

		tempstr = CYN "\n时空骷子落了下来，上面的数字是：" 
			+ chinese_number(i) + "。\n" NOR;

		message_vision(tempstr, me);

		if( me->query_temp("wqa's room/luck") > 0 ) {
			// 运气好时，每次走的点数＊２
			message_vision( HIY "$N鸿运当头，前进的点数加倍！\n" NOR, me);
			me->add_temp("wqa's room/luck", -1);
			i *= 2;
		}
		else if( me->query_temp("wqa's room/luck") < 0 ) {
			// 运气坏时，每次走的点数一点至二点
			message_vision( HIR "$N霉运当头，每次最多只能走两格！\n" NOR, me);
			me->add_temp("wqa's room/luck", 1);
			i = random(2) + 1;
		}

		message("vision", CYN "可是...." + me->name() 

			+ "已经不见了。\n" NOR, this_object(), ({me}));

		go_num = now_num + i;
		if( go_num > 80 ) go_num = go_num % 80;

	// tell_object( me, CYN "你现在的位置是：第" + chinese_number(now_num) + "格。\n" NOR );

		// me->move( str[0..<3] +sprintf("%c%c", '0' + go_num / 10, '0' + go_num % 10) );
		moveto_spec_position(me, go_num);

		tempstr = CYN "\n$N穿越时空，来到第" + chinese_number(go_num) 
			+ "格。\n" NOR;
		me->set_temp("wqa's room/change",0);
		message_vision(tempstr, me);
	}
	return;
		
}

int do_quit(string arg)
{
	object me;
	string tempstr;
	
	me = this_player();

	// 当退出时，清除标志。我想还是保留点数
	me->set_temp("wqa's room/flag", 0);
	me->set_temp("wqa's room/change", 0);

	    // 强行清掉 dream 的标志。  99-03-11 Key bye ten@tianxia
	me->delete_temp("dream");
	
	tempstr = CYN "\n突然间天上有个声音大声叫道：“$N！快些醒来吧！”\n""然后，一阵香风卷来。风中仿佛有许多人影在晃动....\n" NOR;
	message_vision(tempstr, me);

	message("vision", CYN "可是...." + this_player()->name() + "已经不见了。\n" NOR, this_object(), ({this_player()}));
	this_player()->move("/d/center/guangchang");

	tempstr = CYN "只见$N揉了揉眼睛，清醒过来。\n" NOR;
	message_vision(tempstr, me);

	return 1;
}

int do_nothing(string arg)
{
	return 1;
}

void use_start_card( object ob )
{
	message_vision( HIR "\n“呜哇！”从天空上伸出一只大手，把$N捉了去....\n" NOR, ob);

	ob->move("/d/wqa/01");

	message( "vision", HIW "\n你的眼前突然出现一团白色的光芒，"
		+ ob->name() + "出现在你眼前！\n" NOR, environment(ob), ({ ob }) );
		// Key By Ten@Tianxia 99-03-25  防止因为被使用用卡片导致的不能移动。
		ob->delete_temp("dream");
}

void use_go_card( object ob, int i )
{
	message_vision( HIY "\n“哐当！”天上落下一只大白骷子，掉在$N面前....\n"
		"$N上前仔细一看，原来是个" + chinese_number(i) + "点！\n" NOR, ob);

	moveto_spec_position( ob, this_object()->query_posi_number() + i );

	message( "vision", HIW "\n你的眼前突然出现一团白色的光芒，"
		+ ob->name() + "出现在你眼前！\n" NOR, environment(ob), ({ ob }) );
		// Key By Ten@Tianxia 99-03-25  防止因为被使用用卡片导致的不能移动。
		ob->delete_temp("dream");

}

void use_back_card( object ob, int i )
{
	message_vision( HIR "\n“哐当！”天上落下一只大黑骷子，掉在$N面前....\n"
		"$N上前仔细一看，原来是个" + chinese_number(i) + "点！\n" NOR, ob);

	moveto_spec_position( ob, this_object()->query_posi_number() - i );

	message( "vision", HIW "\n你的眼前突然出现一团白色的光芒，"
		+ ob->name() + "出现在你眼前！\n" NOR, environment(ob), ({ ob }) );
		// Key By Ten@Tianxia 99-03-25  防止因为被使用用卡片导致的不能移动。
		ob->delete_temp("dream");

}

void use_luck_card( object ob )
{
	int i ;
	
	i = random(15) + 5;
	message_vision( HIY "\n仙乐响起，福神将无数鲜花洒在$N身上...."
		"$N开始鸿运当头" + chinese_number(i) + "次。\n" NOR, ob);
	ob->add_temp("wqa's room/luck", i );
}

void use_whammy_card( object ob )
{
	int i ;
	
	i = random(15) + 5;
	message_vision( HIR "\n“哗！”，衰神将一桶秽物淋在$N身上...."
		"$N开始霉运当头" + chinese_number(i) + "次。\n" NOR, ob);
	ob->add_temp("wqa's room/luck", -i );
}
