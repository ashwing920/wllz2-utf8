// chufang.c 厨房
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是全真教的厨房，屋角上堆着一大堆手臂粗细的木柴，看来还没
有劈好。一位火工道人正愁眉苦脸地坐在那里，看着那堆柴。墙上挂着一
块牌子(paizi)，墙边扔着一把柴刀。
LONG
);
	set("exits",([
		"west" : __DIR__"shantang",
	]));
	set("objects" , ([
		__DIR__"npc/huogong" : 1,
	]));

	setup();
}

