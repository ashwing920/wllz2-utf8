// xiuxishi.c 休息室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是间很大的房间，光线非常昏暗。房里没有什么别的东西，只有中
间放着一张收拾得舒舒服服的大床，床上的被褥也整理得整整洁洁，看着
就让人想睡觉。
LONG
);

	set("exits", ([
		"southeast" : __DIR__"xiaowu1",
		"south" : __DIR__"liangong",
		"east" : __DIR__"qianting",
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
