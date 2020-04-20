inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名老艄公手持长竹篙，正在
船尾吃力地撑着船。
LONG
);
	set("exits",([
	       "out"  :  __DIR__"anbian",
	]));
	setup();
}
void init()
{
       object me;
       me=this_player();
       message_vision("\n终于到了岸边，船夫把小舟靠在岸边，快下船吧。\n\n",me);
}
