// Room: /d/shaolin/shijie7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
石级继续向上延伸，瀑布在脚下越来越小，水声也渐行远去几位身着
灰黄色僧衣的僧人擦肩而过，看他们下山的时後脚步沉稳，好象是个会家
子。往上远眺，似乎可以看到石檐一角。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"shijie6",
		"east" : __DIR__"shanmen",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

