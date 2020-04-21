//Room: /d/dali/bingying.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","兵营");
	set("long",@LONG
大理国虽小，却重视精兵良将。然屈人必先屈志，兵戈乃下下之策，
段氏大理先与北邻宋朝修和，再以姻亲拉拢当地人，多年无战事。这是城
里的铁骑营，为皇族的嫡系，装备给养无不优于中原地方。军士们严缜以
待，盔甲鲜明，刀剑锋利。
LONG
);
	set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/weishi1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"dahejiewest",
		"west"   : __DIR__"majiu",
	]));
	setup();
	replace_program(ROOM);
}
