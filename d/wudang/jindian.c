//Room: jindian.c 金殿
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","金殿");
	set("long",@LONG
金殿中间供着真武大帝铜像，披发跣足，体态丰满；左右有金童玉女
侍立，虔诚恭敬；水、火二将，威武庄严。殿前供器皆为铜铸。殿宇和殿
内铜像、供桌铆焊一体，构件精确，技巧高超。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"north"	 : __DIR__"zijincheng",
	]));
	setup();
	replace_program(ROOM);
}
