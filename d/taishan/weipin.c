// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "围屏山");
	set("long", @LONG
这里是泰山的其中一座山峰。山的东面有一个虎头崖，其形状有如一
头伏虎。南面有避风崖，崖上大大地刻着「振衣冈」三字于上面。北边则
有北斗坛。从这里往东走，便可到达伺奉泰山之神碧霞元君的碧霞祠。
LONG
);
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"east" : __DIR__"bixia",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}
