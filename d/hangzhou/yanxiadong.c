// yanxiadong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "烟霞洞");
	set("long", @LONG
据说站在山头，清晨观看山村缭绕炊烟，傍晚仰望蓝天彩霞，景色优
美，故称“烟霞”。洞口两旁有精美的“观音”和“大势至菩萨”洞内两
壁的天然岩穴里有各代的石刻。往东是下山的路。西边是去龙井。
LONG
);
	set("exits", ([
		"west"	 : __DIR__"shanlu5",
		"eastdown" : __DIR__"shuiledong",
	]));
	setup();
	replace_program(ROOM);
}
