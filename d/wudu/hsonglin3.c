// Room: /d/wudu/hsonglin3

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","黑松林");
	set("long", @LONG
这是一片茫茫不见边的大森林，林中多有松树，遮天盖日，不见光线
故名黑松林，林中人迹罕至，毒虫出没，毒瘴迷雾，十分危险。偶尔会有
些五毒神教中的高手诡秘进出，神秘莫测。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"west" : __DIR__"hsonglin3",
		"southeast" : __DIR__"hsonglin3",
		"north" : __DIR__"hsonglin3",
		"east" : __DIR__"hsonglin4",
		"south" : __DIR__"hsonglin3",
	]));
	setup();
}
void init()
{
	object ob;
	if( interactive(ob = this_player())) {
		remove_call_out("du");
		call_out("du", 1,ob);
	}
}
void du(object ob)
{

	if(!ob || environment(ob) != this_object()) return;
	if (random(2)){
		message_vision(HIR "忽然一阵迷雾向你涌来，不好！你陷入了毒瘴之中了！\n\n"NOR,ob);
		if ((int)ob->query_skill("wudu-xinfa",1) < 30 ){
			tell_object(ob,"你只觉天旋地转，顿时不醒人事。\n");
			ob->set_temp("die_for","中毒瘴之气而死！");
			ob->die();
			return;
		}
		if ((int)ob->query_skill("wudu-xinfa",1) < 60 ){
			tell_object(ob,"你只觉天旋地转，顿时失去了知觉。\n");
			ob->unconcious();
			ob->move("/d/wudu/hsonglin1");
			return;
		}
		tell_object(ob,"幸好你功力深厚。如此小毒奈何不了你！\n");
	}

}