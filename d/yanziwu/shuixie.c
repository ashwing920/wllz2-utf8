
inherit ROOM;

void create()
{
	set("short","听香水榭");
	set("long",@LONG
这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着“听香水榭”四个大
字，笔致颇为潇洒。东边是一条小路，不知是通往哪里的。再往前走，就
到了“燕子坞”。南边是水榭的后院。
LONG);
	set("exits",([
		"north" : __DIR__"anbian2",
		"west" : __DIR__"anbian4",
		"south" : __DIR__"houyuan1",
	]));
	setup();
	replace_program(ROOM);
}
