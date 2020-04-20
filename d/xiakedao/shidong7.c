// Room: /xiakedao/shidong7.c

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是一个石洞，两旁是光滑的石壁，洞内干干净净，一尘不染却不见
一人，洞内周围有灯球火把，把石洞照耀明亮非凡。
LONG );
	set("exits", ([
		"west" : __DIR__"shidong8",
		"north" : __DIR__"shidong6",
	]));
	setup();
	replace_program(ROOM);
}
