// pink_cloth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红玫瑰" NOR, ({ "red rose", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一束包装精美的红玫瑰，上面附着一张卡片(card)，好象还写着什么。\n");
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
	write(MAG"亲爱的"+query("target")+"：\n");
	write(@TEXT

　　仅以红玫瑰一束，送给我心中最深爱的你。我对你的爱，就象这束玫
瑰花一样，永远盛开灿烂。不论到天涯海角，海枯石烂，我都一如既往，
深深的爱着你，想念着你。


TEXT);
	write("\t\t\t\t爱你的："+ query("master")+"留。\n"NOR);
	return 1;
}