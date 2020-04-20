// huagang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "花港观鱼");
	set("long", @LONG
只见湖中有一小岛，一座曲桥横跨湖面。曲桥上人群熙攘，倚栏投饵
。桥下红鱼，争食欢跳。谢觉哉游园时曾作诗一首“鱼国群粼乐有余，观
鱼才觉我非鱼。虞诈两忘欣共处，鱼犹如此况人乎。”
LONG
);
	set("exits", ([
		"east"	 : __DIR__"suti6",
	]));
	set("outdoors", "hangzhou");
	setup();
}
