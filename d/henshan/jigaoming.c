// Room: /d/henshan/jigaoming.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "极高明台");
	set("long", @LONG
这里是福严寺最高处。唐邺侯李泌手书极高明三个大字于此，意即佛
相极高 (高无见顶相) ，佛光极明 (明不借他光) ，佛是至高无上的，故
曰极高明台。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	   "northdown"  : __DIR__"sansheng",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

