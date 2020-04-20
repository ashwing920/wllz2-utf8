// majuan.c.c 马圈
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "马圈");
	set("long", @LONG
皇家马圈，自然是好马云集。一排排齐整的马厩，一匹匹英挺高头俊
马，让你不由想起大草原上万马奔腾的壮伟景象。
LONG
);
	set("exits", ([
		"east" : __DIR__"houhuayuan2",
	]) );
	set("objects", ([
		"/d/city2/npc/yucongma" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
