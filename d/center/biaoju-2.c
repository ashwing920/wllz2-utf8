// biaoju.c - 镖局内堂
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "镖局内堂");
	set("long", @LONG
这里是镖局的内堂，内堂里装饰得十分别致，是镖局用来接待客人、
洽谈生意的地方。内堂地面铺设着红色的地毯，两边摆着几把椅子。中间
则是一张太师椅，几个客人正和镖头谈论着什么。
LONG
);
	set("exits", ([
		"east"	: __DIR__"biaoju",
	]) );			

	set("objects", ([
		__DIR__"npc/lvke": random(4)+1,
	]));
	setup();
	replace_program(ROOM);
}
