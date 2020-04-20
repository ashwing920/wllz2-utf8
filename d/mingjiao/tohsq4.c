//TOHSQ4.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路到这里似乎变得宽阔了些。清新的山风扑面而来，令人精神顿为
一爽。远处传来淙淙水声，渐行渐远。山壁上挂满了厚密的藤萝，随风轻
轻摇弋。
LONG
);
	set("exits", ([
		"north" : __DIR__"tohsq5",
		"south" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
