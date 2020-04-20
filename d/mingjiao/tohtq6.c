//TOHTQ6.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
山洞中似乎深不可测，洞壁上点着几盏松明，照得洞内一派光亮。洞
内虽然感到十分潮湿，可洞壁干燥坚实，大异平常。
LONG
);
	set("exits", ([
		"north" :__DIR__"htqmen",
		"west"  :__DIR__"tohtq5",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
