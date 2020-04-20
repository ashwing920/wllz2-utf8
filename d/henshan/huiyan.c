//Room: /d/henshan/huiyang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "回雁楼");
	set("long", @LONG
这里是衡阳回雁楼，是本地最大的酒楼。往日这时已经十分忙碌的酒
楼今天却有点异样。一个年近四十的白衣汉子，正端坐自饮，桌面横放着
一把快刀，旁边却坐着一个小尼姑，满脸忧急愁苦之色，容貌却十分秀丽。
LONG
);
	set("exits", ([
		"down" : __DIR__"shop",
	]));
	set("objects", ([
		  __DIR__"npc/tian" : 1,
		  "/d/hengshan/npc/lin" : 1,
	]));
	setup();
	replace_program(ROOM);
}

