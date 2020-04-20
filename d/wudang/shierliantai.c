//Room: shierliantai.c 十二莲台
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","十二莲台");
	set("long",@LONG
这里是武当绝顶的十二莲台，台与台之间以曲栏相连，雕刻精美，是
远眺的最佳所在。站立此台四眺，宛如身在千叶宝莲之上，千峰万壑都在
脚下。往西可望到七百里外的华山，东望则汉水如练，襄、樊一带尽收眼
底。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"east"	 : __DIR__"jinding",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
