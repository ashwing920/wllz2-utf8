// guanjinglou.c 观景楼
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "观景楼");
	set("long", @LONG
这里是一座两层的小楼，是建筑在庄园边缘用来登高凭拦看风景的。
你轻轻靠在栏杆上，竟朽的吱吱做响。看来已经很久没有人有这个雅兴来
这里看风景了。窗户(window)上的窗纸已经破了不少，风一吹哗哗的响。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"north" : __DIR__"houhuayuan",
	]));
	set("item_desc", ([
	"window": "窗外是黄沙满天，往远处看，什么都看不清楚。\n"
	]) );

	setup();
	replace_program(ROOM);
}
