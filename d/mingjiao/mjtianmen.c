// Room: /d/mingjiao/mjtianmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄土地");
	set("long", @LONG
这是一片黄土地，尘沙泛起，剑芒凌空，刀枪晃日，杀气盈野，几个
小伙子膀大腰圆，一身短打，练功不掇。到此地，便能感觉到明教百年兴
旺的根柢非虚。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"mjtianmen1",
		"southeast" : __DIR__"mjsimen1",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
