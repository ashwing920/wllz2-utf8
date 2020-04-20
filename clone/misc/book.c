// blade-book.c

inherit BOOK;

#include <ansi.h>

void create()
{
	set_name("书本",({ "book","shu"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value",0);
		set("material", "paper");
		set("bcolor", BRED);    // 书的整体颜色
		set("lcolor", WHT);     // 书的装订线颜色
		set("fcolor", BWHT);    // 书的标题框颜色
		set("tcolor", BLK);     // 书的标题颜色
	}
}
