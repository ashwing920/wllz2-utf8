// dongting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "东厅");
	set("long", @LONG
这里是衙门东厅，是知府招待客人的所在。厅中摆着一张杉木圆桌和
几张椅子，桌上是一套精致的宜兴瓷器。墙上挂着一幅中堂，画的是猛虎
下山，乃是知府的手笔。
LONG );
	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));

	setup();

}

