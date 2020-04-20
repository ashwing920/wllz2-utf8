// jingci.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short", "净慈寺");
	set("long", @LONG
净慈寺有前，中，後三殿，以中间的大雄宝殿最为壮观。大雄宝殿，
外观两层，黄色琉璃瓦屋顶，特别显的精美宏伟。寺廊的钟声在苍烟暮
霭中回荡，抑扬动听，这就是西湖十景之一“南屏晚钟”的来历。
LONG
);
	set("exits", ([
		"out"   : __DIR__"jingcisi",
	]));
	setup();
	replace_program(ROOM);
}
