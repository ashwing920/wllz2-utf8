inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIM"七"HIR"心"HIG"海棠"NOR, ({"qixin haitang", "haitang"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "江湖上最神秘的毒药，无色无嗅。\n");
                set("unit", "对");
		set("owner_name","袁紫衣");
		set("owner_id","yuan ziyi");
        }
}

