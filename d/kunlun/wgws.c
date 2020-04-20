// Room: /d/kunlun/wgws.c

inherit ROOM;

void create()
{
	set("short", "五姑的卧室");
	set("long", @LONG
一进门，扑鼻便是一股药气，一张绣榻放在墙角，垂着细纱。揭开帐
子，只见一个脸肿得象南瓜般的女人躺在床上。
LONG
);
	set("objects", ([ 
		__DIR__"npc/wugo" : 1,
	]));
	set("exits", ([ 
		"north" : __DIR__"huapu",
		"northeast" : __DIR__"bwc",
	]));
	setup();
	
}
