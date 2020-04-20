// Room: /d/shaolin/gulou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "鼓楼小院");
	set("long", @LONG
这是一座砖木结构的宝塔，塔高七层，塔身作八角形，飞檐翘翎，檐
角上挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂空雕绘着无数佛陀
们的坐像。一个个形态维肖，看来出自名匠之手。塔底入口处开了一扇拱
形的小木门，门扇两侧用彩漆涂绘，画的是释祖在灵山对诸天众佛讲经时
的情形。
LONG
);
	set("exits", ([
		"east" : __DIR__"guangchang2",
		"enter" : __DIR__"gulou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;

	return ::valid_leave(me, dir);
}

