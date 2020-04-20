// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场一百层");
	set("long",@LONG
终于来到了百人道场的顶端第一百层。只见道场中间设立了一个小擂
台，擂台上站着一个老者，莫看他白发苍苍却是鹤发童颜。清瘦的脸颊，
深陷的双眼炯炯有神。从他喘息的气息中，顿可领略他内力修为何等的深
厚。擂台下站满了道场的弟子，个个虎势眈眈的看着你，眼神里充满了无
尽的仇恨，进退无路，奋身应战吧！
LONG
);
	set("lvl",100);
	set("objects",([
		__DIR__"npc/dizi100":1,
	]));
	::create();
}
