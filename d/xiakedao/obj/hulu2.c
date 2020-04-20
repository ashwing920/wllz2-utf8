//hulu2.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("葫芦", ({"bhulu", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个蓝色的葫芦。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 3);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "药酒",
		"remaining": 3,
		"drunk_supply": 10,
	]));
}
