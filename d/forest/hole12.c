// /d/kunming/pubu

inherit ROOM;

static int total = 500000;

void create()
{
	set("short","洞庭深处");
	set("long", @LONG
这里是千年古洞里的最深处，前方已经没有去路了。附着南面的石壁
，石壁的那端隐隐传来阵阵溪水流淌的声音，想必那已经是千年古洞之外
的另一片天地了。石壁上依稀的刻着四个大字，上面写着「绝缘之壁」。
LONG
);
	set("exits",([
		"south": __DIR__"hole10",
	]));
	setup();
}
void init()
{
	add_action("do_break","break");
}
int do_break(string arg)
{
	object me,room;
	int neili;

	me = this_player();
	neili = (int)me->query("neili");

	if(!arg || arg == "")
		return notify_fail("你要用内力震什么？\n");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

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
				if(NATURE_D->is_night())
					message_vision("南面出现了一个大洞，洞外一片皎洁的月光照射了进来。\n",me);
				else
					message_vision("南面出现了一个大洞，洞外一片阳光象利刃一般照射了进来。\n",me);
					set("exits/north",__DIR__"outside");
					room = find_object(__DIR__"outside");
					if(!room) room = load_object(__DIR__"outside");
					room->set("exits/south",__DIR__"hole12");
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
	delete("exits/north");
	delete("breaked");
	total = 500000;
}