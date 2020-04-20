
inherit ROOM;

void create()
{
	set("short","娘缳玉洞");
	set("long",@LONG
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各
种书籍。
LONG);
	set("no_fight", 1);
	set("exits",([
		"north" : __DIR__"ytyuan",
	]));
	setup();
	replace_program(ROOM);
}
