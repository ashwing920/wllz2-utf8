// wangyougu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","忘忧谷");
	set("long",@LONG
这里乃是大轮寺外一处僻静所在，四下绝无人迹。前前後後，大大小
小靖百座佛塔，被白得耀眼的雪被披盖着。银白色的山野、雪地里闪耀着
红色和蓝色的光带，五彩缤纷，迷宫一样的琼楼仙阁在你眼前出现。南面
一条小径不知通往何处。
LONG
);
	set("exits",([
		"south"   : __DIR__"sroad8",
		"north"   : __DIR__"shanmen",
	]));
	set("objects", ([
		__DIR__"npc/zhuoma" :1,
		__DIR__"npc/yangzong" :1,
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}


