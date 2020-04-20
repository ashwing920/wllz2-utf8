// Room: /d/xiangyang/southjie3.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这里是襄阳城南大街的南头。南面就是朱雀内门，北边非常热闹。东
边是为襄阳城守军打制铠甲武器的兵器铺。十余年来，由于蒙古军的侵犯
，叮叮当当的打铁声音就一直响个不停。西面是襄阳城的南兵营，隐隐能
听见里面传来的兵士们的操练声。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"tiejiangpu",
		"west"  : __DIR__"bingying3",
		"south" : __DIR__"southgate1",
		"north" : __DIR__"southjie2",
	]));
	setup();
	replace_program(ROOM);
}
