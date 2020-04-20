
inherit ROOM;

void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长
竹篙，正在船尾吃力地撑着船。
LONG);
	set("exits",([
		"out"  :  __DIR__"xiaodao",
	]));
	setup();
}
void init()
{
       object me,room;
       me=this_player();
       room=this_object();
       message_vision("\n船夫把小舟靠在岸边，快下船吧。\n\n",me);
}
