// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "桃源客栈");
	set("long", @LONG
这里是桃源之城的桃源客栈。方圆五百里内，唯它最负盛名。这里的
生意非常兴隆，来自各地的客人都喜欢在这里住宿。店小二里里外外忙得
团团转，接待着南腔北调的客人。
LONG
);

	set("exits", ([
		"south":     __DIR__"roade1",
		"west":	     __DIR__"roadn1",
		"up":        __DIR__"inn_2f",
	]) );

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/guniang" : 1,
	]));
	setup();

}

int valid_leave(object me,string dir)
{
        if (!me->query_temp("give_sleep_money") && present("xiao er",environment(me))
        &&      dir == "up")
                return notify_fail("店小二拦在楼梯口，白眼一翻，说道：怎么着？想白住？\n");
                
        if ( me->query_temp("give_sleep_money") && present("xiao er",environment(me)) && dir != "up" )
        me->delete_temp("give_sleep_money");
        return ::valid_leave(me, dir);

}
