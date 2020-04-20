// Room: /d/shaolin/bagua.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "八卦阵阵心");
	set("long", @LONG
这里就是洪荒古阵的中心。站在这里，才能看清楚四周的情形，只见
周围暮蔼沉沉，云气弥漫，不见边际。一道道闪电如奔蛇般穿梭其间，发
出阵阵闷雷。间夹着几声惨厉的哭叫声，与雷电着地的劈裂声混合在一起
，整个场面说不出的诡异可惧。阵心正中处有一口深潭 (tan)，望之深不
见底。
LONG
);
	set("item_desc", ([
		"tan":@TEXT
$CYN$
深潭边的岩石上刻着四个巨大的古篆：“万古寒潭”，再有五个小字：“
苍松子谨书”。潭边都是极硬的玄武岩，潭水澄碧透明，鱼虾不生。水面
隐隐泛着一股幽幽的深绿色，走近便觉一股彻骨寒气扑面而来。粗看似乎
只有几十丈深，仔细望下去却是越看越深，直如无底深渊一般！
$NOR$
TEXT
	]));
	set("exits", ([
		"up" : __DIR__"andao3",
	]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="tan" ) 
	{
		if( present("pishui zhu", me) ) {
		message_vision("$N取出辟水灵珠，含在嘴里，轻轻一纵，跃入寒潭之中。\n", me);
		me->move("/d/shaolin/hantan1");
		message_vision("channel:rumor","【武林传奇】某人："+ me->name()+"口寒辟水灵珠，跃入寒谭之中了。\n"NOR,users());
		message("vision", "只听水面哗啦一声响，似乎有人也潜下水来。\n",environment(me), ({me}) );
	}
		else{
		tell_object(me, "你一跳入水中，只觉蚀骨寒气从全身无数个毛孔侵入，四肢几乎完全麻木，\n"
				"你拚着丹田中残余的一股内力，攀住潭边的岩石，急急忙忙地爬了出来！\n");
		message("vision", me->name() + "下半身一浸入水中，立刻大叫一声，落汤鸡似地跳了出来！，\n",environment(me), ({me}) );
		}

		return 1;
	}
}

