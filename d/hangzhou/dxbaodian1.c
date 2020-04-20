// dxbaodian1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
天王殿後是另一座高达三十几米的大殿。匾上写着“大雄宝殿”。殿
前有两座八角九层石塔。往南又进了天王殿。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"tianwangdian",
		"enter"	 : __DIR__"dxbaodian2",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
