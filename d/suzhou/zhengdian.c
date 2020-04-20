// Room: /d/suzhou/zhengdian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "正殿");
	set("long", @LONG
一走进正殿，首先你看到的是号称扬州八怪的画家罗聘所绘寒山，拾
得写意画像石刻和郑文焯指画丰干和尚石刻像。左右碑廊中藏历历代名人
岳飞等题写得诗文，楹联碑刻树方，世传精品。正殿左右的偏殿保存着宋
代樟木雕塑的金身五百罗汉。
LONG
);
	set("exits", ([
		"out"   : __DIR__"hanshansi",
		"east"  : __DIR__"hanshidian",
	]));
	setup();
	replace_program(ROOM);
}

