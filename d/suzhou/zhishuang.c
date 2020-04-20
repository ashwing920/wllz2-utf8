// Room: /d/suzhou/zhishuang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "致爽阁");
	set("long", @LONG
在千人石西面就是致爽阁，又名伏虎阁，在虎丘塔的西南面，是山上
的最高点。阁名取“四山爽气，日夕西来”之意。旧称“小五台”，是海
涌峰顶。阁外平台宽阔，俯瞰沃野；远眺群峰逶迤，可赏著名上午“狮子
回头看虎丘”一景。深秋季节观成群飞翔的苍鹰，蔚为壮观。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"southeast" : __DIR__"qianrenshi",
	]));
	set("objects", ([
		__DIR__"npc/lady1" :1,
	]));
	setup();
	replace_program(ROOM);
}

