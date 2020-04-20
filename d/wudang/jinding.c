//Room: jinding.c 金顶
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","金顶");
	set("long",@LONG
你感到寒意阵阵袭来，原来你已到了武当山的主峰天柱峰的绝顶。前
面的金殿由铜铸成，镀以黄金，每当旭日临空，整个殿宇金光闪闪，故名
金顶。天柱峰高高独立于群峰之上，东西壁立二山，名叫蜡烛峰，中壁立
一山似香炉，名香炉峰，万山千壑，隐隐下伏。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"santiangate",
		"south"	: __DIR__"zijincheng",
		"west"	 : __DIR__"shierliantai",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
