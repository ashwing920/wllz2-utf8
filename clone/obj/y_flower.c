// pink_cloth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"黄玫瑰" NOR, ({ "yellow rose", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一束包装精美的黄玫瑰，上面附着一张卡片(card)，好象还写着什么。\n");
		set("unit", "束");
		set("value",0);
		set("material", "plant");
	}
	setup();
}
void init()
{
	if(environment() == this_player())
	add_action("do_look","look");
}
int do_look(string arg)
{
	if(!arg || arg == "" || arg !="card") return 0;
	write(YEL + query("target")+"：\n");
	write(@TEXT

　　对不起！我知道一束花并不能够弥补我犯下的错误，一直到现在，我
都为自己做过的事情而忏悔，请给我一次机会，原谅我的过错。

TEXT);
	write("\t\t\t\t"+ query("master")+"留。\n"NOR);
	return 1;
}