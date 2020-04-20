//Cracked by Kafei

inherit ROOM;

void create()
{
        set("short", "济世堂老店");
        set("long", @LONG
这是间老字号的中药铺，屋里弥漫着浓厚的药味。正前方有一个红漆
柜台，柜台后是一个硕大无比的药柜，几乎盖住了整堵墙，柜子上有无数
的盛药的小抽屉，每个抽屉均标了小字，注明药物名称。
LONG
);
        set("exits", ([
                "north" : __DIR__"citong_w2",
                "east" : __DIR__ "yaofang",
        ]));
        set("objects",([
        	__DIR__"npc/wang":1,
        ]));
        setup();
        replace_program(ROOM);
}
