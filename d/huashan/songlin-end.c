// Room: /d/huashan/songlin3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "松树林中的空地");
	set("long", @LONG
你已来到了松树林中的空地之间。只见一个青年男子正手握长剑，正
在练习剑法，不时发出嗖嗖的声响，树上的松树叶儿，也应声轻轻飘落。
细看他所演练的剑法，招式平淡，想必只是一个华山的无名小辈在这里练
习剑法而已。
LONG
);
	set("exits", ([
		"south": __DIR__"songlin/entry",
	]));
	set("objects", ([
		__DIR__"npc/lin-pingzhi": 1,
	]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
