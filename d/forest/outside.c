// /d/kunming/pubu

inherit ROOM;

static int total = 500000;

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
		"north": __DIR__"outside01",
		"south": __DIR__"hole12",
	]));
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_look","look");
	add_action("do_break","break");
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
int do_break(string arg)
{
	object me,room;
	int neili;
	
	me = this_player();
	neili = (int)me->query("neili");

	if(!arg || arg == "") 
		return notify_fail("你要用内力震什么？\n");
	
	if( arg == "石壁"){
		if( neili <= 0)
			return notify_fail("你现在体内内力丝毫无存，似乎毫无任何效果。\n");
		if( query("breaked"))
			return notify_fail("你要用内力震什么？\n");
		if( total){
			message_vision("$N潜运内力，暴喝一声：嗨！将全身的内力运于掌中，向石壁推去。\n",me);
			if( total >= 0){
				message_vision("只听见“乓”的一声巨响，尘埃飞起，呛得$N差点透不过气来。\n",me);
				message_vision("石壁似乎有些松动了。\n",me);
			}
			else {
				message_vision("只听见“乓”的一声巨响，尘埃飞起，石壁被$N震开了一个大洞口。\n",me);
				set("exits/south",__DIR__"hole12");
				room = find_object(__DIR__"hole12");
				if(!room) load_object(__DIR__"hole12");
				room->set("exits/north",__DIR__"outside");
				room->set("breaked",1);
				CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("绝缘之壁被%s用内力震开了！",me->name()));
				set("breaked",1);
			}
			total -= neili;
			me->set("neili",0);
			return 1;
		}
	}
}
void reset()
{
	delete("exits/south");
	delete("breaked");
	total = 500000;
}
