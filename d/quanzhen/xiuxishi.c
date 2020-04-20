// xiuxishi.c 休息室
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是间很大的房间，光线非常昏暗。房里没有什么别的东，只有中间
放着一张收拾得舒舒服服的大床，床上的被褥也整理得整整洁洁，看着就
让人想睡觉。
LONG
);

	set("exits", ([
		"west" : __DIR__"wuchang2",
		"northwest" : __DIR__"wuchang1",
		"south" : __DIR__"shantang",
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}

