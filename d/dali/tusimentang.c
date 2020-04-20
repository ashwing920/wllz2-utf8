//Room: /d/dali/tusimentang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","门堂");
	set("long",@LONG
门堂以及其他一些附属建筑，如谷仓，厨房，坚狱，外有二米多高重
修的围墙。主体建筑是规模最大的议事厅，三层大屋系三重蟾歇山顶干栏
式建筑，长六十尺，宽四十有五，高三十尺。二楼是宣抚召集大小头领议
会地点，也是审判室。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"tusihouting",
		"up"	 : __DIR__"tusiyishi",
		"out"	: __DIR__"tusifu",
	]));
	setup();
	replace_program(ROOM);
}

