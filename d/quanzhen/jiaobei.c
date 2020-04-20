// jiaobei.c 教碑
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "教碑");
	set("long", @LONG
这里是全真教的教碑所在地，路旁立着一块大碑(bei)。 再往东走就
是天下闻名的道家玄门正宗--全真教的大门了。北面有一条石阶，不知道
通向哪里，往西是下山的路。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northup" : __DIR__"shijie6",
		"eastup" : __DIR__"damen",
		"west" : __DIR__"shijianyan",
	]));
	set("item_desc", ([
		"bei": @TEXT $CYN$
	＊＊＊＊＊
　　　　＊　　　＊
　　　　＊　全　＊
　　　　＊　　　＊
　　　　＊　真　＊
　　　　＊　　　＊
　　　　＊　古　＊
　　　　＊　　　＊
　　　　＊　刻　＊
　　　　＊　　　＊
　　　　＊＊＊＊＊
$NOR$
TEXT
	]) );
	set("objects",([
		__DIR__"npc/zhao" : 1,
	]));

	setup();
	replace_program(ROOM);
}
