inherit ROOM;

void create()
{
	set("short", "无眠阁");
	set("long", @LONG
“转朱阁，低倚户，照无眠”，这座阁楼正是取词中意境命名。阁中
挂有不少灯笼，是唐门弟子晚上聚会，闲聊的好地方。
LONG
);
	set("exits", ([
		"north" : __DIR__"changlang15",
		"west" : __DIR__"changlang19",
		"eastup" : __DIR__"jiaolou7",
	]));
	setup();
	replace_program(ROOM);
}

