// road.c 桃源大道

inherit ROOM;

void create()
{
	set("short","鲁班居小院");
	set("long",@LONG
这里是一个小院，正中坐着一个人，看不出年纪有多大，四周围着四
个垂髫童子，正在聆听先生教导。院中有一些尚未成型的石具，木模，制
作的非常精细，实在是难以用语言来形容。
LONG
);
	set("exits",([
		"west": "/d/center/shanzhuang",
		"yanzhu": __DIR__"yanzhu/xiaoyuan",
		"mengting": __DIR__"mengting/xiaoyuan",
		"bieshu": __DIR__"bieshu2/xiaoyuan",
	]));
	set("objects", ([
		"/adm/npc/luban.c"   : 1,
		__DIR__"npc/tongzi1" : 1,
		__DIR__"npc/tongzi2" : 1,
		__DIR__"npc/tongzi3" : 1,
		__DIR__"npc/tongzi4" : 1,
	]));
	setup();
	replace_program(ROOM);
}
