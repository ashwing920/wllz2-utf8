// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "玉皇顶");
	set("long", @LONG
此处便是泰山绝顶。这里有一座玉帝观，观前为古登封台，厉代皇帝
封禅的仪式都是在这里举行。台下有一无字碑，据说是汉武帝所立。不远
处有一石碣，上书「孔子小天下处」。正中往上便是武林盟主所在之处—
封禅台。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"nantian",
		"eastdown"  : __DIR__"riguan",
		"west"	  : __DIR__"zhangren",
		"up"	: __DIR__"fengchan",
	]));
	set("objects",([
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}
