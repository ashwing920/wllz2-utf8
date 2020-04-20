
inherit ROOM;

void create()
{
	set("short", "曲廊");
	set("long", @LONG
弯弯曲曲的回廊，廊下就是藕香湖水，湖面满是翠绿的荷叶，中间点
缀着朵朵粉色荷花，偶尔可以看到几条鱼儿在荷间游弋。刚才的琴音渐渐
清晰，好象就在前面不远处。
LONG
);
	set("outdoors", "tangmen");
	set("exits", ([
		"northwest" : __DIR__ "qulang1",
		"southwest" : __DIR__ "ouxiang",
	]));
	setup();
	replace_program(ROOM);
}

