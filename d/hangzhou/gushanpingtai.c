// gushanpingtai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "孤山平台");
	set("long", @LONG
平台北面有“西湖天下景”亭阁，亭柱两旁有一对联(duilian)。 这
里还有曲桥水池，临池有叠石假山，布置得高低参差，疏密有致。北边是
下山的路。
LONG
);
	set("exits", ([
		"northdown" : __DIR__"gushan",
	]));
	set("item_desc", ([
		"duilian" :@TEXT
水		  晴
山		  雨
处		  时
处		  时
明		  好
秀		  奇
TEXT
]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
