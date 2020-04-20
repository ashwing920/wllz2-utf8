// seller-bqp.c - 兵器铺老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
int ask_changename();

void create()
{
        set_name("冷心", ({ "leng xin", "leng","seller" }) );
        set("title","兵器铺老板");
        set("long", @LONG
他就是这间兵器铺的老板。满脸堆笑，看起来十分热情。
LONG
);

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);

        set("combat_exp",40000+random(20000));
        set("env/wimpy", 30);

        set_skill("unarmed", 40);
        set_skill("parry",40);
        set_skill("dodge",40);
	set("inquiry",([
		"改名":		(: ask_changename :),
		"命名":		(: ask_changename :),
	]));
        set("vendor_goods", ([
        	"/clone/weapon/feihuangshi":1,
        	"/clone/weapon/fork":1,
                "/clone/weapon/blade": 1,
                "/clone/weapon/fork.c": 1,
                "/clone/weapon/gangdao.c": 1,
                "/clone/weapon/gangjian.c": 1,
                "/clone/weapon/gangzhang.c": 1,
                "/clone/weapon/longsword.c": 1,
                "/clone/weapon/qimeigun.c": 1,
                "/clone/weapon/staff.c": 1,
                "/clone/weapon/steelstaff.c": 1,
                "/clone/weapon/stick.c": 1,
                "/clone/weapon/sword.c": 1,
                "/clone/weapon/tiejia.c": 1,
                "/clone/weapon/tudao.c": 1,
                "/clone/weapon/whip.c": 1,
                "/clone/weapon/wood_blade.c": 1,
                "/clone/weapon/wood_sword.c": 1,
                "/clone/weapon/zhubang.c": 1,
                "/clone/weapon/zhujian.c": 1,
                "/clone/weapon/changqiang": 1,
                "/clone/weapon/duanjian": 1,
                "/clone/weapon/cbiao": 1,
                "/clone/weapon/fdao": 1,
                "/clone/weapon/xlongquan": 1,
        ]) );

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
}

void init()
{
        object ob;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
	add_action("do_changename","改");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if( this_object()->query_temp("unconcious") ) return;
        switch( random(1) ) {
                case 0:
                        say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，想买兵器吗？\n");
		break;
        }
}

int ask_changename()
{
	object me;
	mapping weapon;
	me = this_player();
	weapon = me->query("weapon");

	if(!me->query("weapon")) {
		command("say 你还没有自造兵器呢！");
		return 1;
	}
	if(weapon["lv"] <= 1){
		command("say 由于等级太低，你的"+ weapon["name"] + CYN"已经不能再改名了。");
		return 1;
	}
	command("say 如果想改"+ weapon["name"] +CYN"的名称，会造成"+ weapon["name"]+CYN"降低一个等级。");
	command("say 要是你想清楚了，就请输入（改 新兵器的名称）");
	me->set_temp("change_wname",1);
	return 1;
}

int do_changename(string arg)
{
	string w_name;
        object me,ob;
        me = this_player();
        ob = this_object();
        w_name= me->query("weapon/name");

	if(!me->query_temp("change_wname")) return 0;

	if( !arg || arg ==" ")
		return notify_fail(ob->name()+"说道：请输入：改 <新名字> \n");

	if(arg == w_name)
		return notify_fail(ob->name()+"说道：你这不是没事找事做吗？\n");

	if(!CHECK_D->check_obj_name(arg)) return notify_fail(ob->query("name")+"摇了摇头道：抱歉！你不能使用这种名字！\n");

        message_vision("$N将$n的"+ w_name +"接过，瞬刻间将剑身上的字迹擦去，刻上了"+ convert_color(arg) + NOR"。\n",ob,me);
	me->delete_temp("change_wname");
	me->set("weapon/name",convert_color(arg) +NOR);
	me->add("weapon/lv",-1);
	me->save();
        message_vision("$N将"+ convert_color(arg) +NOR"交给$n说道：好了，拿去吧！\n",ob,me);
	tell_object(me,"你的兵器新名称将在下次连线生效。\n");
        return 1;
}