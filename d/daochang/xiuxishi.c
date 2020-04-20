// 百人道场休息室
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","百人道场休息室");
	set("long",@LONG
这里是百人道场的休息室，休息室不大但收拾得十分干净。休息室东
面有张床，是提供给伤重者休息用的。北面放着几个药架，上面呈放着一
些晒干的药材。一个老者正坐在休息室正中，为前来挑战的武者们疗伤。
南面有个出口，通往百人道场的大厅。
LONG
);
	set("sleep_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_beg",1);
	set("exits",([
		"north":__DIR__"daochang_gate",
	]));
	set("objects",([
		__DIR__"npc/laozhe":1,
	]));
	setup();
	replace_program(ROOM);
}
