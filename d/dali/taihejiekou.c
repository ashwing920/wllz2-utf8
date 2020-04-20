//Room: /d/dali/taihejiekou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","太和街口");
	set("long",@LONG
太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面是由
碗口大的彩色石块铺成，青兰紫绿，煞是好看。街上行人络绎不绝。大道
两边遍植松柏，满目苍翠。城内居民族裔繁杂，习俗各异，饮食穿着无不
异于中原。太学生们的朗朗之声透室可闻。北面出城门有官道通中原。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"   : __DIR__"paifang",
		"south"   : __DIR__"center",
		"east"	: __DIR__"taiheeast",
		"west"	: __DIR__"sheguta",
	]));
	setup();
	replace_program(ROOM);
}

