// lottery ticket 彩票
// Design By Robert 蝴蝶君

inherit ITEM;

void create()
{
	set_name("彩票",({ "lottery ticket","ticket" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
一张由武林列传发行的彩票，每张彩票可以任意填写一组号码，然后参加
每两个星期一次的抽奖仪式。

你可以使用指令：

dengji 		登记你所要买的号码，一张彩票可以登记7个号码。
duijiang	对奖专用，检查你所购买的彩票是否中奖。
chayue		查阅你已经登记了的号码。

LONG);
		set("value",100000);
		set("unit","张");
		set("buy_time",time());
		set("no_sell",1);
		set("no_pawn",1);
		set("no_get_from",1);
		set("no_put",1);
		set("no_give",1);
		set("no_beg",1);
		set("no_drop",1);
		set("no_get",1);
	}
	setup();
}
void init()
{
	if(environment() == this_player())
	add_action("do_register","dengji");
	add_action("do_check","duijiang");
	add_action("do_checknum","chayue");
}
int do_register(string arg)
{
	object me;
	string *my_num,Nnum;
	int i,num;

	me = this_player();


	if(!arg || sscanf(arg,"%d",num) !=1)
		return notify_fail("指令格式：dengji <号码> \n");
	
	if(num <= 0 || num > 47)
		return notify_fail("你只能等级 1 － 47 的号码。 \n");
	
	Nnum = sprintf("%d",num);
	my_num = me->query("buy_number");

	if(my_num && member_array(Nnum,my_num) != -1)
		return notify_fail("你这个号码已经登记了。\n");

	for(i=0;i<sizeof(my_num);i++){
		if( i > 5)
			return notify_fail("你登记的号码已经满了。\n");
	}

	if( !pointerp(my_num) )
		me->set("buy_number", ({ Nnum }) );
	else
		me->set("buy_number",my_num + ({ Nnum }));

	tell_object(me,sprintf("你在彩票上写上了 %s 。\n",Nnum));
	return 1;
}
int do_check(string arg)
{
	object me = this_player();
	
	if(!id(arg)) return 0;
	if(!me->query("buy_number"))
		return notify_fail("你还没有预选号码。\n");
	if(sizeof(me->query("buy_number")) < 7)
		return notify_fail("你预定的号码不足七个。\n");

	"/adm/daemons/lotd"->check_number(me,me->query("buy_number"),this_object());
	return 1;
}
int do_checknum(string arg)
{
	object me = this_player();
	string *num;
	
	if(!id(arg)) return 0;
	if(!me->query("buy_number"))
		return notify_fail("你并没有登记号码。\n");
	num = me->query("buy_number");
	tell_object(me,"你已经登记的号码为：" + implode(num, ", ") + "。\n");
	return 1;
}
int query_autoload(){ return 1;}
void owner_is_killed(){ destruct(this_object());} 
