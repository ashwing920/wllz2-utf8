//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: heilong1.c 黑龙江栈道

inherit ROOM;

void create()
{
	set("short","黑龙江栈道");
	set("long",@LONG
黑龙江栈道沿黑龙江而建。这里一山中开，两崖并立，形成一道宽仅
数尺，长达几百米的深峡——白云峡。黑龙江栈道就从狭窄的白云峡中转
折穿过，架设在绝壁上。走在栈道上，只觉道窄人危；俯视深涧，急流飞
旋，山静而觉动；仰观头顶，天光如隙，崖开而欲合。这就是天开画图的
「一线天」。栈道南通千佛庵，北至清音阁。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"south"	  : __DIR__"heilong2",
		"northeast"  : __DIR__"qingyinge",
	]));

	setup();
	replace_program(ROOM);
}
