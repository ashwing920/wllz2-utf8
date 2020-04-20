// chenghuangmiao.c - 城隍庙
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
	set("short", "城隍庙");
	set("long", @LONG
这里是桃源城的城隍庙。这是一间十分老旧的庙宇，在你面前的神桌
上供奉著一尊红脸的城隍，庙虽老旧，但是神案四周已被香火薰成乌黑的
颜色，显示这里必定相当受到信徒的敬仰。只见不少香客，正在这里烧香
敬佛，十分虔诚。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"west" 	: __DIR__"roads6",
	]));

	set("objects", ([
		__DIR__"npc/keeper" : 1,
		__DIR__"npc/crazy_dog" : 1,
		"/clone/misc/paper_seal" : 4,
	]) );

	setup();

	replace_program(ROOM);
}
