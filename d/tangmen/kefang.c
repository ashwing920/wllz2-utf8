
inherit ROOM;

void create()
{
	set("short","客房");
	set("long", @LONG
这里是唐门供访客住宿休息的地方。处在花园之中，推窗往外望，便
能看见满园鲜花灿烂，闻到阵阵幽香，甚是心旷神怡。
LONG       
);

	set("exits",([
		"east" : __DIR__"huayuan7",
		"west" : __DIR__"huayuan6",
		"south" : __DIR__"chashi",
	]));

	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
