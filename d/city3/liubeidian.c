// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: liubeidian.c

inherit ROOM;

void create()
{
	set("short", "刘备殿");
	set("long", @LONG
这里是武侯祠的刘备殿。正中供着汉昭烈帝，高可丈许。后主却没得
供奉，所谓 "扶不起来" 的阿斗吧。而哭庙玉碎的北地王刘谌得能和英父
同祀，令人不胜唏嘘。殿下左右是赵云等的武将廊和蒋琬为首的文臣廊。
LONG );
	set("exits", ([
		"south"   : __DIR__"wuhoucigate",
		"northup" : __DIR__"wuhouci",
	]));
	
	setup();
	replace_program(ROOM);
}
