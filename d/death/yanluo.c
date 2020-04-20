// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "阎罗殿");
	set("long", @LONG
经过一路走来的黑暗，乍进门来，牛油巨烛耀眼的光芒让你一阵炫晕
，定下神来，鎏金镶玉的王座上端坐着一位黑面君王，正是掌握六道轮回
，万物来世的阎罗王。两侧四名判官，各捧生死簿册，牛头，马面，各拿
武器，横眉怒目，当堂责罚人犯。世上一切蠃虫，羽虫，毛虫，鳞介无不
由此受判。
LONG
);
	set("objects", ([
		__DIR__"npc/yanwang":1,
		__DIR__"npc/panguan2" : 2,
		__DIR__"npc/niutou" : 1,
		__DIR__"npc/mamian" : 1,
		__DIR__"npc/ghost3" : 3,
	]) );
	set("death",1);
	setup();
}
void init()
{
	remove_call_out("letgo");
	call_out("letgo",15,this_player());
}

void letgo(object me)
{
	object room;
	if(!me || environment(me) != this_object()) return;
	message_vision("\n\n阎王爷长叹一口气：算了，算了，让$N四处逛逛，知道这里是赏罚分明，\n只要$N来世再也不敢胡作非为就可以了！\n\n",me);
	message_vision(HIW"\n\n一阵冷风吹散了$N的阴魂．．．\n\n"NOR,me);
	room = load_object(__DIR__"dizang");
	if(objectp(room))  me->move(room);
}
