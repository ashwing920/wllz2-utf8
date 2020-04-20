//room: /d/btshan/zhailou.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","小宅落");
	set("long",@LONG
这里是一个树影婆娑的静谧的小宅落，当中放着一口乌黑发亮的大水
缸。白驼山上常年积雪，这里的主人架起一条长长的竹渠，把清凉的雪水
引到家中的水缸里来。
LONG
);
	set("exits",([
		"west" : __DIR__"liangong",
	]));
	set("outdoors", "baituo");
	set("resource/water", 1); 
	setup();
	replace_program(ROOM);
}





