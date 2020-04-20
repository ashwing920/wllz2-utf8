//Cracked by Kafei
// wu.c 吴老板

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("吴老板", ({ "wu laoban", "wu" }));
	set("title", "万国烟雨楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long", "吴老板一手开创的万国烟雨楼驰名泉州。\n");
	set("combat_exp", 60000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);

	set("vendor_goods", ([
		__DIR__"obj/hdjiudai":1,
		__DIR__"obj/fotiao":1,
	]));

	setup();
	add_money("gold", 1);
}

void init()
{
	add_action("do_vendor_list", "list");
}

