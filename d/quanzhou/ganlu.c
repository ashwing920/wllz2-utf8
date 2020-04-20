// ganlu.c 甘露戒坛
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "甘露戒坛");
	set("long", @LONG
从大殿后门出来，便是重檐八角攒尖式的戒坛，是佛教徒受戒剃度之
处。坛分五级，最高层中奉木雕的卢舍那坐佛，所祀佛像还有释加牟尼佛
、阿弥陀佛、千手千眼观音佛等。坛座环列「护三皈」和「护五戒」诸神
神主牌位六十四座，气氛庄严。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"cangjing",
		"south" : __DIR__"yuetai",
	]));
	set("objects", ([
		__DIR__"npc/huijin" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
