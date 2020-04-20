// sroad8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大雪山山谷");
	set("long",@LONG
一个宽大山谷, 群山环绕, 山顶上全是白闪闪的积雪, 山谷南方有两
个山洞。
LONG
);
	set("exits",([
		"enter"  : __DIR__"shandong1",
		"north"  : __DIR__"wangyougu",
		"northup": __DIR__"sroad7",
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}
