
inherit ROOM;

void create()
{
	set("short","小径");
	set ("long",@LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花
木点缀在其中。前面就是小厅了，一位美丽的少女站在厅前，你被她的容
貌所吸引，如果不是亲眼所见，不可想象世上还有这等如此美貌的少女。
LONG);
	set("outdoors","yanziwu");
	set("objects",([
		__DIR__"npc/abi" : 1,
	]));
	set("exits",([
		"east" : __DIR__"xiaoting",
		"southwest" : __DIR__"xiaojing3",
	]));
	setup();
	replace_program(ROOM);
}
