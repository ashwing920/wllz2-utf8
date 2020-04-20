// workroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "鸟窝");
	set("long", @LONG
金黄色的落叶铺满了整个地面，犹如铺了层柔软的天鹅绒地毯，轻柔
的脚步伴随着落叶的沙沙声，回荡在整个房间。柔和的月光轻轻的哼着夜
曲，透过宽大的顶棚投射在房间的每个角落，温柔的哄着鸟儿和蝴蝶进入
梦乡。
LONG
);
	set("exits",([
		"north": "/u/robert/workroom",
		"down": "/d/wizard/towiz_room",
	]));
	setup();
	replace_program(ROOM);
}
