// shanmen.c 雪山寺山门
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","雪山寺山门");
	set("long",@LONG
这里是大轮寺的山门，门前是络绎不绝的进香朝圣的信徒，有的甚至
来自乌丝藏西南的波丝。山门(gate)前站了个手持法器的葛伦布在维持秩
序，东方是一条青石板铺成的山路。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"north"	: __DIR__"guangchang",
		"eastdown" : "/d/xuedao/nroad4",
	]));
	set("item_desc",([
		"gate" : "两扇厚厚的铜色大门，非合数人之力，是难以推动的。\n",
	]));
	set("objects",([
		CLASS_D("xueshan")+"/gelunbu": 1,
		"/d/wudang/npc/guest": 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "雪山寺") && dir == "north" &&
		objectp(present("gelunbu", environment(me))))
	   return notify_fail("葛伦布挡住你说：你准备用什麽供奉我们佛爷呀？\n");

	return ::valid_leave(me, dir);
}

