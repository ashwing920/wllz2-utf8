// Room: /d/shaolin/luohan9.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "罗汉堂九部");
	set("long", @LONG
这是一间极为简陋的禅房。环视四周，除了几幅佛竭外，室内空荡荡
地别无他物。地上整齐的摆放着几个破烂且发黑的黄布蒲团，几位须发花
白的老僧正在坐在上面闭目入定。这里是本寺十八罗汉参禅修行的地方，
不少绝世武功便是在此悟出。
LONG
);
	set("exits", ([
		"south" : __DIR__"luohan8",
		"northup" : __DIR__"zoulang8",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-he" : 1,
	]));
	setup();
	replace_program(ROOM);
}

