// Room: /d/shaolin/cjlou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其匹。这里
都是密密麻麻，高及顶棚的书架，书架间仅有容身一人通行的空隙。几排
大书架中间，间隔地放着数丈长的书桌。目光及处，你看到桌上放了几本
佛经。
LONG
);
	set("exits", ([
		"east" : __DIR__"zhulin5",
		"up" : __DIR__"cjlou1",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-yi" : 1,
		"d/shaolin/obj/fojing1"+random(2) : 1,
		"d/shaolin/obj/fojing2"+random(2) : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if( !present("letter", this_player())
	&& (objectp(present("daoyi chanshi", environment(me)))) ){
		if (dir == "up" ){
			return notify_fail("道一说道: 你未经许可，不能上二楼。\n");
		}
	}
	return ::valid_leave(me, dir);
}
