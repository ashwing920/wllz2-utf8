// Room: /d/xiangyang/guofukefang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这里是郭府客人们的住处，整整齐齐的一排平房。门的左右两边各是
一张床，床上的被褥被叠得整整齐齐。床头正对的地方摆着一张桌子，旁
边还放着一张椅子。桌上整齐地放着文房四宝，旁边还放着几本书。地上
摆着一盆牡丹花，一丝清香萦绕房中。因为郭靖是当今的大英雄，所以江
湖上有不少豪杰每年都来拜访他。
LONG
);
	set("sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"guofuhuayuan",
	]));
	setup();
	replace_program(ROOM);
}

