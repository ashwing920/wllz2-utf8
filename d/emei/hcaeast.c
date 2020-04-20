//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcaeast.c 华藏庵侧殿

inherit ROOM;

void create()
{
	set("short","华藏庵侧殿");
	set("long",@LONG
这里是金顶华藏庵东侧殿，是接待香客及来宾的地方。殿内摆着几张
桌子，桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满
经书。有几位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。
还有两个二十来岁的姑娘在向一位师太打听有关出家的事。一个十来岁的
小师太正在忙前忙后招待客人。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/he" : 1,
		CLASS_D("emei") + "/wenhui" : 1,
	]));
	set("exits",([ 
		"west"   : __DIR__"hcazhengdian", 
	]));

	setup();
	replace_program(ROOM);
}
