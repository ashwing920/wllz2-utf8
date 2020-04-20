// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","绝缘之地");
	if(NATURE_D->is_night())
	set("long", @LONG
这里是绝缘壁后的另外一番天地。天空月色皎洁，月光照射下，青草
地上挂着星点的露珠。青草地上，稀疏的种着几棵桃树，零零散散，看起
来确实别有一番的情调。西面有一个水池，月光倒映在水池当中，不时还
有鱼儿吐出若干的气冒，一切宁静、祥和，真可谓是人间仙境。北面有间
小茅屋，门户紧闭，一丝幽幽的灯光从窗户照射出来。
LONG
);
	else 
	set("long", @LONG
这里是绝缘壁后的另外一番天地。阳光明媚，春暖花开。隔三五步就
有一片花丛，花儿在阳光的照射之下，正争香斗艳，引得蝴蝶、蜜蜂在丛
中飞舞，好不热闹。青草地上，稀疏的种着几棵桃树，零零散散，看起来
确实别有一番的情调。西面有一个水池，微风袭来，荡起道道细腻的波纹
，池水清澈见底，不时还有鱼儿穿梭其中。一切宁静、祥和，真可谓是人
间仙境。北面有间小茅屋，门户大开。
LONG
);
	set("exits",([
		"north": __DIR__"maowu",
		"south": __DIR__"outside01",
	]));
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_look","look");
}
int do_look(string arg)
{
	if(arg && arg != "") return 0;
	if(NATURE_D->is_night())
	this_object()->set("long", @LONG
这里是绝缘壁后的另外一番天地。天空月色皎洁，月光照射下，青草
地上挂着星点的露珠。青草地上，稀疏的种着几棵桃树，零零散散，看起
来确实别有一番的情调。西面有一个水池，月光倒映在水池当中，不时还
有鱼儿吐出若干的气冒，一切宁静、祥和，真可谓是人间仙境。北面有间
小茅屋，门户紧闭，一丝幽幽的灯光从窗户照射出来。
LONG
);
	else 
	set("long", @LONG
这里是绝缘壁后的另外一番天地。阳光明媚，春暖花开。隔三五步就
有一片花丛，花儿在阳光的照射之下，正争香斗艳，引得蝴蝶、蜜蜂在丛
中飞舞，好不热闹。青草地上，稀疏的种着几棵桃树，零零散散，看起来
确实别有一番的情调。西面有一个水池，微风袭来，荡起道道细腻的波纹
，池水清澈见底，不时还有鱼儿穿梭其中。一切宁静、祥和，真可谓是人
间仙境。北面有间小茅屋，门户大开。
LONG
);
	return 0;
}
int valid_leave(object me,string dir)
{
        if( dir == "north" && NATURE_D->is_night())
        	return notify_fail("夜深人静的，你想想，还是不打扰人家休息了！\n");
        return ::valid_leave(me, dir);
}