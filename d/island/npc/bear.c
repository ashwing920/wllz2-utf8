//Cracked by Kafei
// laohu.c 老虎

inherit NPC;

void create()
{
	set_name("白熊", ({ "bai xiong", "xiong", "bear" }) );
	set("race", "野兽");
	set("age", 25);
	set("long", "这头大白熊，毛长身巨，竟和大牯牛相似，张牙舞爪，狰狞可怖！\n");
	set("attitude", "aggressive");
	set("str", 60);
	set("con", 60);
	set("dex", 30);
	set("int", 10);
	set("combat_exp", 30000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  50);
	set_weight(150000);
	set("chat_chance", 10);
	set("chat_msg", ({
		"白熊在地上打了个滚，张嘴打了个哈欠。\n",
		"白熊微微侧着脑袋，双目炯炯，紧紧地注视着你的一举一动。\n",
		"白熊在绕着你走了半圈，不时仰头吼叫！\n",
	}) );
	set("chat_msg_combat", ({
		"\n白熊人立起来，提起巨掌，便要拍落！\n",
	}) );

	setup();
}
void init()
{
	object ob;

	if( interactive(ob = this_player()) && ob->query_weight() >= 50000) {
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}
}
