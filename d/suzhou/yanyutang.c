// Room: /d/suzhou/yanyutang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "燕誉堂");
	set("long", @LONG
燕誉堂是全园主厅，旧时系园主宴客处。曾经作为御膳房。堂名取于
《诗经》：“式燕且誉，好而无射”。此处建筑为鸳鸯厅形状，高敞宏丽
，堂内陈设富丽精致。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"west"	  : __DIR__"shizilin",
		"southeast" : __DIR__"zhenquting",
	]));
	set("objects", ([
		__DIR__"npc/lady3" : 2,
	]));
	setup();
	replace_program(ROOM);
}

