//Room: huixianqiao.c 会仙桥
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","会仙桥");
	set("long",@LONG
这里地势稍平，一道山涧缓缓流过，一座窄窄的木桥横在涧上，只溶
一人经过。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"north"	: __DIR__"chaotiangong",
		"south"	: __DIR__"toutiangate",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
