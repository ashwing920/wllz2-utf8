// shuyuan.c - 圣贤书屋
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "圣贤书屋");
	set("long", @LONG
这里是桃源城的圣贤书屋。窗明几净，一尘不染。一位庄重严肃的老
先生坐在太师椅上讲学。在他的两侧坐满了求学的学生。一张古意盎然的
书案放在老先生的前面。老先生的身后是一个书架，讲堂内多历代楹联石
刻，足见书院历史的悠久。值得一提的是嵌在讲堂前左壁的学规(xuegui)。
LONG
);

        set("item_desc", ([
                "xuegui": @TEXT
学规上写着：
$CYN$
日讲经书三起，日看纲目数页。
通晓时务物理，参读古文诗赋。
读书必须过笔，会课按时蚤完。
夜读仍戒晏起，疑误定要力争。
$WHT$
求学需缴学费十两
$NOR$
TEXT	
	]));

	set("exits", ([
                "south" : __DIR__"roadw3",
        ]) );			

        set("objects", ([
                __DIR__"npc/teacher": 1,
                __DIR__"npc/student": 3,
	]) );

	setup();
}
