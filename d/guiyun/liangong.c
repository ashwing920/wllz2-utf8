// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /guiyun/liangong.c

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是归云庄陆少庄主的练功房。由与陆少庄主乃少林旁支仙霞派出
身，所以房中布置尽是为习练外门硬功之用，竖立着不少木桩和草靶。西
边角上还有两个大沙坑，天花板上吊着一支大沙袋。
LONG
);

	set("exits", ([
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 1,
	]));
	setup();
	replace_program(ROOM);
}
