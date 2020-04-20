// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "白鹤泉");
	set("long", @LONG
相传从前这里有一个白鹤泉，它的水清凉甘甜，为泰山之最。这泉水
长年涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因以为名。可惜后
来有一个自私自利的小官，独霸了泉水，后来更因迷信风水之说，把泉眼
堵塞，白鹤泉从此便干涸了。现在只剩下一座刻着「白鹤泉」三字的石坊
以为纪念。从这里继续北上，便是上山之路。
LONG
);
	set("exits", ([
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");

	setup();
	replace_program(ROOM);
}

