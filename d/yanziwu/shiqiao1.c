
inherit ROOM;

void create()
{
	set("short","小石桥");
	set("long",@LONG
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。石桥的东面
是一条鹅卵石铺成的小径，西面是曼佗罗山庄的前院。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"east" : __DIR__"xiaojing5",
		"west" : __DIR__"qianyuan",
	]));
	setup();
	replace_program(ROOM);
}
