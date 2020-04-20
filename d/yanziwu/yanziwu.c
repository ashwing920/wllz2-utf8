
inherit ROOM;

void create()
{
	set("short","燕子坞");
	set ("long",@LONG
燕子坞是幕容氏世居之地, 幕容氏乃夕日大燕国的后裔, 后来日见式
微, 但其弟子却一心一意想光复大燕。其武功见长于以彼之道, 还施彼身
, 端的十分厉害。
LONG);
	set("exits",([
		"south" : __DIR__"xiaojing1-2",
		"west" : __DIR__"houyuan1",
		"east" : __DIR__"wuchang",
	]));
	setup();
	replace_program(ROOM);
}
