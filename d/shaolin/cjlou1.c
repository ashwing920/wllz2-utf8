// Room: /d/shaolin/cjlou1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代人材辈出
。其中有不少高僧遗著留存，汇集至今，终成名震天下的少林七十二绝艺
。少林精华，尽警于此。二楼四面开窗，确保通风。中间排列着五排大书
架。四周则陈列矮几，以供阅读。几位老僧手执经卷，正在闭目凝思。
LONG
);
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"/clone/book/wuji1" : 1,
		"/clone/book/wuji2" : 1,
		"/clone/book/wuji3" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if ( present("huizhen zunzhe", environment(me)) )
	if ( present("shaolin wuji", me)
	||   objectp(ob = present("corpse", me)) && present("shaolin wuji", ob) ){
		if (dir == "down" ){
			return notify_fail("慧真说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
		}
	}
	return ::valid_leave(me, dir);
}

