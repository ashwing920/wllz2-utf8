// Room: /d/henshan/zhongting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "钟亭");
	set("long", @LONG
钟亭内设铁钟一口，重九千斤。每逢山洪暴发，鸣钟镇洪，亦以示警
，声闻二十里外。 
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west"   : __DIR__"kuixingge",
	]));
	setup();
	replace_program(ROOM);
}

