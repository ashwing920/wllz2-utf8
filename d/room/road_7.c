// zahuopu.c
// Design By Bmw 逍遥寻欢 email:Bmw@sina.com

inherit ROOM;

void create()
{
	set("short", "桃源杂货铺");
	set("long", @LONG
这是桃源唯一的杂货铺，柜台后面挂着很多行走江湖的日用必须品。
掌柜的是个进生意场不久的年轻小伙子，一副老实的样子，虽然不能说貌
似潘安可是也差不了多少！听说掌柜的曾经跟过一个世外高人学过武功呢
柜台前面立着一块牌字(sign)。牌子是用非常深厚的$HIY$金刚指$NOR$力写成的！
LONG );
	set("item_desc", ([
		"sign": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"north" : __DIR__"road_6",
	]));

	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
	setup();
	replace_program(ROOM);
}
