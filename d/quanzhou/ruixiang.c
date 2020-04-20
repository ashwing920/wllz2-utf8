// ruixiang.c 瑞象岩

inherit ROOM;

void create()
{
	set("short", "瑞象岩");
	set("long", @LONG
这是座落在半山腰的小峡谷中的一块石坪。登上此处，即可见一座漂
亮的仿木石室。石室后高耸的大岩石叫作「天柱峰」。古时一位巧匠将其
雕成「释迦牟尼」瑞象，作立状，神像庄严大方，维妙维肖。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu3",
		"southup" : __DIR__"wangzhou",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
