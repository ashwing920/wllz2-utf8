// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "封禅台");
	set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，比武
夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上摆放着汉白
玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，上书：替天行道四
个大字。 盟主左右各侍立着两位白衣武士，两边都放着一长排虎皮交椅，
时常有武林前辈高手前来参见盟主。
LONG
);
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
                "north": "/d/xuanbing/entry",
	]));
	set("objects",([
                "/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}
