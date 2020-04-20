// rat.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老鼠", ({ "rat" }));
	set("long", @LONG
这是一只老鼠。
LONG
);
	set("race", "野兽");
	set("age", 3);
	set("str", 24);
	set("cor", 26);
	set("combat_exp", 100);
	set("eatable",1);
	set("afterdie","/clone/food/rat-meat");
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 2);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 20);

	setup();
}
