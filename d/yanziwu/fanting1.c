#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIY"厨房"NOR);
	set("long",@LONG
这是一间小厨房, 虽然不大, 但是锅碗瓢盆, 油盐酱醋, 到很奇全。灶台
上堆满了新鲜瓜果蔬菜, 活鱼活虾, 不仅不脏不乱, 还十分干净整齐。
LONG);
	set("objects", ([
		__DIR__"npc/obj/longjing-caiyeji" : 1,
		__DIR__"npc/obj/meihua-zaoya" : 1,
]));
		set("exits",([
		"west" : __DIR__"c15-0",
]));
	setup();

}
