// Room: /d/xiangyang/juyifemale.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "女客房");
	set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，只
有两边放着几张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"juyihuayuan",
	]));
	setup();
	replace_program(ROOM);
}

