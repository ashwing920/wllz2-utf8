// Room: /d/shaolin/smdian1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "东侧殿");
	set("long", @LONG
这里是东侧殿。房间四周悬挂着达摩祖师、观音大士的画像，以及一
些寺内元老的字画。地下散乱地放着许多蒲团，木鱼等。看来此处是本派
弟子打坐修行之所。几位年轻僧人正肃容入定，看来已颇得禅宗三昧。
LONG
);
	set("exits", ([
		"west" : __DIR__"smdian",
	]));
	set("objects",([
		__DIR__"obj/muchui" : 1,
	]));
	setup();
	replace_program(ROOM);
}

