// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是桃花岛的厨房，中央摆着大圆桌，周围则放着几张竹椅。窗口还
摆着几盆水仙花。你吸了一下鼻子，啊．．．好香！也不知到底是花香还
是饭香。平时桃花岛的弟子和仆人都在这里用餐。
LONG
);
	set("exits",([
		"east" :__DIR__"qianyuan",
	]));

	set("objects", ([
		__DIR__"npc/yan" : 1,
		__DIR__"npc/yapu" : 1,
	]) );
	setup();
	replace_program(ROOM) ;
}
