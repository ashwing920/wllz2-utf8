// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场七十层");
	set("long",@LONG
这里是百人道场第七十层。你脚踩在道场的地面上，却听见骨碎发出
“咯咯哒哒”的声响。仔细一看，只见道场遍地白骨，骨屑轻轻飞起，又
轻轻的飘落，如尘、如埃，无声、无息。一个清瘦的身影出现在你的眼帘
，只见他瘦如干骨，脸上菱角分明，似人既似鬼。深陷的眼颊里却透出异
样的光彩，他便是百人道场第七十层的道场弟子。
LONG
);
	set("lvl",70);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi70":1,
	]));
	::create();
}
