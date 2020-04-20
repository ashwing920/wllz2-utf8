// Room: /d/shaolin/zhonglou6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "钟楼六层");
	set("long", @LONG
沿窗洞吹进一阵阵凌厉的山风，寒意浸人。北望可见松林的尽头，少
室山的顶峰处，有一片小小的平地，正中植着三棵巨松；又似乎有什么东
西正闪闪发光。头顶上的楼板开了个大洞，挂下一口大钟。从这里只能看
到巨钟的下边缘，内里黑洞洞的，什么也看不见。
LONG
);
	set("exits", ([
		"up" : __DIR__"zhonglou7",
		"down" : __DIR__"zhonglou5",
	]));
	setup();
	replace_program(ROOM);
}

