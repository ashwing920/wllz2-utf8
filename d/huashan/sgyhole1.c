// Room: /d/huashan/sgyhole.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
山洞内有块光溜溜的大石，不知道曾有多少华山剑派的前辈在此思过
面壁，以致这块大石竟被坐得滑溜。石壁(wall)左侧刻着「风清扬」三个
大字，是以利器所刻，笔划苍劲，深有半寸。这三字刻得劲力非凡，想必
其人武功一定十分了得。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"out" : __DIR__"siguoya",
	]));
	set("item_desc", ([
		"wall" : "一面很厚的石壁。\n"
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_break", "break");
}
int do_break(string arg)
{
	object weapon,me=this_player();

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你一掌打在石壁，满手都是鲜血。\n");
	message_vision("$N走到石壁前，拔出腰间所悬长剑，运劲向石壁刺了过去！\n",me);
	if (me->query("neili") < 200){
	message_vision("结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n",me);
	me->set("neili",0);
	me->unconcious();
	return 1;
	}
	message_vision("$N只听一声轰响，石壁被捅穿了，原来里面有一个大洞。！\n",me);
		set("exits/enter",__DIR__"sgyhole");
		me->add("neili",-200);
		remove_call_out("close");
		call_out("close", 5, this_object());
	return 1;
	}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}
void close(object room)
{
	message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", room);
	room->delete("exits/enter");
}

