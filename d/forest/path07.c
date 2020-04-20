// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","松树林前的小径");
	set("long", @LONG
穿过林间小径，不知不觉你已经来到了一片松树林前。只见松树林中
松树茂盛而稠密，细看每个松树，至少也有上百年的树龄了。稠密的枝叶
相互交叉着，把整片松树林都遮挡得严严实实。阳光照射到林中，也形成
了稀疏的几道光线。偶然间，你看见有个人影从林中穿过，再细看却什么
也没有。
LONG
);
	set("outdoors","forest");
	set("exits",([
		"east": __DIR__"path06",
		"west": __DIR__"senglin/entry",
	]));
	setup();
	replace_program(ROOM);
}
