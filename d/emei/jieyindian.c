//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: jieyindian.c 接引殿

inherit ROOM;

void create()
{
	set("short","接引殿");
	set("long",@LONG
接引殿右边濒崖，是金钢嘴。崖下有一块巨石，形状似钟，故名「钟
石」。对面有一石，高耸十余丈，叫「仙人石」。由此向上仰攀即到万行
庵，北下经「八十四盘」至洗象池。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"northwest" : __DIR__"bashisipan3",
		"westup"	: __DIR__"wanxingan",
	]));

	setup();
	replace_program(ROOM);
}
