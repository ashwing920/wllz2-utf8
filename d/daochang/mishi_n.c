// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","北面密室");
	set("long",@LONG
这里是百人道场北面的密室。只见密室里阴暗潮湿，密不透风。只有
密室两边的几盏油灯，闪烁着微弱的光芒。借着微弱的灯光，你看到一个
身着长袍的侍者正站在密室中间，一脸惊讶的看着你。
LONG
);
	set("objects",([
		__DIR__"npc/shizhe-n":1,
	]));
	set("exits",([
		"south": __DIR__"zongshi_room",
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_beg",1);
	setup();
}
