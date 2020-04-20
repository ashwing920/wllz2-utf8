//westroad2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short", "深山");
	set("long", @TEXT
已经走了很久，山林越来越密，夜晚来临了，夜枭呼号，令人毛骨悚
然。真是“蜀道难，难于上青天”。再向西，就要出山了。突然，你又发
现南面有零星火光。
TEXT
);
	set("exits",([
		"east" : __DIR__"westroad1",
		"west" : __DIR__"gebitan1",
		"south" : __DIR__"miaorenbuluo",
	]));
	setup();
	replace_program(ROOM);
}
