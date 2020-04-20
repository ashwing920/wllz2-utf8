// Room: /d/xiangyang/dangpu.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『邱航当铺』四个
金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，你一进去就有
一种压抑和悲怅的感觉，柜台后的老板邱航头也不抬的只顾拨拉着算盘，
柜台上方挂着一块花木牌子(paizi) 。据街坊们说铁面当铺给的价还不算
最坏，并且从不问货的来处，除了活人什么都收，所以生意很不错。
LONG
);
	set("item_desc", ([
		"paizi" : "你情我愿，概不赊欠。\n",
	]));
	set("exits", ([
		"north" : __DIR__"westjie1",
	]));
	set("objects", ([
		__DIR__"npc/qiuhang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

