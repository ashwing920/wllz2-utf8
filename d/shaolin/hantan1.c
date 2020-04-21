// Room: /d/shaolin/hantan1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "万古寒潭");
	set("long", @LONG
这是寒潭之中。四周水声哗哗，似乎有一股暗流在极力牵扯着你往下
沉。透过潭水隐约可见潭周的岩壁，被数万年水流冲激磨削得十分光滑。
虽然口中含了辟水珠，身上却仍然感觉到丝丝寒意侵入肌肤，而且越是往
下，水底的吸力越强，寒意更甚。
LONG
);
	setup();
}

void init()
{
	call_out("down", 10, this_player());
}

void down(object me)
{
	tell_object(me, "只觉脚底水流盘旋，一股强大的吸力把你往下拉去...\n");
	me->move(__DIR__"hantan2");
}
