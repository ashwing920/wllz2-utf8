// xiuxishi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是梅庄弟子练功劳累的时候，休息的地方，这里经常可以听到如
雷的鼾声，这里简单的放着几张垫子，几床棉被，几个枕头，而且梅庄弟
子虽然经常打扫这里，但这里仍然凌乱不堪，很多梅庄弟子一进这里，倒
头便睡，显是过于疲劳的缘故。 
LONG
);
	set("sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang2",
	]));
	setup();
	replace_program(ROOM);
}

