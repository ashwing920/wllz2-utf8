inherit ROOM;

void create ()
{
	set ("short", "长安乐坊");
	set ("long", @LONG
这里是长安城一家有名的娱乐场所。当夜幕降临后，这里就格外热闹
。进进出出的客人有达官贵人，南来北往的商旅，浪迹天涯的游子，三五
成群的兵士，有时也能看见一些作俗客打扮的僧人或道士。
LONG
);

	set("exits", ([
		"up"	: __DIR__"clubup",
		"south" : __DIR__"center",
	]));
	set("objects",([
		__DIR__"obj/tables" : 1,
		__DIR__"obj/chairs" : 2,
	]));

	setup();
	replace_program(ROOM);
}

