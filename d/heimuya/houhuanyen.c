// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
此处种满了许多不知名的奇花异草，在绝顶之上有这样的景色，真恍
如飘渺仙景，令人疑幻疑真，西首是一间小石屋，但似乎没有人居住。
LONG
);
        set("exits",([
		"south" : __DIR__"jueya",
		"north" : __DIR__"changlang5",
		"west" : __DIR__"xiaosiwu",
	]));
        set("objects",([
		CLASS_D("riyue")+"/zhang" : 1,
		CLASS_D("riyue")+"/lan" : 1,
	]));
        setup();
        replace_program(ROOM);
}
