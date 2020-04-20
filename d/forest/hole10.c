// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","洞庭中心");
	set("long", @LONG
沿着洞中岔路，你到了一个洞庭之中。这个洞庭是千年古洞中最大的
一个洞庭。洞庭之中十分宽敞，在洞庭中心有一张石桌，石桌旁边有一个
黑乎乎的巨大身影，光线昏暗，你只能依稀看见那身影的样貌。洞庭两边
横七竖八的依靠着几具已经干枯的骸骨。
LONG
);
	set("exits",([
		"north": __DIR__"hole12",
		"south": __DIR__"hole_n/exit",
	]));
	set("objects",([
		__DIR__"npc/juyuan": 4,
	]));
	setup();
}
int valid_leave(object me,string dir)
{
        if( dir == "north" && present("big monkey",environment(me)))
        	return notify_fail("巨猿挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}