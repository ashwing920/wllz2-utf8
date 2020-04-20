//ROOM lianbianshi.c

inherit ROOM;

void create()
{
	set("short", "造鞭潭");
	set("long",@LONG
这里是玄兵古洞的打造钢鞭的地方。处在荒芜人烟的戈壁滩上。居然
能有这样一泓漂亮的潭水，真是让人不得不赞叹大自然的鬼斧神工。潭边
婷婷站者一位妙龄的少女，手中把玩着一把看似极是锋利的匕首，呆呆的
看着深邃的潭水出神。
LONG
);
	set("exits", ([
		"north" : "/d/xingxiu/nanjiang3",
	]));

	set("objects",([
		__DIR__"npc/shibian" :1,
	]));

	setup();
	replace_program(ROOM);
}
