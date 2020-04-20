
inherit ROOM;
void create()
{
	set("short", "曲廊");
	set("long", @LONG
弯弯曲曲的回廊，廊下就是藕香湖水，湖面满是翠绿的荷叶，中间点
缀着朵朵粉色荷花，偶尔可以看到几条鱼儿在荷间游弋。远处飘来时断时
续的忧郁琴音，听着让人黯然神伤。
LONG
	);
	set("outdoors", "tangmen");
	set("exits", ([
		"west" : __DIR__ "ouxiang",
		"east" : __DIR__ "jingyitang",
	]));
	setup();
	replace_program(ROOM);
}

