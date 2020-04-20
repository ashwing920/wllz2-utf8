// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","林中小径");
	set("long", @LONG
你穿过黄果树瀑布，来到了林中小径之中。脚踩着软绵绵的绿草地，
耳边不断的传来阵阵鸟儿的啼叫声。环顾四方，只见小径两旁种满了一排
排整齐的小树，偶然间便可看到松鼠在林中跳跃，采摘果实。鸟语花香，
让人感到十分的舒畅。
LONG
);
	set("outdoors","forest");
	set("exits",([
		"east": "/d/kunming/pubu",
		"west": __DIR__"path02",
	]));
	setup();
	replace_program(ROOM);
}
