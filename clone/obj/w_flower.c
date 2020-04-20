// pink_cloth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"白玫瑰" NOR, ({ "white rose", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一束包装精美的白玫瑰，上面附着一张卡片(card)，好象还写着什么。\n");
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
	write(WHT + query("target")+"：\n");
	write(@TEXT

　　仅以白玫瑰一束，送给我最真挚友情的朋友，愿我们的友谊天长地久！

TEXT);
	write("\t\t\t\t最珍惜你的朋友："+ query("master")+"留。\n"NOR);
	return 1;
}