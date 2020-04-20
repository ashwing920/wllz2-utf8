// fangheting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "放鹤亭");
	set("long", @LONG
亭四周种满了梅花。一到冬末春初，梅花盛放，蔚然可观。此亭是为
了纪念北宋隐逸诗人林和靖而建。他酷爱梅花。“疏影横斜水清浅，暗香
浮动月黄昏”就是他的咏梅名句。据传说，诗人还养鹤一只，取名：“鸣
苯”每逢自己外出散步而恰有客人来访时，童子就开笼放鹤，诗人见鹤，
便回家接客，故流传有“梅妻鹤子”的故事。朝东南走便是平湖秋月。西
南边则是孤山。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"gushan",
		"southeast" : __DIR__"pinghuqiuyue",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
