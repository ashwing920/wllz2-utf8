// jingcisi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "净慈寺");
	set("long", @LONG
净慈寺，原名慧日永明院，又叫兴教寺。净慈寺面向西湖，後拥苍然
挺秀的南屏山。往北就回到大道上。
LONG
);
	set("exits", ([
		"north"   : __DIR__"road16",
		"enter"   : __DIR__"jingci",
	]));
	setup();
	replace_program(ROOM);
}
