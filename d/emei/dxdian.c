//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: dxdian.c 大雄殿

inherit ROOM;

void create()
{
	set("short","大雄殿");
	set("long",@LONG
这里是报国寺大雄殿。报国寺是峨嵋山最大寺院之一。大雄殿内供着
金光灿灿的佛像，气宇轩昂。
LONG
);
	set("objects", ([
		__DIR__+"npc/guest": 2,
	]));
	set("exits",([
		"west"	 : __DIR__"bgschanfang",
		"out"	  : __DIR__"bgs",
		"north"	: __DIR__"cangjinglou",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();

	if( (!mapp(myfam = me->query("family")) || myfam["family_name"] != "峨嵋派") && dir == "west")
		return notify_fail("保国寺禅房只接待峨嵋弟子，你要是诚心礼佛，在此多进几注香吧。\n");
	return ::valid_leave(me, dir);
}
