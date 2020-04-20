//Room: /d/dali/jingzhuang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","第一层");
	set("long",@LONG
雕四大天王像，高约四尺，批甲戴胄，手持斧钺，威严庄重。三人足
踏鬼奴。一鬼奴肌肉暴起，右手挽蛇，蛇嘴正触鬼奴下腭；另俩鬼奴戴镣
。一天神足下三人，中间一人正以双手各托天王一足。天王之间遍刻梵文
佛经。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"up"	: __DIR__"jingzhuang3",
		"out"   : __DIR__"jinzhihe",
	]));
	setup();
	replace_program(ROOM);
}

