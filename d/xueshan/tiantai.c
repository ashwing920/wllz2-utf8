// tiantai.c 天台
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","天台");
	set("long",@LONG
这里是雪山寺的高处。北边可见雄伟的大雪山，南边可以俯瞰美丽如
镜的圣湖。
LONG
);
	set("exits",([
		"west" : __DIR__"neidian",
	]));
	setup();
	replace_program(ROOM);
}

