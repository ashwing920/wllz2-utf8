//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在
太师椅上讲学，那就是京城的大儒顾炎武了。在他的两侧坐满了求学的学
生。一张古意盎然的书案放在顾先生的前面，案上摆着几本翻开了的线装
书籍。顾先生的身后是一个书架(shujia)讲堂内多历代楹联石刻，足见书
院历史的悠久。值得一提的是嵌在讲堂前左壁的学规(xuegui)。
LONG );
	set("exits", ([
		"south" : __DIR__"xisi2",
	]));
	set("item_desc", ([
		"xuegui" : "日讲经书三起，日看纲目数页。"  
			"\n通晓时务物理，参读古文诗赋。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n\n"
			"求学需缴学费五十两\n",
	]));
	set("objects", ([
		__DIR__"npc/gu": 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/朱", 0);
	return 1;
}
