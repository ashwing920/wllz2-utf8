// /d/beijing2/xingbu/ws-2.c

inherit ROOM;
string look_window();
string look_rose();
int do_pick(string arg);
void create()
{
	set("short", "高小姐的卧室");
	set("long", @LONG
这里散发出淡淡的幽香，你说不清究竟是什么香味，大概是少女特有
的体香吧。还有这里布置得很精致，显示出主人是一个很有心思的人。窗
台（window)上放着一盆玫瑰。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang2",
	]));
	set("item_desc", ([
		"window": (: look_window :),
		"rose"  : (: look_rose   :),
	]) );
	set("flower",1);
	setup();
}

void init()
{
	add_action("do_pick", "pick");

}

string look_window()
{
      if (query("flower")) 
	 return "窗台上放着一盆蓝色的玫瑰，玫瑰花(rose)正在盛开，娇艳欲滴，你忍不住想把它摘(pick)下来。\n";
      else
	 return "窗台上放着一个花盆，可惜花已经让别人摘掉了。你不禁想：是谁那么煞风景呢？ \n";

}
string look_rose()
{
      if (query("flower")) 
	 return "这朵蓝色的玫瑰花正处于盛开时期，娇艳欲滴。\n";
      else
	 return "你要看什么？ \n";

}


int do_pick(string arg)
{
	   object me,obj;
	   string err;
	   me=this_player();
	   if(arg!="rose") return 0;
	   if( ! query("flower") )  return 0;
	   message_vision("$N摘下了一朵玫瑰花\n",me);
	   err=catch(obj=new(__DIR__"npc/obj/rose.c"));
	   obj->move(me);
	   delete("flower");
	   return 1;
}

