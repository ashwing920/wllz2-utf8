//fang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","练功房");
	set("long",@LONG
这里是白驼山弟子的练功房。里面有几个单间，是练功室。弟子们在
里边砌磋武艺，绝对不允许外人打搅。
LONG
);
	set("exits",([
		"west" : __DIR__"liangong",
		"1" : __DIR__"room1",
		"2" : __DIR__"room2",
		"3" : __DIR__"room3",	 
	]));
	set("objects",([
		__DIR__"npc/trainer" : 1,
	]));
	setup();

}
int valid_leave(object who ,string dir)
{
	if((string)who->query("family/family_name")!="白驼山派"
		&&(dir!="west"))
	return notify_fail("那里禁止外人进入！\n");
	return 1 ;
}
