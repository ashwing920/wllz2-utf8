// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "慈悲院");
	set("long",@LONG
这是僧人们点化顽徒的地方。不少江湖豪客由于厌倦了打打杀杀的日
子，来到此处落发为僧，叛依佛门。墙上一幅佛祖神像，两边各有一条幅
，上书：放下屠刀，立地成佛。
LONG
);
	set("exits", ([
		"east" : __DIR__"wuwujing",
		"south" : __DIR__"sanwugong",
	]));
	set("objects",([
		__DIR__"laji/pojian":1,
	]));
	setup();
	replace_program(ROOM);
}
