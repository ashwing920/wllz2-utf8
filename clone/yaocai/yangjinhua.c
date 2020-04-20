// yangjinhua.c

inherit ITEM;

void create()
{
	set_name("洋金花", ({ "yang jinhua", "yang", "jinhua" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("long", "这是一朵洋金花。\n");
		set("value", 30);
		set("material", "grass");
		set("cure_s",15);
		set("cure_d",10);
		set("cure_n",72);
	}
	setup();
}
int is_yaocai(){ return 1;}