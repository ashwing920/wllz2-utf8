// dating.c 
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "神龙教大厅");
	set("long", @LONG
过了一条长廊，眼前突然现出一座大厅。此厅硕大无朋，足可容千人
之众。只见一群群少年男女衣分五色，分站五个方位。青、白、黑、黄四
色的都是少年，穿红的却是少女，背上各负短剑，每一队约有百人。
LONG
);

	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"houting",
		"west"  : __DIR__"zhulin",
		"east"  : __DIR__"zoulang",
	]));
	set("valid_startroom",1);
	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		CLASS_D("shenlong")+"/yun": 1,
		CLASS_D("shenlong")+"/hong":  1,
		CLASS_D("shenlong")+"/wugen": 1,
	]));
	setup();
	"/clone/board/shenlong_b"->foo();
	replace_program(ROOM);
}

