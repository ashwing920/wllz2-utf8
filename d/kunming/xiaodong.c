// /d/kunming/xiaodong

inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
这是一个小洞，虽然不宽，却收拾的干干净净，洞顶上开了一个天窗
，有一把梯子搭了上去，阳光照了进来，显得明亮舒服，靠墙有一张小床
，一个小桌子。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"up" : __DIR__"lianhua", 
		"out"  :__DIR__"shijianchi",
	]));
	setup();
	replace_program(ROOM);
}
