// kedian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家当地居民开的鸡毛小店，楼下卖些卤菜和劣酒，楼上则是客
房。这是在进祈连山区前的唯一休息之处，贩夫走卒，采药客等皆在此休
憩，不时还可看见一两个寻仙访道之辈。墙上有一块牌子(sign)，西面是
一间马厩。
LONG
);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"sign" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
		"/d/hangzhou/npc/xiaoer" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"majiu",
		"east" : __DIR__"yongdeng",
		"up"   : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
	 return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就住旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

