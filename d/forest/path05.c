// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","林中小径");
	set("long", @LONG
你脚踩着软绵绵的绿草地，走在一条笔直的林中小径之中。耳边不断
的传来阵阵鸟儿的啼叫声。环顾四方，只见小径两旁种满了一排排整齐的
小树，偶然间便可看到松鼠在林中跳跃，采摘果实。鸟语花香，让人感到
十分的舒畅。
LONG
);
	set("outdoors","forest");
	set("exits",([
		"east": __DIR__"path04",
		"west": __DIR__"path06",
	]));
	setup();
	replace_program(ROOM);
}
