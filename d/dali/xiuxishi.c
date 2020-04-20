//Room: /d/dali/xiuxishi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "下人居室");
	set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，只
有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。这里原来是
镇南王府的下人们居住的地方。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"chahua1",
	]));
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
