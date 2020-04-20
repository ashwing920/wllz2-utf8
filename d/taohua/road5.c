// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
 
void create()
{
	set("short", "洞口");
	set("long",@LONG
这是一条后山上的一个小山洞。洞口很小，但能容一个人钻进去。里
面黑黝黝的什么也看不见。
LONG
);
	set("exits", ([
		"west"   : __DIR__"road4",
		"enter"  : __DIR__"dong",
	]));
	set("outdoors", "taohua");
	setup();
	replace_program(ROOM);
}
