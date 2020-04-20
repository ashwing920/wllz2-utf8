
inherit ROOM;

void create()
{
	set("short","小径");
	set ("long",@LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花
木点缀在其中。远处的一座小屋子映入你的眼帘，阵阵炊烟从小屋后面的
烟囱中冒出。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"northeast" : __DIR__"xiaojing4",
		"west" : __DIR__"xiaoshe",
	]));
	setup();
	replace_program(ROOM);
}
