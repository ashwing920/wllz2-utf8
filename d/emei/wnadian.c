//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: wnadian.c 万年庵砖殿

inherit ROOM;

void create()
{
	set("short","万年庵砖殿");
	set("long",@LONG
这里是万年庵的拱顶无梁砖殿。砖殿四壁为正方形，顶为穹窿圆拱形
，殿内有普贤菩萨骑六牙白象的铜铸像一尊。拱顶无梁砖殿四壁下方，有
小龛二十四个，内各供铁铸佛像一尊。四壁上方则有横龛六道，列置铜铸
小佛三百零七个。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/kong" : 1,
		CLASS_D("emei") + "/wenfang" : 1,
	]));
	set("exits",([ 
		"east"	: __DIR__"wnachanfang",
		"out"	 : __DIR__"wannianan",
	]));

	setup();
	replace_program(ROOM);
}
