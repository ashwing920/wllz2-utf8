//Room: /d/dali/shizilukou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","十字路口");
	set("long",@LONG
这是大理城内的主要商贸场所。形形色色的叫卖声在耳边此起彼伏，
连绵不绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。大道两旁高立
了两座楼牌，西首是御林军的驻地，东面则是民居。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"center",
		"south"  : __DIR__"southgate",
		"east"   : __DIR__"dahejieeast",
		"west"   : __DIR__"dahejiewest",
	]));
	setup();
	replace_program(ROOM);
}

