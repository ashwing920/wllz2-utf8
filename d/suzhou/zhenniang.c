// Room: /d/suzhou/zhenniang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "真娘墓");
	set("long", @LONG
在试剑石北面就是古真娘墓，真娘也称贞娘，因安史之乱流落江南，
受骗流落堕入青楼。贞娘为守贞操，自尽抗之。后人筑亭其上，墓前石刻
“香魂”两字，墓上遍栽花卉。唐代白居易等诗人墨客纷纷为之题诗，褒
赞真娘之贞烈。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"north"	 : __DIR__"sunwuting",
		"southwest" : __DIR__"shijianshi",
	]));
	setup();
	replace_program(ROOM);
}

