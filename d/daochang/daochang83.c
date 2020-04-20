// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场八十三层");
	set("long",@LONG
这里是百人道场第八十三层。只见道场的窗户敞开，阳光从窗外照射
进来，把道场照耀得一片通亮。一个满脸红光，身材略胖的中年人正坐在
道场中间对着你笑，笑容中丝毫察觉不出半点敌意。再细看，你不禁打了
个冷颤。只见那中年人，嘴角正缢出一丝腥红的鲜血，身后，一具干枯的
尸体正用它那冰冷无神的眼光盯着你看。
LONG
);
	set("lvl",83);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi83":1,
	]));
	::create();
}
