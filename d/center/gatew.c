// gatee.c - 西城门
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "西城门");
	set("long", @LONG
这里是桃源城西城门，城门正上方刻着“西门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小
心为妙。一条笔直的青石板大道向东西两边延伸。西边是郊外，隐约可见
一片一望无际的树林。东边是城里。
LONG
);
	set("exits", ([ 
		"east" : __DIR__"roadw4",
		"west" : "/d/road/xia-w01",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing": 2,

	]) );
	set("outdoors","taoyuan");
	setup();
}

void init()
{
	add_action("look_gaoshi", "look");
}

int look_gaoshi(string arg)
{
	int i;
	object *ob;

	if(!arg || arg!="gaoshi")	return 0;

	ob=users();
	while(i<sizeof(ob) && (!ob[i]->query("kill_flag")) )
		i++;
	if(i >= sizeof(ob) ) {
		write("本城治安良好。\n\n          桃源城知府\n");
		return 1;
	}
	write("目前本城正在通辑以下要犯：\n\n");
	while(i < sizeof(ob)) {
		if(ob[i]->query_condition("killer")) 
			write(sprintf(RED"%-12s      %-12s\n"NOR, ob[i]->query("name"), ob[i]->query("id")));
		i++;
	}
	write("\n捉获以上逃犯送官者，重赏！\n\n          桃源城知府\n");
	return 1;
}
