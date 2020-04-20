
inherit ROOM;

void create()
{
	set("short","庄门");
	set("long",@LONG
你转过一丛茂密的花丛, 猛然间, 只见一座红檐绿瓦, 小巧玲珑的庄
院矗利在灿澜的花丛中。庄门大匾上赫然写着「$HIY$曼陀罗山庄$NOR$」五个金光闪
闪的大字。
LONG);
       set("outdoors","yanziwu");
       set("exits",([
		"west" : __DIR__"hc",
		"east" : __DIR__"qianyuan",
		"south" : __DIR__"xiaojing1-0",
		"north" : __DIR__"hc1",
	]));
	setup();
}
