// Room: /t/wanjiegu/drug_room.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
刚进这间屋子，就有一股浓重的药味扑面而来。房子中间有一个练药
用的石臼，还有几只药匙放在一边。靠墙一排架子，架子上摆满了药瓶，
数百个瓶子上都写着药物的名字。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"right_room",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"架子" : "架子上摆满了药瓶。\n",
	]));
	set("objects", ([
		__DIR__"obj/mortar" : 1,
	]));
	setup();
}

void reset()
{
	object	  *inv;
	object	  container, item;
	int		 i;

	::reset();
	container = present("mortar", this_object());
	inv = all_inventory(container);
	if( sizeof(inv) != 1) {
		for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
		item = new(__DIR__"obj/x-drug");
		if(random(2)==1 )
			item->move(container);
	}
}

