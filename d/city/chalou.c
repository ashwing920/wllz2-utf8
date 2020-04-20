// chalou.c - 茶楼
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit CHAT_ROOM;

void create()
{
	set("short", "凝香楼");
	set("long", @LONG
这是一间扬州城最出名的一间茶楼，名曰「凝香楼」，是扬州城里最
热闹的地方。想听一些江湖中的传闻，你可是来对了地方了。这里的客人
多数是来自五湖四海的江湖豪杰，商人等。只见楼上楼下，人头攒攒。好
不热闹。一个小贩穿梭在人群之间，正在贩卖一些食物。叫卖声，哄闹声
，说笑声，掺杂在一起，热闹非常。如果你想找个安静的地方说话，那只
有上二楼的雅间了。
LONG
);

	set("exits", ([
		"up"   : __DIR__"chalou2",
		"east" : __DIR__"chaguan",
	]) );		   

	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
		 
	]));
	::create();
	
}
