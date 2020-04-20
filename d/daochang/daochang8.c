// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场八层");
	set("long",@LONG
这里是百人道场的第八层，道场十分宽敞，可却门窗紧闭，只有东边
那道门，是通往道场休息室。道场中间墙壁上挂着一张字画，上面刚劲有
力的写着一个「拳」字。道场中间地面上画着一个圈子，圈中站着一个道
场弟子，据说只要打败了道场弟子就可以进入道场第九层进行更高的挑战
，武林虽大，能够成功闯过百人道场的人却是寥寥无几。
LONG
);
	set("lvl",8);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi8":1,
	]));
	::create();
}
