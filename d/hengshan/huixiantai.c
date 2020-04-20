// Room: /d/hengshan/huixiantai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "会仙台");
	set("long", @LONG
走出北岳殿，就能看见一个石窟，紧靠在绝壁中凿出的一个小室，就
是会仙台。台上排列群仙雕像，密密麻麻，不能胜数。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown"  : __DIR__"beiyuedian",
	]));

	setup();
	replace_program(ROOM);
}

