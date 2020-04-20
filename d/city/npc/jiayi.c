// shenxian-shizhe.c

#include <ansi.h>
#include <command.h>
#include <localtime.h>

inherit NPC;
void get_yuebing(object ob);
void get_wllz_gift(object ob);
void create()
{
	set_name("贾翌", ({"jia yi", "jia", "yi"}));
	set("long", @LONG
他是一个鹤发童颜的老者，上知天文下知地理，曾经闯荡江湖，也结交了
不少江湖人士。后来就来到这间客栈里，当起了说书先生，生活也倒逍遥
自在。想打听一些江湖上的奇人异事，找他就对了。
LONG
	);

	set("title","英雄楼说书先生");
	set("nickname",HIC"神算子"NOR);

	set("rank_info/respect", "先生");
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 44);

	set("str", 30);         // 膂力
	set("cps", 30);         // 定力
	set("cor", 30);         // 胆识
	set("per", 30);         // 容貌
	set("int", 30);         // 悟性
	set("con", 30);         // 根骨
	set("spi", 30);         // 灵性
	set("kar", 30);         // 福缘

	set("combat_exp", 20000000);
	setup();
	carry_object("/clone/misc/cloth")->wear();

}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_ask", "ask");
}
void get_gift(object ob)
{
	object o;
	int i, a, n;

	command("say 小小礼物，就请收下吧。");

	a = ob->query("age");
	n = ( ob->query("gender") == "女性" ) ? 16 : 18;
	if( n < a ) {
		for( i = n; i < a; i ++ ) {
			o = new("/clone/money/thousand-cash");
			o->move(ob,1);
		}
		tell_object(ob, this_object()->name() + "给你" + chinese_number( a - n )
			+ o->query("unit") + o->name() + "。\n" );
	}

	n = random( 1000 ) + 200;
	ob->add("potential", n);
	tell_object(ob, "你的潜能上升了" + chinese_number(n) + "点。\n");
	n = random( 1500 ) + 500;
	ob->add("combat_exp", n);
	tell_object(ob, "你的经验上升了" + chinese_number(n) + "点。\n");

	if( random( 3 ) == 0 && ob->query("kar") < 30 ) {
		ob->add("kar", 1);
		tell_object(ob, "你的福缘上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("spi") < 30 ) {
		ob->add("spi", 1);
		tell_object(ob,"你的灵性上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("per") < 30 ) {
		ob->add("per", 1);
		tell_object(ob, "你的相貌上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("dex") < 30 ) {
		ob->add("dex", 1);
		tell_object(ob, "你的身法上升了一点。");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("int") < 30 ) {
		ob->add("int", 1);
		tell_object(ob, "你的悟性上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("str") < 30 ) {
		ob->add("str", 1);
		tell_object(ob, "你的膂力上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("con") < 30 ) {
		ob->add("con", 1);
		tell_object(ob, "你的根骨上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	if( random( 3 ) == 0 && ob->query("cor") < 30 ) {
		ob->add("cor", 1);
		tell_object(ob, "你的定力上升了一点。\n");
		if( random(7) != 0 ) return;
	}
	return;
}
void get_wllz_gift(object ob)
{
	object ob1,ob2,ob3;

	command("say 这是武林列传巫师组的一点小礼物，请收下吧。");
	ob1 = new("/clone/wizard/zhu-guo");
	ob1->move(ob,1);
	ob2 = new("/clone/wizard/xisuidan");
	ob2->move(ob,1);
	ob3 = new("/clone/wizard/huantongdan");
	ob3->move(ob);
	log_file("get_gift",sprintf("%s,%s[%s]由贾翌处领取了武林列传诞生一周年礼物。\n",ctime(time()),ob->name(1),geteuid(ob)));
	ob->save();
	return;
}

void get_small_gift(object ob)
{
	int n;

	command("say 小小礼物，就请收下吧。");

	n = random( 400 ) + 200;
	ob->add("potential", n);
	tell_object(ob, "你的潜能上升了" + chinese_number(n) + "点。\n");

	n = random( 1000 ) + 500;
	ob->add("combat_exp", n);
	tell_object(ob, "你的经验上升了" + chinese_number(n) + "点。\n");

}

void greeting(object ob)
{
	mixed *t;

	// 以下加入节日的礼物
	if( !ob || environment(ob) != environment() ) return;

	t = localtime(time());
	if( t[LT_MON] == 0 && t[LT_MDAY] == 1 ) {       // 一月一日
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，元旦到啦，节日快乐！");
		if( ob->query("gift/date") != "元旦" ) {
			ob->set("gift/date", "元旦");
			get_gift(ob);
		}
		return;
	}
	if( (t[LT_MON] == 0 && t[LT_MDAY] == 24 )
	|| (t[LT_MON] == 0 && t[LT_MDAY] == 25 )) {      // 春节（一月二十四日 2001）
		command("say 这位" + RANK_D->query_respect(ob) + "，春节到啦，节日快乐！");
		if( ob->query("gift/date") != "春节" ) {
			ob->set("gift/date", "春节");
			get_gift(ob);
		}
		return;
	}
	if( t[LT_MON] == 4 && t[LT_MDAY] == 1 ) {       // 五月一日
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，劳动节到啦，节日快乐！");
		if( ob->query("gift/date") != "劳动节" ) {
			ob->set("gift/date", "劳动节");
			get_gift(ob);
		}
		return;
	}

	if( (t[LT_MON] == 9 && t[LT_MDAY] == 1) 
	|| (t[LT_MON] == 9 && t[LT_MDAY] == 2) 
	|| (t[LT_MON] == 9 && t[LT_MDAY] == 3)) {       // 十月一日
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，国庆节到啦，节日快乐！");
		if( ob->query("gift/date") != "国庆节" ) {
			ob->set("gift/date", "国庆节");
			get_gift(ob);
		}
		return;
	}
	if( t[LT_MON] == 2 && t[LT_MDAY] == 6 ) {       // 三月六日
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，武林列传诞生日到啦，节日快乐！");
		if( ob->query("gift/date") != "诞生日" ) {
			ob->set("gift/date", "诞生日");
			get_wllz_gift(ob);
		}
		return;
	}

	if( t[LT_MON] == 2 && t[LT_MDAY] == 8
	&&      ob->query("gender") == "女性" && stringp(ob->query("marry")) ) {
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，妇女节到啦，节日快乐！");
		if( ob->query("gift/date") != "妇女节" ) {
			ob->set("gift/date", "妇女节");
			get_small_gift(ob);
		}
		return;
	}
	if( t[LT_MON] == 5 && t[LT_MDAY] == 1           // 六月一日
	&&      ob->query("age") <= 16 ) {
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，儿童节到啦，节日快乐！");
		if( ob->query("gift/date") != "儿童节" ) {
			ob->set("gift/date", "儿童节");
			get_small_gift(ob);
		}
		return;
	}
	if( t[LT_MON] == 11 && t[LT_MDAY] == 25 ) {     // 圣诞节
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，圣诞节到啦，节日快乐！");
		if( ob->query("gift/date") != "圣诞节" ) {
			ob->set("gift/date", "圣诞节");
			get_small_gift(ob);
		}
		return;
	}

	if( t[LT_MON] == 8 && t[LT_MDAY] == 15 ) {     // 圣诞节
		command("smile " + ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，中秋佳节到啦，别忘了回家团圆喔！");
		if( ob->query("gift/date") != "中秋节" ) {
			ob->set("gift/date", "中秋节");
			get_yuebing(ob);
		}
		return;
	}
	if(environment(ob))
	command("smile " + ob->query("id"));
	command( "say 这位" + RANK_D->query_respect(ob) + "，想算一卦吗？");
}

int do_ask(string arg)
{
	object ob, me = this_player();
	string tempstr, name;
	int str, cor, ntg, spi, dex, per, con, kar;

	if(!arg || sscanf(arg, "%s about %s", tempstr, name) != 2)   return 0;

	if(name == "成年" && !(int)me->query("gift/grown") && me->query("age") >= 18) {
		command("smile " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "，恭喜成年！");
		me->set("gift/grown", 1);
		get_gift(me);
		return 1;
	}
	if(name == "新婚" && !(int)me->query("gift/marry") && stringp(me->query("marry"))) {
		command("smile " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "，新婚快乐！");
		me->set("gift/marry", 1);
		get_gift(me);
		return 1;
	}
	if(name == "大寿" && !(int)me->query("gift/birthday30") && me->query("age") == 30) {
		command("smile " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "，三十大寿快乐！");
		me->set("gift/birthday30", 1);
		get_gift(me);
		return 1;
	}
	if(name == "大寿" && !(int)me->query("gift/birthday50") && me->query("age") == 50) {
		command("smile " + me->query("id"));
		command("say 这位" + RANK_D->query_respect(me) + "，五十大寿快乐！");
		me->set("gift/birthday50", 1);
		get_gift(me);
		return 1;
	}

	if(!objectp(ob = find_player(name)) )   return 0;
	if(!me->query_temp("give_me_money") ) {
		command("say 五两银子一卦，先交钱吧。");
		return 1;
	}
	me->delete_temp("give_me_money");

	str = ob->query("str");
	cor = ob->query("cor");
	ntg = ob->query("int");
	spi = ob->query("spi");
	dex = ob->query("cps");
	per = ob->query("per");
	con = ob->query("con");
	kar = ob->query("kar");

	switch(random(6)) {
		case 0 :
			if( str + cor + ntg + spi + dex + per + con + kar
				> (ob->query("age") + 6) * 8) {
				command("nod");
				command("say 不错，"+ob->name()+"还算修练有方。");
			}
			else {
				command("sigh");
				command("say "+ob->name() + "还要在基本功上多下点功夫！");
			}
			break;
		case 1 :
			if(ntg > 35 || ntg > 15 + ob->query("age") ) {
				command("nod");
				command("say "+ob->name()+"天资过人，若能多加努力，必定能出人头地。");
			}
			else {
				command("shake");
				command("say "+ob->name()+"如果知道＂笨鸟先飞＂的道理，还是有机会的。");
			}
			break;
		case 2 :
			if(spi > 25) {
				command("nod");
				command("say "+ob->name()+"如果有意钻研武学，倒也不难成为一代宗师。");
			}
			else {
				command("shake");
				command("say "+ob->name()+"应该专精几门武功，不可以贪多。");
			}
			break;
		case 3 :
			if(per > 26) {
				command("smile");
				command("say "+ob->name()+"相貌非凡，一定有不少人追求。");
			}
			else {
				command("hmm");
				if(ob->query("marry"))
					command("say "+ob->name()+"看来好不容易才找到一位情侣。");
				else
					command("say "+ob->name()+"在婚姻生活上看来是要多历磨难了。");
			}
			break;
		case 4 :
			if(kar > 22) {
				command("smile");
				command("say "+ob->name()+"福缘深厚，吉人自有天相。");
			}
			else {
				command("sigh");
				command("say "+ob->name()+"这一生看来是注定要多历磨难了。");
			}
			break;
		case 5 :
			if(ob->query("combat_exp") > (ob->query("age") - 14) * 10000 ) {
				command("smile");
				command("say "+ob->name()+"闯荡江湖这么多年，看来还是学到不少东西。");
			}
			else {
				command("shake");
				command("say "+ob->name()+"闯荡江湖多年，竟然虚渡了许多光阴。");
			}
			break;
		}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !ob->query("money_id") || ob->value() < 500 )
		return 0;
	who->set_temp("give_me_money", 1);

	return 1;
}
void get_yuebing(object ob)
{
	int i;
	object o;

	command("gongxi "+ob->name());
	for( i = 0; i < 4; i ++ ) {
		o = new("/clone/wizard/yue-bing");
		o->move(ob,1);
	}
	ob->save();
	message_vision("贾翌给$N一些"+o->query("name")+"。\n", ob);
	return ;

}
