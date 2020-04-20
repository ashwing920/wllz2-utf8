// lottery boy 票童
// Design By Robert 蝴蝶君

inherit NPC;
inherit F_VENDOR;

string ask_dengji();

void create()
{
	set_name("票童",({ "lottery boy","boy"}));
	set("long",@LONG
他是负责售卖、登记彩票的票童。
LONG);
	set("gender","男性");
	set("age",19);
	set("inquiry",([
		"登记": (: ask_dengji() :),
	]));
	set("vendor_goods", ([
		"/clone/misc/lottery_ticket": 1,
	]));
	carry_object("/clone/cloth/cloth")->wear();
	setup();
}
void init()
{
	add_action("do_vendor_list", "list");
}
string ask_dengji()
{
	object me = this_player();
	
	if(!me->query("buy_number"))
		return "你还没有登记预选号码。";
	
	if(sizeof(me->query("buy_number")) < 7)
		return "你的登记号码不足 7 个。";
	
	"/adm/daemons/lotd"->do_register(me,100000);
	return "好吧，我帮你看看！";
}
