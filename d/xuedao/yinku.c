// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "淫窟");
	set("long", @LONG
这竟然是个淫窟，阵阵浪笑传来，装修奢靡的房子里一张大床分外显
眼，一个含春少女迎上来脉脉含情的问你是否要双修。
LONG
);
	set("exits", ([
		"east" : __DIR__"midao4",
	]));
	set("objects",([
		CLASS_D("xuedao")+"/funv" : 1,
	]));
	setup();
	replace_program(ROOM);
}


