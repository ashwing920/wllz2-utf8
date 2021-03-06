// shuyuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在
太师椅上讲学，那就是当今大儒朱先生了。在他的两侧坐满了求学的学生
。一张古意盎然的书案放在朱先生的前面，案上摆着几本翻开了的线装书
籍。朱先生的身后是一个书架(shujia)讲堂内多历代楹联石刻，足见书院
历史的悠久。值得一提的是嵌在讲堂前左壁的学规(xuegui)。书院老夫子
刚奉了圣旨颁发学位，就在门口树着书院新立的学位公告板(board)。
LONG );
	set("item_desc", ([ 
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	求学需缴学费五十两。\n",
		"board": "
	   本书院奉圣上恩旨自即日起封授学位：
  0	   文盲
 10	   童生
 20	   秀才
 30	   举人
 40	   解元
 50	   贡士
 60	   会元
 70	   进士
 80	   探花
 90	   榜眼
100	   状元
110	   翰林院士
120	   翰林硕士
130	   翰林博士
140	   翰林院编修
150	   庶吉士
160	   学士
170	   内阁大学士
180	   内阁首辅
190	   文学大宗师
200	   圣人\n" 
	]));
	set("exits", ([ 
		"up"	: __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	]));


	setup();
	replace_program(ROOM);
}
