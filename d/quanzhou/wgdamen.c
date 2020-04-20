// Room: /city/wgdamen.c

inherit ROOM;

void create()
{
	set("short", "武馆大门");
	set("long", @LONG
一所气派辉煌的武馆。朱漆大门旁边摆镇了两头高大威猛，栩栩如生
的石狮子。门上挂着一块黑底大匾额，四个刷金的大字－「扬威武馆」闪
闪生光。左边插着一根两丈多高的旗杆，绣着“武”字的红旗随风飘扬。
这便是城里招牌最老，威信最著的武馆，好多城中的子弟都在此学些拳脚
兵器功夫。馆主马五德豪富好客，颇有孟尝之风。所聘教头都是一等一身
具真功夫的好手。
LONG
);
	set("exits", ([
		"east" : __DIR__"minzai2",
		"west" : __DIR__"kaojiao",
	]));
	set("objects", ([
		__DIR__"npc/mending" : 2,
	]));
	setup();
	replace_program(ROOM);
}
