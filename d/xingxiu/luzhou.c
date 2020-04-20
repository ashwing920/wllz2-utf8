// Room: /d/xingxiu/luzhou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "沙漠绿洲");
	set("long", @LONG
在沙漠的尽头出现了一个绿洲。灌木丛中有一眼坎儿井。井台上有一
个木杯专供口渴的行人喝水。井边是一块瓜地。
LONG
);
	set("resource/water", 1);

	set("exits", ([
		"northeast" : __DIR__"shanjiao",
		"southwest" : __DIR__"nanjiang3",
		"south"	 : "/d/npc/m_weapon/lianbianshi",
	]));

	set("objects", ([
		"/d/xingxiu/obj/donkey" : 1,
		"/d/xingxiu/obj/hamigua" : 2,
	]));
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water) {
		me->set("water", current_water+30);
		message("vision", me->name()+"趴在坎儿井的井台上用木杯舀了一杯水喝。\n"
		, environment(me), ({me}) );
		write("你喝了一口井中从天山上流淌下来的雪水，简直比蜜还甜。\n");
	}
	else write("逮着不要钱的水就这么喝，至于吗?\n");

	return 1;
}


