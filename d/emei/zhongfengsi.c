//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: zhongfengsi.c 中峰寺

inherit ROOM;

void create()
{
	set("short","中峰寺");
	set("long",@LONG
中峰寺在白云峰下，始建于晋代，原为道观。传说观内的道人每年在
三月三日都献身给山中一条大蟒，以为可以升仙。后来有个从资州来的明
果禅师，杀了那条大蟒，道士们始知上当，感激不已，自愿改信佛教，从
此改观为寺。这里往北可到清音阁，东下至神水庵。
LONG
);
	set("objects", ([
		__DIR__+"npc/guest": 1,
	]));
	set("exits",([ 
		"northwest"	: __DIR__"qingyinge",
		"eastdown"	 : __DIR__"shenshuian",
	]));
	set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}
