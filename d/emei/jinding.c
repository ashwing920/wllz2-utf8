//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: jinding.c 金顶

inherit ROOM;

void create()
{
	set("short","金顶");
	set("long",@LONG
这就是峨嵋山的主峰金顶了。此峰耸立大地，高入云表，秀丽而又壮
美，李白赞颂它：『青冥倚天开，彩错疑画出。』登上金顶，视野豁然开
朗，鸟看脚下，但见群峰涌绿叠翠，三江如丝如带；回首远眺，则见大雪
山横亘天际，贡嘎山直插苍穹。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"northdown"  : __DIR__"wanxingan",
		"southwest"  : __DIR__"woyunan", 
		"south"	  : __DIR__"huacangan",
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
