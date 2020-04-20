// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场五十一层");
	set("long",@LONG
这里是百人道场第五十一层。却见道场之中门窗禁闭，空无一人。道
场四周的房梁上挂着几缕白色的布匹，闻丝不动。细看那几缕布匹上，还
残留着陈年的斑点血渍。道场中凝聚着一股死寂的气息，黑暗中的角落中
，仿佛有双利眼正盯着你看，你不得不提高警觉，注意着四周的环境。
LONG
);
	set("lvl",51);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi51":1,
	]));
	::create();
}
