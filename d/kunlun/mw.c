//d/kunlun/mw.c

inherit ROOM;

void create()
{
	set("short", "小山谷");
	set("long", @LONG
这是三圣坳山后的一个小山谷，长年人迹罕至，谷中古松参天，积雪
皑皑。偶尔从远处传来几声雪鸡的鸣啼。谷中有一茅草搭成的山亭，亭内
有一竹编的小几，一位白发苍苍满面红光的老者正盘坐在几前抚琴。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"ssy",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("kunlun") +"/hezuodao" : 1,
	]));
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
