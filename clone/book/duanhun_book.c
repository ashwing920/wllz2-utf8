// 断魂抢法

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("断魂抢法", ({"duanhun book","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("no_sell",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_pawn",1);
		set("no_steal",1);
		set("no_beg",1);
		set("no_put",1);
		set("no_get",1);
		set("no_get_from",1);
		set("is_monitored",1);
		set("value",0);
		set("material", "paper");
		set("bcolor", BCYN);    // 书的整体颜色
		set("lcolor", WHT);     // 书的装订线颜色
		set("fcolor", BWHT);    // 书的标题框颜色
		set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	"duanhun-qiang",	// name of the skill
			"exp_required":	5000000,	// minimum combat experience required
			"jing_cost": 100+random(20),// jing cost every time study this
			"difficulty":80,	// the base int to learn this skill
			"max_skill": 199,	// the maximum level you can learn
		]) );
	}
}
int query_autoload(){ return 1;}
void owner_is_killed(){ destruct(this_object());} 
