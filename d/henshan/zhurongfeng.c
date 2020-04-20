// Room: /d/henshan/zhurongfeng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "祝融峰");
	set("long", @LONG
祝融峰之高为衡山大四绝之首。在此俯瞰群峰，尽收眼底。东望湘江
，南及五岭，北瞰洞庭，西视雪山。杜甫望岳诗中有祝融五峰尊，峰峰次
低昂。韩愈亦以祝融万丈拔地起，欲见不见轻烟里极言其高。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown"   : __DIR__"zhurongdian",
	]));
	setup();
	replace_program(ROOM);
}

