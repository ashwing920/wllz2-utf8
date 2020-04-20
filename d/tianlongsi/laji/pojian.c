// duanjian.c 断了的长剑
// xueer

inherit ITEM;

void create()
{
	set_name("断了的长剑", ({ "duan jian","sword"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把被折断的长剑。\n");
		set("value",10);
	}
	setup();
}
