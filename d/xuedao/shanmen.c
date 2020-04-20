// shanmen.c 血刀门山门
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","血刀门山门");
	set("long",@LONG
红的异常的红漆大门(men)上方高挂着一块匾,写着血刀门三个大字。
门口站着一位穿着红袈裟的和尚，据说这儿晚上经常听到妇女的哭声。
LONG
);
	set("outdoors","xuedao");
	set("exits",([
		"north" : __DIR__"guangchang",
		"south" : "/d/xuedao/wangyougu",
	]));
	set("item_desc",([
		"gate" : "两扇血色大门，给人一种很诡异的感觉。\n",
	]));
	set("objects",([
		CLASS_D("xuedao")+"/dizi": 4,
		CLASS_D("xuedao")+"/suixi": 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;

	if((!mapp( myfam = me->query("family")) || myfam["family_name"] != "血刀门") 
	&& (dir == "north") && objectp(present("xuedao dizi", environment(me))))
		return notify_fail("血刀门弟子拦住你的去路，说道：血刀门不是你随便出入的地方！\n");
	return ::valid_leave(me, dir);
}
