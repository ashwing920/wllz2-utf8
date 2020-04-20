//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: qfachanfang.c 禅房

inherit ROOM;

void create()
{
	set("short","禅房");
	set("long",@LONG
这里是一间安静宽敞的禅房，乃是千佛庵中弟子打坐修行之所。地下
整整齐齐放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG
);
	set("exits",([ 
		"west"	 : __DIR__"qfadadian",
	]));
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
