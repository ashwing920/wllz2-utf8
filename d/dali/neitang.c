//Room: /d/dali/neitang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","内堂");
	set("long",@LONG
这里是镇南王府的内堂。十分宽阔明亮。正面墙上挂着一幅水墨画，
两边各有一个窗子，透过窗户可以看见外面的青山绿水。内堂西面放着一
个书柜(shugui)，上面放满了一些书籍。
LONG
);
	set("objects", ([
		CLASS_D("dali")+"/duanzc": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"yongdao2",
	]));
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	object me;
	me = this_player();

	if(!arg || arg == "" || arg != "shugui") return 0;
	if((string)me->query("family/family_name") != "大理段家")
		return notify_fail("你将书柜推了推，却丝毫不动，一点用都没有。\n");
	
	message_vision("$N用手轻轻的推了推书柜，只听见“咯吱”的一声，书柜移了一下，露出了一条暗道。\n",me);
	message_vision("$N毫不犹豫的往里面钻了进去。\n",me);
	me->move(__DIR__"biguanshi");
	return 1;
}