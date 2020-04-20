// 盗贼山洞
// Design By Robert 蝴蝶君 email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","盗贼山洞");
	set("long",@LONG
这里是盗贼山洞的一条石阶，你站在石阶之上，向南望去，南面已经
是盗贼山洞的第二层了。山洞中光线昏暗，只有山洞两边的那几把火把，
火光闪烁不定。透过昏暗的光线，你隐约可以看见几个人影晃动，再仔细
看去，又好象什么也没有。
LONG);

	set("exits",([
		"north": __DIR__"level2/entry",
		"down": __DIR__"level1/exit",
	]));
	setup();
	replace_program(ROOM);
}