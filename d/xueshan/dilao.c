// dilao.c 地牢
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","地牢");
	set("long",@LONG
这是一个阴暗、潮湿的牢房。你感到奇怪的是怎麽会不时听到一点怪
声却怎么也找不到人呢? 
LONG
);
	set("exits",([
		"westup" : __DIR__"houyuan",
	]));
	setup();
	replace_program(ROOM);
}

