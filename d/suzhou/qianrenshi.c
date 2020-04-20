// Room: /d/suzhou/qianrenshi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "千人石");
	set("long", @LONG
在虎丘山中心，有一块千人石，巨石呈暗紫红色，由南向北倾斜石面
甚平坦，石壁如斧削。传说吴王墓筑成后，其子夫差怕泄露筑墓秘密假借
墓成祝酒观舞之名，将千余名工匠全部杀戮，鲜血渗透石中，成暗红色。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"east"	  : __DIR__"erxianting",
		"north"	 : __DIR__"shijianshi",
		"northwest" : __DIR__"zhishuang",
	]));
	setup();
	replace_program(ROOM);
}

