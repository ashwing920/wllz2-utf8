// Room: /d/shaolin/zoulang3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
#include <ansi.h>
string look_duizi();

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。房顶一侧支在南面的高墙上，另一侧则与北边和尚
院的屋顶相连。彩梁画栋，连顶棚也用彩漆绘满了各种飞天的图形，每幅
画似乎都在向人诉说一个娓娓动人的佛经故事。南边的墙壁上挂着一幅对
子(duizi)。北望可以观赏僧众们练武的场面。
LONG
);
	set("exits", ([
		"east" : __DIR__"zoulang4",
		"west" : __DIR__"houdian",
		"north" : __DIR__"wuchang2",
	]));
	set("item_desc",([
		"duizi": (: look_duizi :),
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-pin" : 1,
	]));
	setup();
}

string look_duizi()
{
	return
	CYN"\n"
	"	※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　一　　　※※※※　　　和　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　体　　　※※※※　　　合　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　真　　　※※※※　　　四　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　如　　　※※※※　　　相　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　转　　　※※※※　　　复　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　落　　　※※※※　　　修　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※　　　尘　　　※※※※　　　身　　　※※※※\n"
	"	※※※※　　　　　　　※※※※　　　　　　　※※※※\n"
	"	※※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR;
}

