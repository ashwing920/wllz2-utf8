//Room: /d/dali/chahua10.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","茶花苑");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。这里是府中的茶
花苑，天下名品毕聚于此，你对着满苑茶花，心花怒放，看了一本，喜欢
一本，实在不知道哪本茶花更好些。
LONG
);
	set("objects", ([
		__DIR__"obj/chahua2": 1,
		__DIR__"obj/chahua3": 1,
		__DIR__"obj/chahua6": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"chahua7",
	]));
	setup();
	replace_program(ROOM);
}
