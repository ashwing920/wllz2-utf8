// zhubaodian.c 珠宝店
// Design By Robert 蝴蝶君 Email:robert_st@263.net
inherit ROOM;

void create()
{
	set("short","桃源珠宝店");
	set("long",@LONG
$RED$			桃源珠宝店$NOR$

    珠宝店的正中是块千年古玉雕成的祥龙，玉龙活灵活现，穿梭于祥云
之中。龙嘴中含玉球，玉球有拳头大小，翠绿欲滴。龙眼半睁半闭。四周
的墙上挂满了各种金玉制品和各种护身吉祥玉器。
LONG
);
	set("exits",([
		"south": __DIR__"roadw2",
	]));
	
	set("objects", ([
                __DIR__"npc/seller-zbd": 1,
        ]) );
        setup();
	replace_program(ROOM);
}	
		