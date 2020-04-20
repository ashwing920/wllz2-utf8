// Room: /d/taishan/xiayi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "侠义厅");
	set("long", @LONG
这里是封禅台左边的侠义厅，武林盟赏善使者平时不下山时，通常都
是在这里办理武林公案。上首正中放着把太师椅，赏善使者就坐在上面开
堂审理。左右各侍立着几位红衣武士，看上去威风凛凛，自有一股庄严气
象。
LONG
);
	set("exits", ([
		"west" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/shang-shan" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	setup();
	replace_program(ROOM);
}
