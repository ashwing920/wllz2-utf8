// qiantang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "钱塘江畔");
	set("long", @LONG
钱塘江，每年八月十八是观潮的好日子。“八月十八潮，壮观天下无
”。潮水来时“远若素练横江，声如金鼓；近则亘如山岳，奋如雷霆”，
刹那间，漫江沸腾，泼涛万顷，潮高丈馀，万马奔腾，真有“涛来势转雄
，猎猎驾长风。雷震云霓里，山飞霜雪中”的壮丽气势。西上月轮山便到
了六和塔。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"road17",
		"westup"	: __DIR__"liuheta",
	]));
	set("objects", ([
		__DIR__"npc/jian-ke" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
