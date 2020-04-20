// Room: /d/xingxiu/riyuedong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "日月洞");
	set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上
端坐着星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字
画(zihua)。洞两侧竖立兵器架，上面排列的大多是各种棍棒。
LONG
);
	set("exits", ([
		 "south" : __DIR__"xxh2",
	]));
	set("item_desc", ([
		"zihua" :@TEXT
$CYN$
都是些吹捧星宿老仙的诗词和他的画像。

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　狂　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
$NOR$
TEXT
	]) );
	set("objects", ([
		CLASS_D("xingxiu") +"/ding" : 1,
		"/d/xingxiu/obj/tiegun" : 1,
	]) );
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}
