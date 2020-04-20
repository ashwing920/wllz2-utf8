//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//changan  city

inherit ROOM;

void create()
{
	set("short","长安城西门");
	set("long",@LONG
这里是长安城的西门。东面就到了城中，远望人山人海，往来行人车
流不绝。西面一条大路通向远方。城门下有一些执勤的兵士。时下虽已天
下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人士。
LONG
);
	set("exits",([
		"west":  "/d/xingxiu/xxroad1",
		"east":  __DIR__"center",
	]));

	set("objects",([
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  1,
	]));
	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}



