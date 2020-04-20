//Room: shiliang.c 石梁
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","石梁");
	set("long",@LONG
你走入山坞中，有一道石梁跨溪而建，这里是九渡涧的下流，各岭之
水均在此交汇，景色极佳。附近设有许多小吃店，游人至此，大多小住歇
歇脚力。再往上就是陡峭的十八盘了。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northup"	: __DIR__"taizipo",
		"southup"	: __DIR__"shibapan",
		"east"	 : __DIR__"shop",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
