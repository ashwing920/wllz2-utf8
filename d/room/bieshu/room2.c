// rouw_home 梦庭院

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","花园");
	set("long",@LONG
这里是主人家的花园，你脚踩在汉白玉石铺设的小道上，只见花园东
面，是一座小假山，假山上怪石嶙峋，十分逼真。假山旁边还有一张小石
桌，石桌上有一个棋盘。花园的西面有一排整齐的杨柳树，微风吹过，柳
树条儿发出沙沙的声响。院中有一个家丁，正站在院中打扫，不时抬头看
了你一眼。
LONG
);
	set("playerhouse",1);
/**/	set("default_long","这里是主人家的花园，你脚踩在汉白玉石铺设的小道上，只见花园东面，是一座小假山，假山上怪石嶙峋，十分逼真。假山旁边还有一张小石桌，石桌上有一个棋盘。花园的西面有一排整齐的杨柳树，微风吹过，柳树条儿发出沙沙的声响。院中有一个家丁，正站在院中打扫，不时抬头看了你一眼。");
	set("objects",([
		"/d/room/npc/jiading":1,
	]));
	set("exits", ([
		"west" : __DIR__"room4",
		"east" : __DIR__"room5",
		"south"  : __DIR__"room1",
	]));
	set("owner", "ROOM_OWNER");
	setup();
}
