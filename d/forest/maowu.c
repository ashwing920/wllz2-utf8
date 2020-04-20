// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","小茅屋");
	set("long", @LONG
这是位于绝缘之地的一间小茅屋，茅屋中虽然简陋，但布置得十分雅
致。茅屋正中有张木桌，桌旁坐着一位清瘦的白发老者，虽然看起来白发
苍苍，却是鹤发童颜，想必一定是隐居于此的高人。屋子的南面挂着一把
乌金发亮的钢刀，刀柄上缠着一条白布，冥冥中却让人感到一种威不可挡
的气势。
LONG
);
	set("exits",([
		"south": __DIR__"outside02",
	]));
	set("objects",([
		__DIR__"npc/laozhe": 1,
	]));
	setup();
}
