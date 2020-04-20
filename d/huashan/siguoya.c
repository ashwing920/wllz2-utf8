// siguoya.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "思过崖");
	set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山剑派历代弟子犯规后囚
禁受罚之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来相传是
玉女发钗上的一颗珍珠，当年华山剑派的祖师以此危崖为惩罚弟子之所，
主要是此处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，不致为外
物所扰，心有旁鹜。
LONG
);
	set("objects", ([
		CLASS_D("huashan")+"/linghu" : 1,
	]));
 
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"yunupath2",
		"enter"  : __DIR__"sgyhole1",
	]));
	set("outdoors", "huashan" );
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
	return;
}
