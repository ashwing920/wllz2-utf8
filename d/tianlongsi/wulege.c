// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "无乐阁");
	set("long",@LONG
这是历代大理王侯前来进香还愿时休息的地方。阁内檀象宝炉，软榻
矮几，一应俱全，清静之中隐然透出一丝富贵之象。
LONG
);
	set("exits", ([
		"north": __DIR__"xianghemen",
		"east" : __DIR__"huangtianmen",
	]));
	set("objects",([
		 CLASS_D("tianlong")+"/xiaoshami" : 2,
	]));
	setup();
	replace_program(ROOM);
}
