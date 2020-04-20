// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: wangjianglou.c

inherit ROOM;

void create()
{
	set("short", "望江楼");
	set("long", @LONG
望江楼又名崇丽阁。下两层四角，上两层八角，朱柱琉瓦，翘角飞甍
，雕梁画栋，登临其上，远眺府南河，清风扑面，舟火穿梭，实为胜景。
楼的周遭，翠竹千茎朝天，每当雨雾氤氲，轻烟笼翠，竹籁鸟音，动人心
魄。楼前薛涛井，传说因为薛涛漂洗一种红色诗笺而流芳千古: 无波古井
因涛重，有色遗笺举世珍。这也是这一才女的传世的唯一遗泽。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"northwest"  : __DIR__"eastroad3",
	]));
	
	setup();
	replace_program(ROOM);
}
