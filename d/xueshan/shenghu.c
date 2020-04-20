// shenghu.c 圣湖
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","圣湖");
	set("long",@LONG
眼前就是著名的圣湖，碧蓝的湖面倒影着蓝天和白云，浩淼的水面让
人心旷神怡。远处金碧辉煌的雪山寺清晰可见，再远处是几座延绵的大雪
山，其中最高大的是神山，相传山中有神仙居住。雪山中融化的雪水都汇
入湖中。
LONG
);
	set("resource/water",1);
	set("exits",([
		"south" : __DIR__"tulu3",
		"east"  : __DIR__"hubian1",
		"west"  : "/d/npc/m_weapon/liangunshi",
	]));
	setup();
	replace_program(ROOM);
}

