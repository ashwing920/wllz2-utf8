// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: bingqidian.c

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这着是一家小小店面的兵器铺，可是卖的兵器可不寻常。种类固然中
土难得一见，能用的人更是稀少。掌柜的拿着眼瞟得你直发毛。你转脸就
看到墙上的招牌(zhaopai)。
LONG
);
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("objects", ([
		__DIR__"npc/tanghuai" : 1,
	]));

	set("exits", ([
		"southeast" : __DIR__"northroad1",
	]));

	setup();
	replace_program(ROOM);
}

