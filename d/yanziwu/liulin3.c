
inherit ROOM;

void create()
{
	set("short","柳树林");
	set("long",@LONG
这是一片碧绿的柳树林，草地中间有两棵大树(tree)，看上去枝叶茂
盛，树上几只小鸟唧唧喳喳的叫个不停。
LONG);
	set("exits",([
		"south" : __DIR__"liulin1",
	]));
	set("item_desc", ([
                "tree" : "树枝离地面不高，不知能不能跃(yue)上去。\n",
	]));
	set("objects",([
		__DIR__"npc/obj/xiao-shuzhi" : 2,
	]));
	setup();
}
void init()
{
	add_action("do_yue", "yue");
}
int do_yue(string arg)
{
	object me;
	me = this_player();
	if (arg !="tree")
		return notify_fail("你要到那去？\n");
	else
	{
		write("你纵身跳上了树枝。\n");
		message("vision",
		me->name() + "一纵身跳上了树枝。\n",environment(me), ({me}));
		me->move(__DIR__"shuzhi");
		message("vision",
		me->name() + "从下面跳了上来。\n",environment(me), ({me}) );
	}
	return 1;
}
