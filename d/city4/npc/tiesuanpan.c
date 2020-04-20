// tiesuanpan.c
 
inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("铁算盘",  ({"tie suanpan",  "tie",  "zhanggui"}));
	set("title",  "钱庄掌柜");
	set("gender",  "男性");
	set("age",  54);
	set("qi",  800);  
	set("max_qi",  800);
	set("jing",  200);
	set("max_jing",  200);
	set("combat_exp",  50000);
	set("attitude",  "friendly");
	set("env/wimpy",  50);
	set("chat_chance",  10);
	set_skill("unarmed",  60);
	set_skill("parry",  60);
	set_skill("dodge",  60);

	setup();
	carry_object(__DIR__"obj/choupao")->wear();
	add_money("gold",  1);
}
void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}
