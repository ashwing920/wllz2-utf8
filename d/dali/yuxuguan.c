//Room: /d/dali/yuxuguan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","玉虚观");
	set("long",@LONG
玉虚观内十分清检，正中供着张果老、吕洞宾、何香姑等八仙的塑像
，香火缭绕，供桌上摆着些蟠桃。正中放了几个蒲团。旁边一个小句里摆
着桌椅，是玉虚散人休息和授徒的地方。
LONG
);
	set("objects", ([
		CLASS_D("dali")+"/daobaifeng": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"yuxuguanqian",
	]));
	setup();
	replace_program(ROOM);
}

