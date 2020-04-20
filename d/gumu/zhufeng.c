// zhufeng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "终南山主峰");
	set("long", @LONG
此时你已身在终南山主峰，视野更为广阔。往低望去，群山尽吭匍匐
在脚下。重阳宫的翠绿琉瓦在山腰处，晶莹生辉。只见不少殿宇散布於山
坳间，景色颇为美妙。一块巨石 (shi)立在一旁，似乎刻了什麽东西。往
西和南各是一条山路。
LONG
);
	set("item_desc", ([
		"shi"  :@TEXT
$CYN$
		於人妄矫重异要佐子
		今传迹矫阳人伴汉房
		终入复英起与赤开志
		南道知雄全异松鸿亡
		山初非姿真书游举秦
		，，，，，，，，，
		殿二收乘高造功屹曾
		阁仙心时视物成然进
		凌此活或仍不拂天桥
		烟相死割阔轻衣一下
		雾遇墓据步付去柱履
		。。。。。。。。。
$NOR$
TEXT
	]));
	set("outdoors", "gumu");
	set("exits", ([
		"westdown"  : __DIR__"shanlu2",
		"southdown" : __DIR__"shanlu1",
		"south": "/d/tianxiepai/main-01",
	]));
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	
	if(!arg || arg == "" || arg != "shi") return 0;
	if((int)me->query_skill("dodge",1) < 200) {
		message_vision("$N往上一跃，企图跳上巨石，可是跳了半天，还是站在原地。\n",me);
		return 1;
	}
	message_vision("$N运气绝顶轻功，轻轻一跃，飞上巨石之上，屹立在风中。\n",me);
	me->move(__DIR__"jushi");
	return 1;
}