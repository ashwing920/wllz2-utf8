// qingtuoluohua.c

inherit ITEM;

void create()
{
	set_name("青陀螺花", ({ "qingtuo luohua", "tuoluo", "hua" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵产之西域的青陀螺花，据说是有毒植物。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}

int is_yaocai(){ return 1;}
