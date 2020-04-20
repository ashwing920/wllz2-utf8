//Cracked by Kafei
// xu.c 许老板/d/quanzhou/npc/xu.c
// modified by aln  2 / 98

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("许老板", ({ "xu laoban", "xu" }));
	set("title", "鸿翔绸缎庄老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "鸿翔绸缎庄乃是许老板祖传的生意，到许老板已是第四代了。\n");
	set("combat_exp", 10000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);

	set("vendor_goods", ([
		__DIR__"obj/gua":1,
		__DIR__"obj/jin_ao":1,
		__DIR__"obj/red_cloth":1,
		__DIR__"obj/qun":1,
		__DIR__"obj/guazi":1,
		__DIR__"obj/green_beixin":1,
		__DIR__"obj/xiupao":1,
		__DIR__"obj/zhouqun":1,
		__DIR__"obj/chaoxue":1,
	]));
	setup();
	add_money("silver", 50);
}
void init()
{
	add_action("do_vendor_list", "list");
}
