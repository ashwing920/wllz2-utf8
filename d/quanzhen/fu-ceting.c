// fu-ceting 侧厅
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这是正堂旁边的一间小厅，本来是用作书房的，只是侯员外家实在找
不出多少书来装点门面，所以就整治成了招待熟客的地方。厅中摆放着一
张八仙桌和几把椅子，桌上刚沏好的茶还在冒着热气。
LONG
);
	set("exits", ([
		"west" : __DIR__"fu-datang",
		"north" : __DIR__"fu-huating",
	]));
	setup();
	replace_program(ROOM);
}
