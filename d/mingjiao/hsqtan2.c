//HSQTAN2.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "深潭");
	set("long", @LONG
这里是瀑布下的寒潭，水中幽暗无比，四周似乎有几处出口，但实在
看不清是通向何处。水中冰冷刺骨，令人难以忍受，你只觉得气力在一点
一点消失。
LONG
);
	set("exits", ([
		"east" : __DIR__"hsqtan3",
		"west" : __DIR__"hsqtan2",
		"south" :__DIR__"hsqtan1",
		"north" :__DIR__"hsqtan2",
	]));
	setup();
}
void init()
{
	object me;
	int meqi,meneili,decqi,mq;
	me=this_player();
	meqi=(int)me->query("qi");
	meneili=(int)me->query("neili");
	mq=(int)me->query("max_qi");
	decqi=(int)(mq/(random(4)+5+meneili/200));
	meqi=meqi-decqi;
	me->set("neili",0);
	if(meqi>0) me->set("qi",meqi);
	else me->die();
}
