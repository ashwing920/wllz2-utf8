// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
头顶上看来是个井口，太阳从上面照射下来，把这里照得十分明亮，
井壁上有些凹进去的地方可以给人借力往上攀爬。
LONG
);
	set("exits",([
		"north" : __DIR__"shandong",
		"up" : __DIR__"houhuayen",
	]));
	setup();
	replace_program(ROOM);
}
