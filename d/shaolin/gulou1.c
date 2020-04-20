// Room: /d/shaolin/gulou1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "鼓楼一层");
	set("long", @LONG
这里是塔楼的底层，一缕缕阳光从墙上的花砖缝隙里透射进来，在青
砖地上投下别致的光影，如同一格格棋盘相似。往上看，长长的木楼梯盘
绕而上，似乎永无尽头。墙角，梯级都相当洁净，看来经常有僧人打扫。
LONG
);
	set("exits", ([
		"up" : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

