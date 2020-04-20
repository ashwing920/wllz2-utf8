//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "安定门");
	set("long", @LONG
这里是永定门，城门正上方刻着“安定门”三个大字，城墙上贴着几
张官府告示 (gaoshi)。几个官兵守在两旁。
LONG );
	set("outdoors", "city2");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south" : __DIR__"di_anmen",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼！\n举报一人，赏金十两；\n"
	  "捉拿一人，赏金百两。\n知情不报者，立斩！\n鳌拜发\n";
}

