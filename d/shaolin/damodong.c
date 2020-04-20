// Room: /d/shaolin/damodong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "达摩洞");
	set("long", @LONG
这里是达摩古洞。五百年前南天竺僧人菩提达摩来到少林寺，见此风
水宝地，就住下来广罗弟子，传授禅宗，开创少林寺佛教禅宗千年不败之
基。达摩祖师常在此面壁悟道，一坐十年，壁间隐隐似仍可看到他面壁时
的打坐姿态。除地上的几块竹片外，洞中空无一物。
LONG
);
	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));
	set("objects",([
		"/clone/book/book-bamboo" : 1,
		CLASS_D("shaolin")+"/da-mo" : 1,
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
}

void init()
{
	add_action("do_mianbi","面壁"); 
	add_action("do_mianbi","mianbi");       
}
int do_mianbi()
{
	int ski;
	object me = this_player();
	ski = me->query_skill("dodge",1);
	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) ){
		if((ski*ski*ski / 10) < (int)me->query("combat_exp")) 
			message_vision("$N面对着达摩洞後半边的石壁跌坐静思，良久，似有所悟。\n", me);
			me->receive_damage("jing",10);
			me->improve_skill("dodge",me->query("int"));
			me->set_busy(2);
			return 1;
		}
			else {
	message_vision("$N面对着达摩洞後半边的石壁跌坐静思，可许久也参悟不出个结果。\n", me);           
	return 1;
	}
}
