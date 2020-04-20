// Room: /d/suzhou/lixuetang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "立雪堂");
	set("long", @LONG
立雪堂名自“程门力雪”和“断臂力雪”之典。堂前小院中的湖石、
形似牛、蟹、狮、蛙，谓“狮子静观牛吃蟹”，颇生动有趣。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"north"  : __DIR__"wenmeige",
	]));
	setup();
	replace_program(ROOM);
}

