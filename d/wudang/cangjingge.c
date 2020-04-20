// cangjingge.c 藏经阁
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长
方形的大桌子，上面也堆满了书。一个道童正在整理书籍。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		"clone/book/"+books[random(sizeof(books))] : 1,
		"clone/book/"+books[random(sizeof(books))] : 1
	]));
	setup();
	replace_program(ROOM);
}
