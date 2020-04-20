// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: qingyanggong.c

inherit ROOM;

void create()
{
	set("short", "青羊宫");
	set("long", @LONG
青羊宫是天下第一大道观。观中林木婆娑，冠盖亭亭观中道士匆匆来
去，没人得空理你，更没人接待你。你觉得到一种宽松的失落。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"westroad1",
	]));
	
	setup();
	replace_program(ROOM);
}
