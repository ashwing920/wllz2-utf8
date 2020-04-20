// pink_cloth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"粉色玫瑰" NOR, ({ "pink rose", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一束包装精美的粉红玫瑰，上面附着一张卡片(card)，好象还写着什么。\n");
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
	write(HIM"我心中的"+ query("target")+"：\n");
	write(@TEXT

　　仔细回想，你我相识已有一段日子，从相遇到相知，一直以来，你都
对我不舍不弃。亲爱的，我将永远爱你，用我的一生，呵护着你，支持着
你！

TEXT);
	write("\t\t\t\t你心中的"+ query("master")+"留。\n"NOR);
	return 1;
}