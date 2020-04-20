// Room: /d/shaolin/twdian2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "西侧殿");
	set("long", @LONG
这里是西侧殿。房间四周悬挂着达摩祖师、观音大士的画像，以及一
些寺内元老的字画。地下散乱地放着许多蒲团，木鱼等。看来此处是本派
弟子打坐修行之所。几位中年和尚手持数珠，正在喃喃念经。
LONG
);
	set("exits", ([
		"east" : __DIR__"twdian",
	]));
	setup();
	replace_program(ROOM);
}

