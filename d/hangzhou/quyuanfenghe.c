// quyuanfenghe.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "曲院风荷");
	set("long", @LONG
走进亭院，只见临湖一座小榭。柱上有一对联(duilian)。 依榭观湖
，只见荷花满湖，茭荷深处，香远益清。杨万里曾有题咏“毕竟西湖六月
中，风光不与四时同。接天莲叶无穷碧，映日荷花别样红”。
LONG
);
	set("exits", ([
		"out"	: __DIR__"quyuanbei",
	]));
	set("item_desc", ([
		"duilian" :@TEXT
		
	身		  眼
	在		  明
	荷		  小
	香		  阁
	水		  浮
	影		  烟
	中		  翠
TEXT
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
