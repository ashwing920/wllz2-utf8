// dongmen.c 东门
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是武功镇的东门，眼前城墙高耸，墙上的箭垛里好象还有人走来
走去。阳光照来，城墙上闪过几道白光，似乎是兵器反射出的光。城门上
题着‘东门’两个大字，门口站着一些官兵，正手持兵刃盘问着来往的行
人们。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"east" : __DIR__"guandao2",
		"west" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}
