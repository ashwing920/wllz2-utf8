// Room: /d/huashan/yuntai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "云台峰");
	set("long", @LONG
太华北峰又名云台峰，它和南面的诸峰连成一条崎岖的长岭，构成了
一条鱼椎脊似的登峰天梯。香炉峰和梁张峰拱立左右，峥嵘兀突。云台四
面都是悬崖绝壁，十分险峻。峰顶建有真武宫，朝南通道上立着石牌楼两
座，高镶“北峰顶”三字。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown" : __DIR__"canglong",
	]));
	set("outdoors", "huashan");
	setup();
}
 
void init()
{
	object me = this_player();
	add_action("do_pray1","pray");
	add_action("do_pray", "风前辈");
	if (me->query_temp("xunshan")) me->set_temp("xunshan/yuntai", 1);
	return;
}
int do_pray1()
{
	object ob;
	ob = present("xinwu",this_player());
	if(present("xinwu",this_player())){
		message_vision("$N心中默默地祈祷，突然眼前一亮，风清扬就要出现了！\n\n",this_player());
		this_player()->move("/d/huashan/luoyan");
		destruct(ob);
		return 1;
	} else{
	message_vision("$N心中默默地祈祷！\n\n",this_player());
	return 1;
      }
}
int do_pray()
{
	object npc,me;
	me = this_player();
	if (me->query_temp("lookfeng")){
	npc=new("/d/henshan/npc/tian");
		npc->move("/d/huashan/yuntai.c");  
		me->delete_temp("lookfeng");
		message_vision("田伯光突然跳了出来!\n\n",me);
		message_vision("田伯光说道：风前辈对我说了，我在些恭候多时了！不过要想去见风老前辈，我想看看你有多少份俩。\n",me);
		return 1;
	}
		else{
	message_vision("田伯光突然跳了出来!\n\n",me);
	message_vision("田伯光说道：他妈的，打扰我睡觉！是不是想让我打断$N的狗腿。\n\n",me);
	message_vision("田伯光一转身又不见了!\n\n",me);
	       return 1;
	}
}
