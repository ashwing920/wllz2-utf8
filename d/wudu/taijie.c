// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","台阶");
	set("long", @LONG
你走在一排整齐的台阶上，然而由于年代久远，有点破落了，台阶以
南是一片森林，看上并没有什么出路，五毒教地处隐蔽之地，许多武林人
士都觅不得路而进，台阶上去，就是五毒教的前厅。
LONG
);
	set("exits", ([
		"south" : __DIR__"hsonglin1",
		"northup" :__DIR__"qianting"
	]));
	setup();
	replace_program(ROOM);
}



	


	
