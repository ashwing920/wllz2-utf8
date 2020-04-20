// saoba.c
// Design By ymh 飞影 email:stcoolman@21cn.com

inherit COMBINED_ITEM;

void create()
{
	set_name("针线", ({ "twine","zhen xian" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","捆");
		set("long", "这是一捆缝补衣服用的针线。\n");
		set("material", "cloth");
		set("use_time",1000);
		set("value",300);
		set("base_unit", "小捆");
		set("base_weight",37);
	}
	set_amount(1);
}
