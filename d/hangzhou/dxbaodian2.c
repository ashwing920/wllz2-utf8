// dxbaodian2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
殿内正中一尊如来佛像，两旁塑有二十尊诸天的佛像，大殿後壁有五
十三参海岛像，岛上有姿态各异的大小佛像一百五十个。
LONG
);
	set("exits", ([
		"out"	 : __DIR__"dxbaodian1",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
